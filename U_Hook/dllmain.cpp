#pragma once

#include "./include/d3dx11.h"



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        AllocConsole();
        freopen("CONOUT$", "w+", stdout);
        CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Dx11Hook, NULL, NULL, NULL));
    };

    return true;
}
