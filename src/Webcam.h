#pragma once
typedef int (*XUsbcamCallback)(int a1, int a2, int a3);

inline XUsbcamCallback ReadCallback = nullptr;
inline int ReadCallbackContext = 0;
inline int ReadCallbackSize = 0;


inline void TriggerReadCallback() {
    if (ReadCallback) {
        //ReadCallback(ReadCallbackContext, 0, ReadCallbackSize);
    }
}