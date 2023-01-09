#pragma once
#include "d3dx11.h"



// Data
static ID3D11Device           *g_pd3dDevice           = NULL;
static ID3D11DeviceContext    *g_pd3dDeviceContext    = NULL;
static IDXGISwapChain         *g_pSwapChain           = NULL;
static ID3D11RenderTargetView *g_mainRenderTargetView = NULL;

HWND     g_hWnd = nullptr;
DWORD64 *Vtb    = nullptr;


void Dx11Hook()
{
    // 获取游戏类名
    g_hWnd = FindWindowA("UnrealWindow", NULL);

    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount                        = 2;
    sd.BufferDesc.Width                   = 0;
    sd.BufferDesc.Height                  = 0;
    sd.BufferDesc.Format                  = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator   = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags                              = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage                        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow                       = g_hWnd;
    sd.SampleDesc.Count                   = 1;
    sd.SampleDesc.Quality                 = 0;
    sd.Windowed                           = TRUE;
    sd.SwapEffect                         = DXGI_SWAP_EFFECT_DISCARD;



    UINT              createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;


    const D3D_FEATURE_LEVEL featureLevelArray[2] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };
    HRESULT res = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, nullptr,
                                                &featureLevel, nullptr);
    if (res == DXGI_ERROR_UNSUPPORTED)
        res = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_WARP, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, nullptr,
                                            &featureLevel, nullptr);
    if (res != S_OK) return;  // bug 这里有优化，可能会出问题

    Vtb = *(DWORD64 **)g_pSwapChain;
    printf("%llu\n", Vtb[8]);
}