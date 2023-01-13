#pragma once
#include "./include/d3dx11.h"

#include <processthreadsapi.h>



Present oPresent;
HRESULT _stdcall hkEndScene(IDXGISwapChain *pSwapChain, UINT Synclnterval, UINT Flags)
{
    static bool init_hook = false;
    if (!init_hook) {
        MessageBox(0, "BOOm", "Kiero", MB_OK);
        init_hook = true;
    }
    return oPresent(pSwapChain, Synclnterval, Flags);
}

int KieroExampleThread()
{
    bool init = false;
    do {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            //
            kiero::bind(8, (void **)&oPresent, hkEndScene);
        }
    } while (!init);
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)KieroExampleThread, NULL, 0, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
