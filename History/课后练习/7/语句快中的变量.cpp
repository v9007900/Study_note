#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int b;
    int a{2}, b{3};
    if (int a; b) //变量a 只存在于 if 语句中
    {
        a = 2;
        printf("aa%d", a);
    }
    else
    {
        a = 3;
        printf("aa%d", a);
    }
    // a = 4; //到括号结尾 a 死亡

    switch (int a; b)
    {

    case 1:
        cout << "1";
        break;

    default:
        break;
    }

    return 0;
}
