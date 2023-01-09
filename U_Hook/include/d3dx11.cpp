#pragma once
#include "d3dx11.h"

#include <stdio.h>

bool bWnd = true;  // 判断菜单  真假


typedef HRESULT(WINAPI *Present)(IDXGISwapChain *This, UINT SyncInterval, UINT Flags);
typedef LRESULT(WINAPI *WndProc)(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(WINAPI *Resize)(IDXGISwapChain *This, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);



HRESULT WINAPI Init(IDXGISwapChain *This, UINT SyncInterval, UINT Flags);

// Data
static ID3D11Device           *g_pd3dDevice           = NULL;
static ID3D11DeviceContext    *g_pd3dDeviceContext    = NULL;
static IDXGISwapChain         *g_pSwapChain           = NULL;
static ID3D11RenderTargetView *g_mainRenderTargetView = NULL;

HWND     g_hWnd   = nullptr;
DWORD64 *Vtb      = nullptr;
Present  oPresent = nullptr;
WndProc  oWndProc = nullptr;
Resize   oResize  = nullptr;


void GetDx11ptr(IDXGISwapChain *This);  // 会经常用到的函数          这里

static bool Debug_1 = false;
static bool Z_ji    = false;
static bool Home    = true;
int         hukjua {1};



HRESULT WINAPI hkPresent(IDXGISwapChain *This, UINT SyncInterval, UINT Flags)
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;



    // ImGuiWindowFlags_AlwaysAutoResize  根据组件自动调整大小
    // ImGuiWindowFlags_MenuBar           子菜单
    // ImGuiWindowFlags_NoDecoration      取消标题栏
    // ImGuiWindowFlags_NoResize          禁用右下角小三角


    ImGui::SetNextWindowSize(ImVec2(450, 250));  // imgui 窗口大小
    ImGui::Begin("标题", NULL, ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoCollapse);
    ImGui::Checkbox("222", &Debug_1);  // 选项框
    ImGui::Checkbox("333", &Z_ji);     // 选项框


    // ImGui::SliderInt(u8"滑动条", &hukjua, 1, 5);

    ImGui::End();



    // //注入部分
    // UWorld* World = GetWorld();
    // TArray<AActor*>& Actors = World->PersistentLevel->Actors;

    // for (size_t i = 0; i < Actors.Count; i++)
    // {
    //     AActor* Actor = Actors.Data[i];

    //     if (!Actor || (Actor->RootComponent))
    //         continue;

    //     string ActorName = Actor->GetName();

    //     if(ActorName.find("Zombie_BP") == string::npos)
    //         continue;


    //     FTransform& Transform = Actor->RootComponent->ComponentToWorld;

    //     Vector2 Screen{ 0 };
    //     if (WorldToScreen(Transform.Translation, Screen))
    //     {
    //         /*char buf[256];
    //         sprintf(buf, "%p", Actor);*/
    //         ImGui::GetForegroundDrawList()->AddText({ Screen.X,Screen.Y }, ImColor(255, 255,50), ActorName.c_str());
    //     }


    // }



    ImGui::Render();
    g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    // 将imgui 绘制 提交到 dx11

    return oPresent(This, SyncInterval, Flags);
};


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
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, nullptr, &featureLevel, nullptr) != S_OK) return;

    Vtb = *(DWORD64 **)g_pSwapChain;
    printf("%llu\n", Vtb[8]);
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);  // 自己加的


LRESULT WINAPI hkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) return true;


    return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam);
}

HRESULT WINAPI hkResize(IDXGISwapChain *This, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{



    if (g_pd3dDevice) {
        g_pd3dDevice->Release();
        g_pd3dDevice = nullptr;
        g_mainRenderTargetView->Release();
        ImGui_ImplDX11_Shutdown();
        Vtb[8] = (DWORD64)Init;
    }
    return oResize(This, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

HRESULT WINAPI Init(IDXGISwapChain *This, UINT SyncInterval, UINT Flags)
{

    static bool Is = true;
    GetDx11ptr(This);

    if (Is) {
        Is       = false;
        oWndProc = (WndProc)SetWindowLongPtrA(g_hWnd, GWLP_WNDPROC, (LONG_PTR)hkWndProc);
        ImGui::CreateContext();    // 创建imgui 环境
        ImGui::StyleColorsDark();  // 创建imgui 默认样式
        ImGui_ImplWin32_Init(g_hWnd);


        ////加载字体
        ImGuiIO &io    = ImGui::GetIO();
        io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;


        /*ImGui::CreateContext();
        ImGuiIO& io1 = ImGui::GetIO(); (void)io1;*/
        // ImFont* font = io1.Fonts->AddFontFromFileTTF("D:\\Ipad\\PingFang.ttf", 20.0f, NULL, io1.Fonts->GetGlyphRangesChineseFull());
        ImFont *font = io.Fonts->AddFontFromMemoryTTF((void *)PingFangttf_data, PingFangttf_size, 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());  // 内存字体
        ImGui_ImplWin32_Init(g_hWnd);
    }



    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    Vtb[8] = (DWORD64)hkPresent;
    return oPresent(This, SyncInterval, Flags);
}

void GetDx11ptr(IDXGISwapChain *This)  // 会经常用到的函数
{
    g_pSwapChain = This;
    g_pSwapChain->GetDevice(__uuidof(g_pd3dDevice), (void **)&g_pd3dDevice);
    g_pd3dDevice->GetImmediateContext(&g_pd3dDeviceContext);

    ID3D11Texture2D *pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void DX11Hook()
{

    g_hWnd = FindWindowA("UnrealWindow", NULL);  // 窗口标题

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

    UINT createDeviceFlags = 0;
    // createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL       featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, nullptr, &featureLevel, nullptr) != S_OK) return;


    Vtb = *(DWORD64 **)g_pSwapChain;
    DWORD Prptect;
    VirtualProtect(Vtb, 1, PAGE_EXECUTE_READWRITE, &Prptect);  // 解除保护权限

    oPresent = (Present)Vtb[8];
    oResize  = (Resize)Vtb[13];
    Vtb[8]   = (DWORD64)Init;
    Vtb[13]  = (DWORD64)hkResize;
    g_pSwapChain->Release();  // 释放交换链指针
}