#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;
// L=76 l=108
int main()
{
huiqu:
    char cin = _getch();
    if ((cin == 'l') || (cin == 'L'))
    {
        for (int lv = 0; lv <= 100; lv++)
        {
            cout << setfill(' ');
            cout << "当前等级:" << setw(3) << lv << "\t\t"
                 << "经验值:" << setw(7) << (int)(lv * lv) * 100 << endl;
            Sleep(10);
        }
    }
    else
    {
        cout << "输入错误，请重新输入" << endl;
        goto huiqu;
    }
}
