#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int Pass1{0}, Pass2{0};

congxin:
    cout << "输入密码:";
    cin >> Pass1;
    cout << "确认密码:";
    cin >> Pass2;

    if (int Crack{0}; Pass1 == Pass2)
    {
        cout << "密码正确,\n按下任意键进入破解...\n";
        system("cls");
        _getch();
    kaishi:
        if (Crack != Pass1)
        {
            Crack++;
            printf("破解进度%d\n", Crack);
            goto kaishi;
        }
        else
        {
            cout << "密码破解成功:" << Crack << endl;
            goto congxin;
        }
    }
    else
    {
        cout << "密码错误，请重新输入。";
    }
    return 0;
}
