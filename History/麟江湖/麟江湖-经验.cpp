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
            cout << "��ǰ�ȼ�:" << setw(3) << lv << "\t\t"
                 << "����ֵ:" << setw(7) << (int)(lv * lv) * 100 << endl;
            Sleep(10);
        }
    }
    else
    {
        cout << "�����������������" << endl;
        goto huiqu;
    }
}
