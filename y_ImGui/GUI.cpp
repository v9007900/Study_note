#include "./include/includes.h"

/*
 * 创建窗口
 *
 * 初始化d3d
 *
 * 初始化 IMGUI
 *
 * 设置消息循环
 *
 */
LPDIRECT3D9           g_pD3D       = {};
LPDIRECT3DDEVICE9     g_pd3dDevice = {};
D3DPRESENT_PARAMETERS g_d3dpp      = {};
WNDCLASSEX            wClass       = {};
HWND                  hHackWnd     = {};


// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI                WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool                          CreateDeviceD3D(HWND hWnd);
void                          CleanupDeviceD3D();

bool GUI::CreateWnd()
{
    // 初始化窗口类
    wClass.cbClsExtra    = NULL;
    wClass.cbSize        = sizeof(WNDCLASSEX);
    wClass.cbWndExtra    = NULL;
    wClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    wClass.hCursor       = LoadCursor(0, IDC_ARROW);
    wClass.hIcon         = LoadIcon(0, IDI_APPLICATION);
    wClass.hIconSm       = LoadIcon(0, IDI_APPLICATION);  // 默认图标
    wClass.hInstance     = GetModuleHandle(NULL);
    wClass.lpfnWndProc   = (WNDPROC)WndProc;
    wClass.lpszClassName = L" ";
    wClass.lpszMenuName  = L" ";
    wClass.style         = CS_VREDRAW | CS_HREDRAW;
    // 如果移动或大小调整更改工作区的高度，则重新绘制整个窗口。
    // 如果移动或大小调整更改了工作区的宽度，则重新绘制整个窗口。



    if (RegisterClassEx(&wClass) == 0) {
        MessageBoxA(NULL, "创建窗口出错！", "提示！", 0);
        exit(1);
    }

    // 创建窗口
    int cx   = GetSystemMetrics(SM_CXSCREEN); /* 屏幕宽度 */
    int cy   = GetSystemMetrics(SM_CYSCREEN); /* 屏幕高度 */
    hHackWnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_COMPOSITED | WS_EX_COMPOSITED, L" ", L" ", WS_POPUP, 1, 1, cx, cy, 0, 0, 0, 0);
    //                       窗口是分层 窗口 窗口是调色板窗口  使用双缓冲

    if (!CreateDeviceD3D(hHackWnd)) {
        CleanupDeviceD3D();
        ::UnregisterClass(wClass.lpszClassName, wClass.hInstance);
        MessageBox(NULL, L"ImGui初始化失败!", L"error", MB_OK);
        exit(1);
    }

    SetLayeredWindowAttributes(hHackWnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
    ShowWindow(hHackWnd, SW_SHOW);


    // 设置ImGui上下文
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;



    // 设置ImGui样式
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsClassic();

    // 安装平台/渲染器后端
    ImGui_ImplWin32_Init(hHackWnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // imgui  颜色 风格
    {
        ImGui::StyleColorsDark();
        ImGuiStyle &style                   = ImGui::GetStyle();
        ImVec4     *colors                  = style.Colors;
        colors[ImGuiCol_FrameBg]            = ImVec4(0.16f, 0.16f, 0.17f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]     = ImVec4(0.37f, 0.36f, 0.36f, 102.00f);
        colors[ImGuiCol_FrameBgActive]      = ImVec4(0.10f, 0.10f, 0.10f, 171.00f);  // 标题
        colors[ImGuiCol_TitleBg]            = ImVec4(0.10f, 0.10f, 0.10f, 171.00f);  // 选中标题
        colors[ImGuiCol_TitleBgActive]      = ImVec4(0.10f, 0.10f, 0.10f, 171.00f);  // 选中标题
        colors[ImGuiCol_CheckMark]          = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        colors[ImGuiCol_SliderGrab]         = ImVec4(0.64f, 0.64f, 0.64f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]   = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
        colors[ImGuiCol_Button]             = ImVec4(0.22f, 0.22f, 0.22f, 0.40f);
        colors[ImGuiCol_ButtonHovered]      = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
        colors[ImGuiCol_ButtonActive]       = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
        colors[ImGuiCol_Header]             = ImVec4(0.45f, 0.45f, 0.45f, 0.31f);
        colors[ImGuiCol_HeaderHovered]      = ImVec4(0.55f, 0.55f, 0.55f, 0.80f);
        colors[ImGuiCol_HeaderActive]       = ImVec4(0.09f, 0.09f, 0.09f, 1.00f);
        colors[ImGuiCol_ResizeGrip]         = ImVec4(1.00f, 1.00f, 1.00f, 0.20f);
        colors[ImGuiCol_ResizeGripHovered]  = ImVec4(0.46f, 0.46f, 0.46f, 0.67f);
        colors[ImGuiCol_ResizeGripActive]   = ImVec4(0.17f, 0.17f, 0.17f, 0.95f);
        colors[ImGuiCol_SeparatorActive]    = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
        colors[ImGuiCol_SeparatorHovered]   = ImVec4(0.50f, 0.50f, 0.50f, 0.78f);
        colors[ImGuiCol_TabHovered]         = ImVec4(0.45f, 0.45f, 0.45f, 0.80f);
        colors[ImGuiCol_TabActive]          = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
        colors[ImGuiCol_DockingPreview]     = ImVec4(0.51f, 0.51f, 0.51f, 0.70f);
        colors[ImGuiCol_Tab]                = ImVec4(0.21f, 0.21f, 0.21f, 0.86f);
        colors[ImGuiCol_TabUnfocused]       = ImVec4(0.15f, 0.15f, 0.15f, 0.97f);
        colors[ImGuiCol_NavHighlight]       = ImVec4(1.00f, 0.40f, 0.13f, 1.00f);
        colors[ImGuiCol_TextSelectedBg]     = ImVec4(0.45f, 1.00f, 0.85f, 0.35f);
        style.WindowRounding                = 4;
        style.FrameRounding                 = 4;
        style.GrabRounding                  = 3;
        style.ScrollbarSize                 = 7;
        style.ScrollbarRounding             = 0;
        style.WindowTitleAlign              = ImVec2(0.5, 0.5);  // 标题居中
        style.Colors[ImGuiCol_WindowBg]     = ImVec4(255, 255, 255, 250);
        style.Colors[ImGuiCol_SliderGrab]   = ImVec4(255, 255, 255, 250);
    }



    // Setup Dear ImGui context


    // ImGuiIO& io = ImGui::GetIO();
    //(void)io;
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

    // 加载字体
    ImFontConfig bigFontCfg;
    bigFontCfg.FontDataOwnedByAtlas = false;
    ImGuiIO &io1                    = ImGui::GetIO();
    (void)io1;
    ImFont *font = io1.Fonts->AddFontFromMemoryTTF((void *)PingFangttf_data, PingFangttf_size, 20.0f, &bigFontCfg, io1.Fonts->GetGlyphRangesChineseFull());  // 内存字体
}


bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed               = TRUE;
    g_d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat       = D3DFMT_UNKNOWN;  // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval   = D3DPRESENT_INTERVAL_ONE;  // Present with vsync
    // g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0) return false;

    return true;
}
void CleanupDeviceD3D()
{
    if (g_pd3dDevice) {
        g_pd3dDevice->Release();
        g_pd3dDevice = NULL;
    }
    if (g_pD3D) {
        g_pD3D->Release();
        g_pD3D = NULL;
    }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL) IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}
// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) return true;

    switch (msg) {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED) {
            g_d3dpp.BackBufferWidth  = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)  // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}



void GUI::WndLoop(DRAWFUN RenderFun, DRAWFUN MenuFun, bool &bWnd)
{
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT) {
        SetWindowLong(hHackWnd, GWL_EXSTYLE, WS_EX_TOPMOST + WS_EX_LAYERED + WS_EX_TOOLWINDOW + WS_EX_CLIENTEDGE);

        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        // 启动ImGui框架
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // 这里绘制
        RenderFun();
        MenuFun();

        if (GetAsyncKeyState(VK_HOME) & 1) bWnd = !bWnd;



        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * 255.0f), (int)(clear_color.y * 255.0f), (int)(clear_color.z * 255.0f), (int)(clear_color.w * 255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, (0, 0, 0, 0), 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0) {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) ResetDevice();

        // ImGui::EndFrame();
        // g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        // g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        // g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
    }

    // Cleanup
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hHackWnd);
    ::UnregisterClass(wClass.lpszClassName, wClass.hInstance);

    // for (std::vector<HANDLE>::iterator it = MyImGui::ThreadHandle.begin(); it != MyImGui::ThreadHandle.end(); it++)
    //{
    //     TerminateThread(*it, 1);
    //     CloseHandle(*it);
    // }
    // MyImGui::ThreadHandle.clear();
}