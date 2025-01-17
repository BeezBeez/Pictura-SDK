#pragma once
#include "Core/CoreFramework.h"

namespace Pictura::Runtime
{
    class NTRuntime
    {
      public:
        static String GetLastErrorAsString()
        {
            //Get the error message, if any.
            DWORD errorMessageID = ::GetLastError();
            if (errorMessageID == 0)
                return String(); //No error message has been recorded

            LPSTR messageBuffer = nullptr;
            size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                         NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

            std::string message(messageBuffer, size);

            //Free the buffer.
            LocalFree(messageBuffer);

            return message;
        }

        static int NTMessageBox(HWND wndHwnd, LPCTSTR Message, LPCTSTR Title, UINT Type)
        {
            int msgBoxResult = MessageBox(wndHwnd, Message, Title, Type);
            return msgBoxResult;
        }
    };
}