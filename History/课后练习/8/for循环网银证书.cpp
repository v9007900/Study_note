#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    // system("mode con cols=40 lines=10");
    // system("color 8E");
    int Pass1{0}, Pass2{0};

    cout << "输入密码:";
    cin >> Pass1;
    cout << "确认密码:";
    cin >> Pass2;
    if (Pass1 == Pass2)
    {
        cout << "密码正确,\n按下任意键进入破解...\n";
        system("cls");
        _getch();

        for (int i = 0; i < 999999; i++)
        {
            if (i != Pass2)
            {
                cout << i << endl;
            }
            else
            {
                cout << "破解成功，密码是:" << i << endl;
                goto mima;
            }
        }
    }
    else
    {
        cout << "密码错误，请重新输入。";
    }
mima:
    return 0;
}
