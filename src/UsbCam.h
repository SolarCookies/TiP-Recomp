#pragma once
#include <cstdint>
#include <vector>

// Returns the latest camera frame converted to RGBA8 in `out`.
// outW / outH are set to the native capture resolution (e.g. 1920x1080).
// outFmtCC receives the DirectShow subtype FourCC (e.g. 'NV12' = 0x3231564E).
// outFrameSeq is incremented by the DirectShow callback on every new frame;
//   callers can compare against their last value to skip redundant texture uploads.
// Returns false if the camera is not open or no frame has arrived yet.
/*
bool UsbCam_GetFrameRGBA(std::vector<uint8_t>& out,
                          uint32_t& outW,
                          uint32_t& outH,
                          uint32_t& outFmtCC,
                          uint64_t& outFrameSeq);
                          */
