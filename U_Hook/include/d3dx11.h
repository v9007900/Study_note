#pragma once
#pragma comment(lib, "E:/Git/UnrealEngine/Engine/Source/ThirdParty/Windows/DirectX/Lib/x86/d3d11.lib")
#include "../imGui/imgui.h"
#include "../imGui/imgui_impl_dx11.h"
#include "../imGui/imgui_impl_win32.h"

#include <d3d11.h>
#include <minwindef.h>
#include <stdio.h>
#include <windows.h>

void Dx11Hook();
