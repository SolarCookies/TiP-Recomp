#include <rex/ppc/context.h>
#include <rex/ppc/function.h>
#include "tip_engine/Log.h"
#include "UsbCam.h"
#include "UsbCam.h"

// Use DirectShow (COM) directly so we can capture from DirectShow sources
// such as OBS Virtual Camera, which does not appear via Media Foundation.
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <dshow.h>

#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <cstring>
#include <format>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#pragma comment(lib, "strmiids.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")

// Forward-declare the xcam APC completion routine.
// On real Xbox 360, KeInsertQueueApc queues this to fire after camera DMA completes.
// In the PC recomp, KeInsertQueueApc is stubbed so we call it manually after writing data.
// It reads XOVERLAPPED+16; if non-null calls it(XOVERLAPPED+0, XOVERLAPPED+4).
PPC_EXTERN_IMPORT(sub_82ACFB40);

// ISampleGrabberCB / ISampleGrabber are from the deprecated qedit.h.
// Redefined here to avoid that header dependency.
struct __declspec(uuid("0579154A-2B53-4994-B0D0-E773148EFF85"))
ISampleGrabberCB : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE SampleCB(double, IMediaSample*) = 0;
    virtual HRESULT STDMETHODCALLTYPE BufferCB(double, BYTE*, long)   = 0;
};

struct __declspec(uuid("6B652FFF-11FE-4fce-92AD-0266B5D7C78F"))
ISampleGrabber : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE SetOneShot(BOOL)                      = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMediaType(const AM_MEDIA_TYPE*)    = 0;
    virtual HRESULT STDMETHODCALLTYPE GetConnectedMediaType(AM_MEDIA_TYPE*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetBufferSamples(BOOL)                = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCurrentBuffer(long*, long*)        = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCurrentSample(IMediaSample**)      = 0;
    virtual HRESULT STDMETHODCALLTYPE SetCallback(ISampleGrabberCB*, long)  = 0;
};

// CLSIDs for SampleGrabber / NullRenderer (from qedit.h, stable forever).
static const CLSID CLSID_SampleGrabber_L =
    {0xC1F400A0,0x3F08,0x11d3,{0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37}};
static const CLSID CLSID_NullRenderer_L =
    {0xC1F400A4,0x3F08,0x11d3,{0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37}};

// MEDIASUBTYPE_I420 is not in the Windows SDK headers.
static const GUID MEDIASUBTYPE_I420_L =
    {0x30323449,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};

namespace {

uint32_t g_camWidth  = 320;
uint32_t g_camHeight = 240;
constexpr uint32_t kFakeCamHandle = 0xCA50C001u;

// ── Frame callback ────────────────────────────────────────────────────────────
// Called on a DirectShow worker thread; just stores the raw bytes.
class FrameGrabberCB : public ISampleGrabberCB {
public:
    std::mutex           mtx;
    std::vector<uint8_t> data;     // consumer-ready buffer, guarded by mtx
    std::vector<uint8_t> staging;  // producer-side buffer, only touched by BufferCB thread
    bool                 hasFrame = false;
    uint64_t             frameSeq = 0;  // incremented on every BufferCB

    ULONG   STDMETHODCALLTYPE AddRef()  override { return 2; }
    ULONG   STDMETHODCALLTYPE Release() override { return 1; }
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
        if (riid == IID_IUnknown || riid == __uuidof(ISampleGrabberCB))
            { *ppv = this; return S_OK; }
        *ppv = nullptr; return E_NOINTERFACE;
    }
    HRESULT STDMETHODCALLTYPE SampleCB(double, IMediaSample*) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE BufferCB(double ts, BYTE* buf, long len) override {
        // ── Copy to staging OUTSIDE the lock ─────────────────────────────────
        // This keeps the lock hold time O(1) (just a pointer swap) instead of
        // O(3 MB), which previously starved this thread and caused it to stop
        // delivering samples after the very first frame.
        staging.assign(buf, buf + len);
        {
            std::lock_guard<std::mutex> lk(mtx);
            data.swap(staging);  // O(1) — consumers hold the lock for 3 MB copies
            if (!hasFrame)
                Log(LogLevel::Error, std::format("XUsbcam: BufferCB first frame ts={:.3f} len={}", ts, len));
            hasFrame = true;
            ++frameSeq;
            if ((frameSeq % 60) == 0)
                Log(LogLevel::Error, std::format("XUsbcam: BufferCB frame #{}", frameSeq));
        }
        return S_OK;
    }
};

// ── DirectShow camera state ───────────────────────────────────────────────────
struct {
    IGraphBuilder*         graph    = nullptr;
    ICaptureGraphBuilder2* capBuild = nullptr;
    IMediaControl*         control  = nullptr;
    ISampleGrabber*        grabber  = nullptr;
    IBaseFilter*           camFilt  = nullptr;
    IBaseFilter*           grabFilt = nullptr;
    IBaseFilter*           nullFilt = nullptr;
    FrameGrabberCB         cb;
    std::atomic<bool>      open{false};
    GUID                   subtype  = GUID_NULL;  // negotiated pixel format
    int                    dsWidth  = 0;
    int                    dsHeight = 0;
} g_ds;

std::mutex g_camMutex;  // guards open/close of the graph

// ── Background DS thread ──────────────────────────────────────────────────────
// The entire DirectShow graph lives on a dedicated thread with its own MTA COM
// apartment.  This prevents COM apartment teardown issues that can stall sample
// delivery on PPC game threads.
std::thread             g_dsThread;
std::atomic<bool>       g_dsStop{false};
std::mutex              g_dsReadyMx;
std::condition_variable g_dsReadyCv;
bool                    g_dsReady = false;

// ── Helpers ───────────────────────────────────────────────────────────────────
static std::string WideToUTF8(const wchar_t* w) {
    if (!w) return {};
    int n = WideCharToMultiByte(CP_UTF8, 0, w, -1, nullptr, 0, nullptr, nullptr);
    std::string s(n - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, w, -1, s.data(), n, nullptr, nullptr);
    return s;
}

template<typename T>
static void SafeRelease(T*& p) { if (p) { p->Release(); p = nullptr; } }

void CloseDSCamera_Locked() {
    Log(LogLevel::Error, std::format("XUsbcam: CloseDSCamera_Locked wasOpen={}", g_ds.open.load()));
    g_ds.open = false;
    if (g_ds.control) g_ds.control->Stop();
    SafeRelease(g_ds.grabber);
    SafeRelease(g_ds.control);
    SafeRelease(g_ds.capBuild);
    SafeRelease(g_ds.nullFilt);
    SafeRelease(g_ds.grabFilt);
    SafeRelease(g_ds.camFilt);
    SafeRelease(g_ds.graph);
}

// Forward-declared; body is below OpenDSCamera.
static void DSBuildAndRun_Locked();

static void DSThreadProc() {
    // Use STA so OBS Virtual Camera's COM objects (which are STA-compatible)
    // can be created and called without cross-apartment marshaling.
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    // Build and start the DirectShow graph on THIS thread.
    {
        std::lock_guard<std::mutex> lk(g_camMutex);
        DSBuildAndRun_Locked();
    }

    // Signal the caller that the graph is ready (or failed).
    {
        std::lock_guard<std::mutex> lk(g_dsReadyMx);
        g_dsReady = true;
    }
    g_dsReadyCv.notify_all();

    // Poll GetCurrentBuffer at ~60 fps.  This is purely pull-based: the
    // SampleGrabber stores the latest delivered sample internally
    // (SetBufferSamples(TRUE)) and we retrieve it without any COM callback.
    // This completely sidesteps STA/MTA cross-apartment marshaling issues
    // that cause SampleCB / BufferCB to stall after the first delivery.
    while (!g_dsStop.load()) {
        if (g_ds.open && g_ds.grabber) {
            // Query the current buffered sample size first.
            long bufSize = 0;
            HRESULT hr = g_ds.grabber->GetCurrentBuffer(&bufSize, nullptr);
            if (SUCCEEDED(hr) && bufSize > 0) {
                g_ds.cb.staging.resize(static_cast<size_t>(bufSize));
                hr = g_ds.grabber->GetCurrentBuffer(
                    &bufSize,
                    reinterpret_cast<long*>(g_ds.cb.staging.data()));
                if (SUCCEEDED(hr)) {
                    std::lock_guard<std::mutex> lk(g_ds.cb.mtx);
                    g_ds.cb.data.swap(g_ds.cb.staging);
                    if (!g_ds.cb.hasFrame)
                        Log(LogLevel::Error, std::format("XUsbcam: first polled frame size={}", bufSize));
                    g_ds.cb.hasFrame = true;
                    ++g_ds.cb.frameSeq;
                    if ((g_ds.cb.frameSeq % 60) == 0)
                        Log(LogLevel::Error, std::format("XUsbcam: poll frame #{}", g_ds.cb.frameSeq));
                }
            }
        }

        // Pump the STA message queue so COM infrastructure stays responsive.
        MSG msg;
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        Sleep(16);
    }

    // Tear down COM on this same thread.
    {
        std::lock_guard<std::mutex> lk(g_camMutex);
        CloseDSCamera_Locked();
    }
    CoUninitialize();
}

void OpenDSCamera() {
    Log(LogLevel::Error, std::format("XUsbcam: OpenDSCamera {}x{}", g_camWidth, g_camHeight));

    // Stop any existing background thread cleanly.
    if (g_dsThread.joinable()) {
        g_dsStop = true;
        g_dsThread.join();
        g_dsStop = false;
    }

    {
        std::lock_guard<std::mutex> lk(g_dsReadyMx);
        g_dsReady = false;
    }

    g_dsThread = std::thread(DSThreadProc);

    // Wait up to 15 s for the graph to be built.
    {
        std::unique_lock<std::mutex> lk(g_dsReadyMx);
        if (!g_dsReadyCv.wait_for(lk, std::chrono::seconds(15), [] { return g_dsReady; }))
            Log(LogLevel::Error, "XUsbcam: OpenDSCamera timed out waiting for graph");
    }
}

// ── Actual graph construction (runs on DSThreadProc under g_camMutex) ─────────
static void DSBuildAndRun_Locked() {
    CloseDSCamera_Locked();  // clean up any leftover COM pointers

    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_MULTITHREADED);  // already init'd on this thread; S_FALSE is OK
    Log(LogLevel::Error, std::format("XUsbcam: CoInitializeEx hr={:08X}", (uint32_t)hrCo));

    // Enumerate DirectShow video-capture devices.
    ICreateDevEnum* devEnum = nullptr;
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, nullptr, CLSCTX_INPROC_SERVER,
                                   IID_ICreateDevEnum, reinterpret_cast<void**>(&devEnum));
    if (FAILED(hr)) {
        Log(LogLevel::Error, std::format("XUsbcam: SystemDeviceEnum hr={:08X}", (uint32_t)hr));
        return;
    }

    IEnumMoniker* enumMon = nullptr;
    hr = devEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &enumMon, 0);
    devEnum->Release();
    Log(LogLevel::Error, std::format("XUsbcam: CreateClassEnumerator hr={:08X} enumMon={}", (uint32_t)hr, enumMon != nullptr));
    if (FAILED(hr) || !enumMon) {
        Log(LogLevel::Error, "XUsbcam: no DirectShow video capture devices found");
        return;
    }

    // Log every device; prefer OBS Virtual Camera, fall back to index 0.
    IMoniker* chosen  = nullptr;
    IMoniker* first   = nullptr;
    IMoniker* moniker = nullptr;
    int idx = 0;
    while (enumMon->Next(1, &moniker, nullptr) == S_OK) {
        IPropertyBag* bag  = nullptr;
        std::string   name = "<unknown>";
        if (SUCCEEDED(moniker->BindToStorage(nullptr, nullptr, IID_IPropertyBag,
                                              reinterpret_cast<void**>(&bag)))) {
            VARIANT var; VariantInit(&var);
            if (SUCCEEDED(bag->Read(L"FriendlyName", &var, nullptr)) && var.vt == VT_BSTR)
                name = WideToUTF8(var.bstrVal);
            VariantClear(&var);
            bag->Release();
        }
        Log(LogLevel::Error, std::format("XUsbcam: DS device[{}] = '{}'", idx, name));
        if (!first)  { first = moniker; moniker->AddRef(); }
        if (!chosen && name.find("OBS Virtual Camera") != std::string::npos)
            { chosen = moniker; moniker->AddRef(); }
        moniker->Release();
        ++idx;
    }
    enumMon->Release();

    Log(LogLevel::Error, std::format("XUsbcam: enumerated {} device(s)", idx));
    if (!chosen) {
        if (first) {
            Log(LogLevel::Error, "XUsbcam: OBS Virtual Camera not found; using first device");
            chosen = first; first = nullptr;
        } else {
            Log(LogLevel::Error, "XUsbcam: no devices found");
            return;
        }
    }
    SafeRelease(first);

    // ── Build filter graph ────────────────────────────────────────────────────
    Log(LogLevel::Error, "XUsbcam: creating FilterGraph");
    hr = CoCreateInstance(CLSID_FilterGraph, nullptr, CLSCTX_INPROC_SERVER,
                          IID_IGraphBuilder, reinterpret_cast<void**>(&g_ds.graph));
    Log(LogLevel::Error, std::format("XUsbcam: FilterGraph hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        chosen->Release(); return;
    }

    hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, nullptr, CLSCTX_INPROC_SERVER,
                          IID_ICaptureGraphBuilder2, reinterpret_cast<void**>(&g_ds.capBuild));
    Log(LogLevel::Error, std::format("XUsbcam: CaptureGraphBuilder2 hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        chosen->Release(); CloseDSCamera_Locked(); return;
    }
    g_ds.capBuild->SetFiltergraph(g_ds.graph);
    Log(LogLevel::Error, "XUsbcam: SetFiltergraph done");

    Log(LogLevel::Error, "XUsbcam: binding chosen device to IBaseFilter");
    hr = chosen->BindToObject(nullptr, nullptr, IID_IBaseFilter,
                               reinterpret_cast<void**>(&g_ds.camFilt));
    chosen->Release();
    Log(LogLevel::Error, std::format("XUsbcam: camera BindToObject hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        CloseDSCamera_Locked(); return;
    }
    g_ds.graph->AddFilter(g_ds.camFilt, L"Camera");
    Log(LogLevel::Error, "XUsbcam: camera filter added to graph");

    hr = CoCreateInstance(CLSID_SampleGrabber_L, nullptr, CLSCTX_INPROC_SERVER,
                          IID_IBaseFilter, reinterpret_cast<void**>(&g_ds.grabFilt));
    Log(LogLevel::Error, std::format("XUsbcam: SampleGrabber hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        CloseDSCamera_Locked(); return;
    }
    g_ds.graph->AddFilter(g_ds.grabFilt, L"Grabber");
    Log(LogLevel::Error, "XUsbcam: grabber filter added to graph");

    if (FAILED(g_ds.grabFilt->QueryInterface(__uuidof(ISampleGrabber),
                                              reinterpret_cast<void**>(&g_ds.grabber)))) {
        Log(LogLevel::Error, "XUsbcam: ISampleGrabber QI failed");
        CloseDSCamera_Locked(); return;
    }
    Log(LogLevel::Error, "XUsbcam: ISampleGrabber QI OK");

    // Accept any video format — OBS Virtual Camera outputs NV12, not YUY2.
    AM_MEDIA_TYPE mt{};
    mt.majortype = MEDIATYPE_Video;
    g_ds.grabber->SetMediaType(&mt);
    g_ds.grabber->SetOneShot(FALSE);
    g_ds.grabber->SetBufferSamples(TRUE);   // keep a copy of each sample for polling
    // No callback — we poll GetCurrentBuffer from the background thread loop.
    Log(LogLevel::Error, "XUsbcam: grabber configured (any video format, polling mode)");

    hr = CoCreateInstance(CLSID_NullRenderer_L, nullptr, CLSCTX_INPROC_SERVER,
                          IID_IBaseFilter, reinterpret_cast<void**>(&g_ds.nullFilt));
    Log(LogLevel::Error, std::format("XUsbcam: NullRenderer hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        CloseDSCamera_Locked(); return;
    }
    g_ds.graph->AddFilter(g_ds.nullFilt, L"Null");
    Log(LogLevel::Error, "XUsbcam: null renderer added to graph");

    Log(LogLevel::Error, "XUsbcam: calling RenderStream");
    hr = g_ds.capBuild->RenderStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video,
                                      g_ds.camFilt, g_ds.grabFilt, g_ds.nullFilt);
    Log(LogLevel::Error, std::format("XUsbcam: RenderStream hr={:08X}", (uint32_t)hr));
    if (FAILED(hr)) {
        CloseDSCamera_Locked(); return;
    }

    // Remove the reference clock so the NullRenderer renders frames immediately
    // without waiting for clock-based scheduling.  Without this, Run() returns
    // S_FALSE (graph transitioning) and never reaches State_Running, so the
    // source filter only delivers one preroll sample and then stalls.
    {
        IMediaFilter* mf = nullptr;
        if (SUCCEEDED(g_ds.graph->QueryInterface(IID_IMediaFilter, reinterpret_cast<void**>(&mf)))) {
            mf->SetSyncSource(nullptr);
            mf->Release();
            Log(LogLevel::Error, "XUsbcam: reference clock removed");
        }
    }

    HRESULT hrQI = g_ds.graph->QueryInterface(IID_IMediaControl, reinterpret_cast<void**>(&g_ds.control));
    Log(LogLevel::Error, std::format("XUsbcam: IMediaControl QI hr={:08X}", (uint32_t)hrQI));
    if (g_ds.control) {
        HRESULT hrRun = g_ds.control->Run();
        Log(LogLevel::Error, std::format("XUsbcam: IMediaControl::Run hr={:08X}", (uint32_t)hrRun));

        // Wait up to 5 s for the graph to reach State_Running.
        OAFilterState fs = State_Stopped;
        HRESULT hrSt = g_ds.control->GetState(5000, &fs);
        Log(LogLevel::Error, std::format("XUsbcam: graph state hr={:08X} state={} (2=Running)", (uint32_t)hrSt, (int)fs));
    }

    // Query the negotiated format so ReadFrame knows how to convert.
    AM_MEDIA_TYPE cmt{};
    HRESULT hrFmt = g_ds.grabber->GetConnectedMediaType(&cmt);
    Log(LogLevel::Error, std::format("XUsbcam: GetConnectedMediaType hr={:08X}", (uint32_t)hrFmt));
    if (SUCCEEDED(hrFmt)) {
        g_ds.subtype = cmt.subtype;
        if (cmt.formattype == FORMAT_VideoInfo && cmt.cbFormat >= sizeof(VIDEOINFOHEADER)) {
            auto* vih = reinterpret_cast<VIDEOINFOHEADER*>(cmt.pbFormat);
            g_ds.dsWidth  = std::abs(vih->bmiHeader.biWidth);
            g_ds.dsHeight = std::abs(vih->bmiHeader.biHeight);
            Log(LogLevel::Error, std::format("XUsbcam: VideoInfoHeader avg_frame_time={} bit_rate={}",
                vih->AvgTimePerFrame, vih->dwBitRate));
        } else {
            Log(LogLevel::Error, std::format("XUsbcam: non-VideoInfo format formattype={:08X} cbFormat={}",
                cmt.formattype.Data1, cmt.cbFormat));
        }
        if (cmt.cbFormat && cmt.pbFormat) CoTaskMemFree(cmt.pbFormat);
        if (cmt.pUnk) cmt.pUnk->Release();
        Log(LogLevel::Error, std::format("XUsbcam: connected format {:08X}-{:04X}, ds={}x{}",
            cmt.subtype.Data1, cmt.subtype.Data2, g_ds.dsWidth, g_ds.dsHeight));
    } else {
        Log(LogLevel::Error, "XUsbcam: GetConnectedMediaType failed; format unknown");
    }

    g_ds.open = true;
    Log(LogLevel::Error, std::format("XUsbcam: DirectShow graph running {}x{}", g_camWidth, g_camHeight));
}

}  // namespace

// ── PPC stubs ─────────────────────────────────────────────────────────────────

extern "C" PPC_FUNC(__imp__XUsbcamCreate) {
    (void)base;
    const uint32_t bufferSize = ctx.r4.u32;
    Log(LogLevel::Error, std::format("XUsbcamCreate: bufferSize={:#x} r5={:#x}", bufferSize, ctx.r5.u32));
    g_camWidth  = (bufferSize == 0x4B000u) ? 640u : 320u;
    g_camHeight = (bufferSize == 0x4B000u) ? 480u : 240u;

    OpenDSCamera();

    if (ctx.r5.u32)
        PPC_STORE_U32(ctx.r5.u32, kFakeCamHandle);

    ctx.r3.u64 = 0;
    Log(LogLevel::Error, std::format("XUsbcamCreate: {}x{} open={}", g_camWidth, g_camHeight, g_ds.open.load()));
}

extern "C" PPC_FUNC(__imp__XUsbcamDestroy) {
    (void)base;
    // Signal the background DS thread to stop and wait for it to tear down COM.
    if (g_dsThread.joinable()) {
        g_dsStop = true;
        g_dsThread.join();
        g_dsStop = false;
    }
    ctx.r3.u64 = 0;
    Log(LogLevel::Error, "XUsbcamDestroy called");
}

extern "C" PPC_FUNC(__imp__XUsbcamGetState) {
    (void)base;
    // 0 = not connected, 1 = connected (camera present but not yet streaming),
    // 2 = streaming. Always return at least 1 so the game shows the camera UI
    // and proceeds to call XUsbcamCreate / XUsbcamReadFrame.
    const uint32_t state = g_ds.open ? 2u : 1u;
    Log(LogLevel::Trace, std::format("XUsbcamGetState -> {}", state));
    ctx.r3.u64 = state;
}

extern "C" PPC_FUNC(__imp__XUsbcamSetConfig) {
    (void)base;
    Log(LogLevel::Error, std::format("XUsbcamSetConfig: r4={:#x} r5={:#x} r6={:#x}",
        ctx.r4.u32, ctx.r5.u32, ctx.r6.u32));
    ctx.r3.u64 = 0;
}

extern "C" PPC_FUNC(__imp__XUsbcamSetView) {
    (void)base;
    Log(LogLevel::Error, std::format("XUsbcamSetView: r4={:#x} r5={:#x} r6={:#x} r7={:#x}",
        ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32));
    ctx.r3.u64 = 0;
}

extern "C" PPC_FUNC(__imp__XUsbcamSetCaptureMode) {
    (void)base;
    const uint32_t w = ctx.r6.u32;
    const uint32_t h = ctx.r7.u32;
    Log(LogLevel::Error, std::format("XUsbcamSetCaptureMode: {}x{} open={}", w, h, g_ds.open.load()));
    if (w && h && w <= 1280 && h <= 960) {
        g_camWidth  = w;
        g_camHeight = h;
        // Never restart the DirectShow graph here — g_camWidth/g_camHeight only
        // control the scaling in XUsbcamReadFrame. Tearing down and rebuilding
        // the graph every time SetCaptureMode is called keeps the camera stuck
        // on frame 1. Only open if not already running.
        if (!g_ds.open) {
            OpenDSCamera();
        }
    }
    ctx.r3.u64 = 0;
}

extern "C" PPC_FUNC(__imp__XUsbcamReadFrame) {
    const uint32_t pBits     = ctx.r4.u32;
    const uint32_t pitch     = ctx.r5.u32;
    const uint32_t w         = g_camWidth;
    const uint32_t h         = g_camHeight;
    const uint32_t rowStride = pitch ? pitch : (w * 2);

    static bool s_readFrameLogged = false;
    if (!s_readFrameLogged) {
        s_readFrameLogged = true;
        Log(LogLevel::Error, std::format("XUsbcamReadFrame: first call pBits={:#x} pitch={} {}x{} open={}",
            pBits, pitch, w, h, g_ds.open.load()));
    }

    if (!pBits) {
        Log(LogLevel::Error, "XUsbcamReadFrame: pBits=0, ignoring");
        ctx.r3.u64 = 0;
        return;
    }

    if (!g_ds.open) {
        static uint32_t s_noOpenCount = 0;
        if ((++s_noOpenCount % 60) == 1)
            Log(LogLevel::Error, std::format("XUsbcamReadFrame: camera not open (call #{})", s_noOpenCount));
        ctx.r3.u64 = 997u;
        return;
    }

    if (g_ds.open) {
        // Copy frame data under lock (fast), then release lock before converting.
        std::vector<uint8_t> localData;
        GUID localFmt = GUID_NULL;
        uint32_t sw = 0, sh = 0;
        {
            std::lock_guard<std::mutex> flk(g_ds.cb.mtx);

            // Log once when first real frame arrives; then every 300 frames.
            static bool     s_firstFrameLogged = false;
            static uint32_t s_frameCount       = 0;
            if (g_ds.cb.hasFrame) ++s_frameCount;
            if (!g_ds.cb.hasFrame) {
                static uint32_t s_waitCount = 0;
                if ((++s_waitCount % 60) == 1)
                    Log(LogLevel::Error, std::format("XUsbcamReadFrame: waiting for first DS frame (wait #{})", s_waitCount));
            }
            if (g_ds.cb.hasFrame && !s_firstFrameLogged) {
                s_firstFrameLogged = true;
                const uint8_t* d = g_ds.cb.data.data();
                const uint32_t sw0 = g_ds.dsWidth  ? (uint32_t)g_ds.dsWidth  : w;
                const uint32_t sh0 = g_ds.dsHeight ? (uint32_t)g_ds.dsHeight : h;
                const uint8_t cY = (g_ds.cb.data.size() >= sw0 * sh0)
                                    ? d[(sh0/2) * sw0 + sw0/2] : 0;
                Log(LogLevel::Error, std::format(
                    "XUsbcamReadFrame: first DS frame size={} fmt={:08X} ds={}x{} centre_Y={}",
                    g_ds.cb.data.size(), g_ds.subtype.Data1, sw0, sh0, (uint32_t)cY));
            }

            if (!g_ds.cb.hasFrame || g_ds.cb.data.empty()) {
                ctx.r3.u64 = 997u;
                return;
            }

            // Quick copy — releases lock immediately after.
            localData = g_ds.cb.data;
            localFmt  = g_ds.subtype;
            sw = g_ds.dsWidth  ? static_cast<uint32_t>(g_ds.dsWidth)  : w;
            sh = g_ds.dsHeight ? static_cast<uint32_t>(g_ds.dsHeight) : h;
        }  // lock released here — BufferCB can now write new frames freely

        const uint8_t* src = localData.data();
        bool handled = true;

        if (localFmt == MEDIASUBTYPE_YUY2 || localFmt == MEDIASUBTYPE_YUYV) {
                // Source is YUY2 (Y0, Cb, Y1, Cr); Xbox texture is k_Cr_Y1_Cb_Y0_REP = UYVY (Cb, Y0, Cr, Y1).
                // Swap bytes: [Y0,Cb,Y1,Cr] -> [Cb,Y0,Cr,Y1].
                const uint32_t srcRowBytes = sw * 2;
                for (uint32_t dy = 0; dy < h; ++dy) {
                    const uint32_t sy = dy * sh / h;
                    const uint8_t* srcRow = src + sy * srcRowBytes;
                    uint8_t*       dstRow = base + pBits + dy * rowStride;
                    for (uint32_t dx = 0; dx + 1 < w; dx += 2) {
                        const uint32_t sx = (dx * sw / w) & ~1u;  // keep even
                        // YUY2 macropixel: [Y0=sx*2+0, Cb=sx*2+1, Y1=sx*2+2, Cr=sx*2+3]
                        // UYVY macropixel: [Cb, Y0, Cr, Y1]
                        dstRow[dx*2+0] = srcRow[sx*2+1];  // Cb
                        dstRow[dx*2+1] = srcRow[sx*2+0];  // Y0
                        dstRow[dx*2+2] = srcRow[sx*2+3];  // Cr
                        dstRow[dx*2+3] = srcRow[sx*2+2];  // Y1
                    }
                }

            } else if (localFmt == MEDIASUBTYPE_NV12) {
                // NV12: Y plane (sw*sh), then interleaved UV plane (sw*sh/2).
                // Output UYVY (Cb, Y0, Cr, Y1) to match k_Cr_Y1_Cb_Y0_REP.
                const uint8_t* Y  = src;
                const uint8_t* UV = src + sw * sh;
                for (uint32_t dy = 0; dy < h; ++dy) {
                    const uint32_t sy    = dy * sh / h;
                    uint8_t*       dst   = base + pBits + dy * rowStride;
                    const uint8_t* uvRow = UV + (sy / 2) * sw;
                    for (uint32_t dx = 0; dx + 1 < w; dx += 2) {
                        const uint32_t sx = (dx * sw / w) & ~1u;
                        dst[dx*2+0] = uvRow[sx];      // Cb
                        dst[dx*2+1] = Y[sy*sw + sx];  // Y0
                        dst[dx*2+2] = uvRow[sx + 1];  // Cr
                        dst[dx*2+3] = Y[sy*sw + sx + 1]; // Y1
                    }
                }

            } else if (localFmt == MEDIASUBTYPE_I420_L || localFmt == MEDIASUBTYPE_IYUV) {
                // I420/IYUV: Y plane, then U plane, then V plane (each chroma sw/2 * sh/2).
                // Output UYVY (Cb, Y0, Cr, Y1) to match k_Cr_Y1_Cb_Y0_REP.
                const uint32_t uvStride = sw / 2;
                const uint8_t* Y = src;
                const uint8_t* U = src + sw * sh;
                const uint8_t* V = U + uvStride * (sh / 2);
                for (uint32_t dy = 0; dy < h; ++dy) {
                    const uint32_t sy  = dy * sh / h;
                    uint8_t*       dst = base + pBits + dy * rowStride;
                    for (uint32_t dx = 0; dx + 1 < w; dx += 2) {
                        const uint32_t sx = (dx * sw / w) & ~1u;
                        dst[dx*2+0] = U[(sy/2)*uvStride + sx/2];  // Cb
                        dst[dx*2+1] = Y[sy*sw + sx];              // Y0
                        dst[dx*2+2] = V[(sy/2)*uvStride + sx/2];  // Cr
                        dst[dx*2+3] = Y[sy*sw + sx + 1];          // Y1
                    }
                }

            } else if (localFmt == MEDIASUBTYPE_YV12) {
                // YV12: same as I420 but U and V swapped.
                // Output UYVY (Cb, Y0, Cr, Y1) to match k_Cr_Y1_Cb_Y0_REP.
                const uint32_t uvStride = sw / 2;
                const uint8_t* Y = src;
                const uint8_t* V = src + sw * sh;
                const uint8_t* U = V + uvStride * (sh / 2);
                for (uint32_t dy = 0; dy < h; ++dy) {
                    const uint32_t sy  = dy * sh / h;
                    uint8_t*       dst = base + pBits + dy * rowStride;
                    for (uint32_t dx = 0; dx + 1 < w; dx += 2) {
                        const uint32_t sx = (dx * sw / w) & ~1u;
                        dst[dx*2+0] = U[(sy/2)*uvStride + sx/2];  // Cb
                        dst[dx*2+1] = Y[sy*sw + sx];              // Y0
                        dst[dx*2+2] = V[(sy/2)*uvStride + sx/2];  // Cr
                        dst[dx*2+3] = Y[sy*sw + sx + 1];          // Y1
                    }
                }

            } else {
                // Unknown format — log once, fall through to gradient.
                static bool s_warned = false;
                if (!s_warned) {
                    s_warned = true;
                    Log(LogLevel::Error, std::format(
                        "XUsbcam: unsupported format {:08X}, using gradient fallback",
                        localFmt.Data1));
                }
                handled = false;
            }

        if (handled) {
            static uint32_t s_frmLog = 0;
            if ((++s_frmLog % 300) == 0)
                Log(LogLevel::Error, std::format("XUsbcamReadFrame: frame #{} fmt={:08X} ds={}x{} -> {}x{}",
                    s_frmLog, localFmt.Data1, sw, sh, w, h));

            // Fire the XOVERLAPPED completion callback if the game registered one.
            // On real Xbox 360, this fires via an APC (sub_82ACFB40) queued by
            // KeInsertQueueApc after DMA completes.  In the PC recomp, KeInsertQueueApc
            // is stubbed and never fires, so we call sub_82ACFB40 manually here.
            // sub_82ACFDD0 (called before us) stores pOverlapped at slot+8.
            // sub_82ACFB40 reads XOVERLAPPED+16; if non-null it calls it(status, XOVERLAPPED+4).
            const uint32_t slotPtr = ctx.r7.u32;
            if (slotPtr != 0) {
                const uint32_t pOverlapped = PPC_LOAD_U32(slotPtr + 8);
                if (pOverlapped != 0) {
                    // sub_82ACF690 sets XOVERLAPPED+0=0 after we return, but the callback
                    // reads it directly, so set it now so the callback sees status=success.
                    PPC_STORE_U32(pOverlapped + 0, 0u);
                    // Save volatile regs modified by sub_82ACFB40 / its callee.
                    const uint64_t savedLR = ctx.lr;
                    const uint64_t savedR4 = ctx.r4.u64;
                    ctx.r3.u64 = pOverlapped;
                    sub_82ACFB40(ctx, base);  // fires XOVERLAPPED+16 callback if registered
                    ctx.lr     = savedLR;
                    ctx.r4.u64 = savedR4;
                }
            }

            ctx.r3.u64 = 0;
            return;
        }
    }

    // No real frame yet (camera warming up, unsupported format, or camera closed).
    // Return 997 so the game knows to retry next tick rather than running detection
    // on stale/gradient data.
    {
        static bool s_997Logged = false;
        if (!s_997Logged) {
            s_997Logged = true;
            Log(LogLevel::Error, std::format("XUsbcamReadFrame: returning 997 (no usable frame) open={}", g_ds.open.load()));
        }
    }
    ctx.r3.u64 = 997u;
}

// ── Public API ────────────────────────────────────────────────────────────────

bool UsbCam_GetFrameRGBA(std::vector<uint8_t>& out,
                          uint32_t& outW,
                          uint32_t& outH,
                          uint32_t& outFmtCC,
                          uint64_t& outFrameSeq) {
    if (!g_ds.open) return false;

    // Cache the last converted RGBA so we don't re-run the 1920×1080 conversion
    // at 60 fps when the source frame hasn't changed.  Only the cheap 3 MB copy
    // + O(1) seq check happens under the lock on every call.
    static uint64_t        s_convSeq  = UINT64_MAX;
    static uint32_t        s_cachedW  = 0;
    static uint32_t        s_cachedH  = 0;
    static uint32_t        s_cachedCC = 0;

    std::vector<uint8_t> raw;
    GUID     fmt = GUID_NULL;
    uint32_t sw = 0, sh = 0;
    uint64_t seq = 0;
    {
        std::lock_guard<std::mutex> lk(g_ds.cb.mtx);
        if (!g_ds.cb.hasFrame || g_ds.cb.data.empty()) return false;
        seq = g_ds.cb.frameSeq;
        fmt = g_ds.subtype;
        sw  = g_ds.dsWidth  ? static_cast<uint32_t>(g_ds.dsWidth)  : g_camWidth;
        sh  = g_ds.dsHeight ? static_cast<uint32_t>(g_ds.dsHeight) : g_camHeight;
        if (seq != s_convSeq)
            raw = g_ds.cb.data;  // only copy raw bytes when a new frame arrived
    }

    outFrameSeq = seq;
    outW  = s_cachedW  = sw;
    outH  = s_cachedH  = sh;
    outFmtCC = s_cachedCC = fmt.Data1;

    if (raw.empty()) {
        // Frame unchanged — overlay checks camSeq != lastSeq_ before using rgba,
        // so leaving 'out' as-is (possibly empty) is safe here.
        return true;
    }

    outW     = sw;
    outH     = sh;
    outFmtCC = fmt.Data1;
    out.resize(sw * sh * 4);

    const uint8_t* src = raw.data();

    // BT.601 studio-swing YCbCr → RGBA8
    auto clamp8 = [](int v) -> uint8_t {
        return v < 0 ? 0u : v > 255 ? 255u : static_cast<uint8_t>(v);
    };
    auto yuv2rgba = [&](uint8_t Yv, uint8_t Cb, uint8_t Cr, uint8_t* d) {
        const int y  = (static_cast<int>(Yv)  - 16) * 298;
        const int cb = static_cast<int>(Cb) - 128;
        const int cr = static_cast<int>(Cr) - 128;
        d[0] = clamp8((y + 409 * cr            + 128) >> 8);
        d[1] = clamp8((y - 100 * cb - 208 * cr + 128) >> 8);
        d[2] = clamp8((y + 516 * cb            + 128) >> 8);
        d[3] = 255;
    };

    if (fmt == MEDIASUBTYPE_NV12) {
        if (raw.size() < static_cast<size_t>(sw * sh * 3 / 2)) return false;
        const uint8_t* Y  = src;
        const uint8_t* UV = src + sw * sh;
        for (uint32_t y = 0; y < sh; ++y) {
            const uint8_t* uvRow  = UV + (y / 2) * sw;
            uint8_t*       dstRow = out.data() + y * sw * 4;
            for (uint32_t x = 0; x + 1 < sw; x += 2) {
                const uint8_t cb = uvRow[x], cr = uvRow[x + 1];
                yuv2rgba(Y[y * sw + x],     cb, cr, dstRow + x * 4);
                yuv2rgba(Y[y * sw + x + 1], cb, cr, dstRow + (x + 1) * 4);
            }
        }
    } else if (fmt == MEDIASUBTYPE_YUY2 || fmt == MEDIASUBTYPE_YUYV) {
        if (raw.size() < static_cast<size_t>(sw * sh * 2)) return false;
        for (uint32_t y = 0; y < sh; ++y) {
            const uint8_t* row    = src + y * sw * 2;
            uint8_t*       dstRow = out.data() + y * sw * 4;
            for (uint32_t x = 0; x + 1 < sw; x += 2) {
                // YUY2 macropixel: Y0 Cb Y1 Cr
                yuv2rgba(row[x*2+0], row[x*2+1], row[x*2+3], dstRow + x * 4);
                yuv2rgba(row[x*2+2], row[x*2+1], row[x*2+3], dstRow + (x+1) * 4);
            }
        }
    } else if (fmt == MEDIASUBTYPE_I420_L || fmt == MEDIASUBTYPE_IYUV) {
        if (raw.size() < static_cast<size_t>(sw * sh * 3 / 2)) return false;
        const uint32_t uvS = sw / 2;
        const uint8_t* Y   = src;
        const uint8_t* U   = src + sw * sh;
        const uint8_t* V   = U + uvS * (sh / 2);
        for (uint32_t y = 0; y < sh; ++y) {
            uint8_t* dstRow = out.data() + y * sw * 4;
            for (uint32_t x = 0; x + 1 < sw; x += 2) {
                const uint8_t cb = U[(y/2)*uvS + x/2], cr = V[(y/2)*uvS + x/2];
                yuv2rgba(Y[y*sw + x],     cb, cr, dstRow + x * 4);
                yuv2rgba(Y[y*sw + x + 1], cb, cr, dstRow + (x+1) * 4);
            }
        }
    } else if (fmt == MEDIASUBTYPE_YV12) {
        if (raw.size() < static_cast<size_t>(sw * sh * 3 / 2)) return false;
        const uint32_t uvS = sw / 2;
        const uint8_t* Y   = src;
        const uint8_t* V   = src + sw * sh;
        const uint8_t* U   = V + uvS * (sh / 2);
        for (uint32_t y = 0; y < sh; ++y) {
            uint8_t* dstRow = out.data() + y * sw * 4;
            for (uint32_t x = 0; x + 1 < sw; x += 2) {
                const uint8_t cb = U[(y/2)*uvS + x/2], cr = V[(y/2)*uvS + x/2];
                yuv2rgba(Y[y*sw + x],     cb, cr, dstRow + x * 4);
                yuv2rgba(Y[y*sw + x + 1], cb, cr, dstRow + (x+1) * 4);
            }
        }
    } else {
        return false;  // Unsupported format
    }
    s_convSeq = seq;  // mark this frame as converted so next call skips re-conversion
    return true;
}