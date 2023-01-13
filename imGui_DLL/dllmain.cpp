#pragma once
#include "./include/d3dx11.h"


Present oPresent;
HRESULT _stdcall hkEndScene(IDXGISwapChain *pSwapChain, UINT Synclnterval, UINT Flags)
{
    static bool init_hook = false;
    if (!init) {
        MessageBox(0, "BOOm", "Kiero", MB_OK);
        init = true;
    }
}

int KieroExampleThread()

{
    bool init = false;
    if (kiero::init(kiero::RenderType::Auto) == kiero::Status::Success) {
        //
        kiero::bind(8, (void **)&oPresent, hkEndScene);
    }
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}