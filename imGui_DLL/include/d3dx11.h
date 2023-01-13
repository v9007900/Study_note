#pragma once
#include "../imGui/Font_MiSans_Regular.h"  //字体
#include "../imGui/imgui.h"
#include "../imGui/imgui_impl_dx11.h"
#include "../imGui/imgui_impl_win32.h"
#include "../include/Kiero/kiero.h"

#include <d3d11.h>
#include <dxgi.h>
#include <iostream>
#include <windows.h>
#include <winnt.h>



typedef HRESULT(_stdcall *Present)(IDXGISwapChain *pSwapChaint, UINT Synclinterval, UINT Flags);