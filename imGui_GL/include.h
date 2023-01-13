#pragma once
#pragma comment(lib, "F:/Ipad/Study_note/Study_note/imGui_GL/imGui/lib/d3d9.lib")
#include "imGui/imgui.h"
#include "imGui/imgui_impl_dx9.h"
#include "imGui/imgui_impl_win32.h"
#include "imgui/PingFang_Bold.h"

#include <Windows.h>
#include <d3d9.h>



typedef void (*DRAWFUN)();
namespace GUI {
    bool CreateWnd();

    void WndLoop(DRAWFUN RenderFun, DRAWFUN MenuFun, bool &bWnd);
}  // namespace GUI