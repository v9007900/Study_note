#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int Pass1, Pass2, Pass3{-1};

    /* while (Pass1 != Pass2)
    {
        system("cls");
        cout << "输入密码:";
        cin >> Pass1;
        cin >> Pass2;
        cout << "确认密码:";
    }

    cout << "开始执行破解程序" << endl;

    while (Pass2 != Pass3)
        Pass3++;

    cout << "密码破解成功" << Pass3; */

    do
    {
        system("cls");
        cout << "输入密码:";
        cin >> Pass1;
        cout << "确认密码:";
        cin >> Pass2;
    } while (Pass1 != Pass2);

    do Pass3++;while (Pass2 != Pass3); cout << "密码破解成功" << Pass3;
}
