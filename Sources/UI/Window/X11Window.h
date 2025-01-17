#pragma once
#include "NullWindow.h"

namespace Pictura::UI
{
    class X11Window : public NullWindow
    {
      public:
        X11Window();
        ~X11Window();

      private:
        void *SetupWindow();

      protected:
        virtual void SetFullscreen(bool value);

      public:
        virtual void Show();
        virtual void Hide();
        virtual void Close();
        virtual void Focus();
        virtual void Update();

        virtual MessageBoxResult MessageBox(WideString Message, WideString Title, MessageBoxIcon Icons, MessageBoxButtons Buttons);
    };
} // namespace Pictura::UI