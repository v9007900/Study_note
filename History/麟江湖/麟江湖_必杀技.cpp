#include <iostream>
#include <windows.h>
using namespace std;

int main()
{

    int MP(1460), lsMP{MP};
    int Cri{}, ATX{};
    do
    {
        Cri += 100;
        MP -= ATX;
        ATX += 50;
        cout << "\nÔì³ÉÉËº¦:" << Cri << "Ê£ÓàMP:" << MP;
        Sleep(500);
    } while (MP >= ATX);
    MP = lsMP;
    cout << (char)10 << "MP:" << MP;
}
