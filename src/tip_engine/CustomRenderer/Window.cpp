#include "Window.h"
#include "OpenGL_Stuff.h"

#define GLFW_EXPOSE_NATIVE_WIN32

#include <GLFW/glfw3native.h> // Include this for native access


#pragma comment(lib, "dwmapi.lib")

#include <dwmapi.h>


void VinceWindow::EnableBlur()
{
	HWND hwnd = glfwGetWin32Window(window.get());
	if (!hwnd) return;

	// DWM: Extend frame into client area (title bar and borders)
	MARGINS margins = { -1 }; // -1 means extend to the whole window
	DwmExtendFrameIntoClientArea(hwnd, &margins);

	// Existing blur code...
	const HINSTANCE hModule = LoadLibrary(TEXT("user32.dll"));
	if (hModule)
	{
		typedef struct _ACCENT_POLICY
		{
			int nAccentState;
			int nFlags;
			int nColor;
			int nAnimationId;
		} ACCENT_POLICY;

		typedef struct _WINDOWCOMPOSITIONATTRIBDATA
		{
			int nAttribute;
			PVOID pData;
			SIZE_T ulDataSize;
		} WINDOWCOMPOSITIONATTRIBDATA;

		enum AccentState
		{
			ACCENT_DISABLED = 0,
			ACCENT_ENABLE_BLURBEHIND = 3,
			ACCENT_ENABLE_ACRYLICBLURBEHIND = 4 // Windows 10/11
		};

		auto SetWindowCompositionAttribute = (BOOL(WINAPI*)(HWND, WINDOWCOMPOSITIONATTRIBDATA*))GetProcAddress(hModule, "SetWindowCompositionAttribute");
		if (SetWindowCompositionAttribute)
		{
			ACCENT_POLICY policy = { ACCENT_ENABLE_BLURBEHIND, 0, 0, 0 };
			WINDOWCOMPOSITIONATTRIBDATA data = { 19, &policy, sizeof(policy) };
			SetWindowCompositionAttribute(hwnd, &data);
		}
		FreeLibrary(hModule);
	}
}

void VinceWindow::init()
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		assert(false && "Failed to initialize GLFW");

	// GL 3.0 + GLSL 330
	glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

	if (overlay) {
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
		glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
	}

	// Create window with graphics context using unique_ptr and custom deleter
	window = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(
		glfwCreateWindow(width, height, overlay ? "" : "Solar Renderer", nullptr, nullptr),
		&glfwDestroyWindow
	);
	if (!window) {
		assert(false && "Failed to create GLFW window");
	}

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window.get(), &bufferWidth, &bufferHeight);
	glfwMakeContextCurrent(window.get());

	//glfwSwapInterval(1); // Enable vsync
	//Log("VSync Enabled", EType::Normal);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		assert(false && "Failed to initialize OpenGL context");
	}

	glViewport(0, 0, bufferWidth, bufferHeight);

	if (overlay) {
		HWND hwnd = glfwGetWin32Window(window.get());
		if (hwnd) {
			MARGINS margins = { -1, -1, -1, -1 };
			DwmExtendFrameIntoClientArea(hwnd, &margins);

			// Always-on-top
			SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0,
				SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		}
	} else {
		VinceWindow::EnableBlur();
	}
}

void VinceWindow::SetupImGuiIO()
{
	
}

void VinceWindow::InitFrameBuffer()
{
	//Gets the frame-buffer ready to start
	frameBuffer.create_framebuffer(0);
	frameBuffer2.create_framebuffer(1);
}

void VinceWindow::SyncToOwnerWindow(void* ownerHwnd)
{
	if (!ownerHwnd || !window) return;
	HWND owner = static_cast<HWND>(ownerHwnd);

	RECT rect;
	if (!GetClientRect(owner, &rect)) return;

	POINT topLeft = { rect.left, rect.top };
	ClientToScreen(owner, &topLeft);

	int w = rect.right - rect.left;
	int h = rect.bottom - rect.top;

	// Only update if size/position changed
	int curX, curY, curW, curH;
	glfwGetWindowPos(window.get(), &curX, &curY);
	glfwGetWindowSize(window.get(), &curW, &curH);

	if (curX != topLeft.x || curY != topLeft.y || curW != w || curH != h) {
		glfwSetWindowPos(window.get(), topLeft.x, topLeft.y);
		glfwSetWindowSize(window.get(), w, h);
	}
}
