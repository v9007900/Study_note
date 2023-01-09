#include <iostream>
#include <windows.h>
HWND Dckjb() // HWND=获取窗口句柄   Dckjb=获取游戏窗口句柄
{
    return FindWindowA("Sword2 Window", "Sword2.exe");
}

int R4(UINT_PTR ncdz) // unsigned 表示正数的赋值，R4表示读写
{
    HWND ckjb = Dckjb(); // ckjb=窗口句柄
    DWORD pid = 0, tid = 0;
    tid = GetWindowThreadProcessId(ckjb, &pid);
    HANDLE jcjb = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); // jcjb=进程句柄
    unsigned int fhz = 0;                                  // fhz=返回值，unsigned 表示正数的赋值
    ReadProcessMemory(jcjb, (LPCVOID)ncdz, &fhz, 4, 0);    //用于读取地址
    CloseHandle(jcjb);                                     //释放句柄资源
    printf("tid=%d pid=%d", tid, pid);
    return fhz;
}

int main()
{
    int Yg = R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560);    // Yg=阳光  R4=读写的意思，这里需要读最后的值，需要读3次
    UINT_PTR Ygdz = R4(R4(0x6A9EC0) + 0x768) + 0x5560; // Ygdz=阳光地址,UINT_PTR用来表示无符号指针，具有通用性，在64位的占用8个字节
    printf("阳光=%d\n", Yg);
    printf("阳光地址=%X\n", Ygdz);
    W4(Ygdz, 99999);
    getchar(); //等待键盘输入
}





int W4(UINT_PTR ncdz, DWORD xrdz) // ncdz=内存地址  xrdz=写入的值
{
    HWND ckjb = Dckjb(); // ckjb=窗口句柄
    DWORD pid = 0, tid = 0;
    tid = GetWindowThreadProcessId(ckjb, &pid);
    HANDLE jcjb = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); // jcjb=进程句柄
    unsigned int fhz = 0;                                  // fhz=返回值，unsigned 表示正数的赋值
    WriteProcessMemory(jcjb, (LPVOID)ncdz, &xrdz, 4, 0);   //用于写入地址
    CloseHandle(jcjb);                                     //释放句柄资源
    return fhz;
}