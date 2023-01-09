#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"

typedef void (*DRAWFUN)();

namespace GUI {
    bool CreateWnd();

    void WndLoop(DRAWFUN RenderFun, DRAWFUN MenuFun, bool &bWnd);
}  // namespace GUI