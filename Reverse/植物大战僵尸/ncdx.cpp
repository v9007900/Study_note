#include <iostream>
#include <windows.h>
HWND Dckjb() // HWND=��ȡ���ھ��   Dckjb=��ȡ��Ϸ���ھ��
{
    return FindWindowA("Sword2 Window", "Sword2.exe");
}

int R4(UINT_PTR ncdz) // unsigned ��ʾ�����ĸ�ֵ��R4��ʾ��д
{
    HWND ckjb = Dckjb(); // ckjb=���ھ��
    DWORD pid = 0, tid = 0;
    tid = GetWindowThreadProcessId(ckjb, &pid);
    HANDLE jcjb = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); // jcjb=���̾��
    unsigned int fhz = 0;                                  // fhz=����ֵ��unsigned ��ʾ�����ĸ�ֵ
    ReadProcessMemory(jcjb, (LPCVOID)ncdz, &fhz, 4, 0);    //���ڶ�ȡ��ַ
    CloseHandle(jcjb);                                     //�ͷž����Դ
    printf("tid=%d pid=%d", tid, pid);
    return fhz;
}

int main()
{
    int Yg = R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560);    // Yg=����  R4=��д����˼��������Ҫ������ֵ����Ҫ��3��
    UINT_PTR Ygdz = R4(R4(0x6A9EC0) + 0x768) + 0x5560; // Ygdz=�����ַ,UINT_PTR������ʾ�޷���ָ�룬����ͨ���ԣ���64λ��ռ��8���ֽ�
    printf("����=%d\n", Yg);
    printf("�����ַ=%X\n", Ygdz);
    W4(Ygdz, 99999);
    getchar(); //�ȴ���������
}





int W4(UINT_PTR ncdz, DWORD xrdz) // ncdz=�ڴ��ַ  xrdz=д���ֵ
{
    HWND ckjb = Dckjb(); // ckjb=���ھ��
    DWORD pid = 0, tid = 0;
    tid = GetWindowThreadProcessId(ckjb, &pid);
    HANDLE jcjb = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); // jcjb=���̾��
    unsigned int fhz = 0;                                  // fhz=����ֵ��unsigned ��ʾ�����ĸ�ֵ
    WriteProcessMemory(jcjb, (LPVOID)ncdz, &xrdz, 4, 0);   //����д���ַ
    CloseHandle(jcjb);                                     //�ͷž����Դ
    return fhz;
}