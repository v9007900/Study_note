#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char vss; // a=97   A=65
    cout << "输入字母:";
    cin >> vss;
    if (vss <= 122) //如果 小于122 继续 大于122 判断符号
    {
        if (vss >= 48)
        {

            if (vss >= 58)
            {
                if (vss >= 65)
                {
                    if (vss >= 91)
                    {
                        if (vss >= 97)
                        {
                            char b = vss - 32;
                            cout << b;
                        }
                        else
                        {
                            cout << "输入的是符号";
                        }
                    }
                    else
                    {
                        char b = vss + 32;
                        cout << b;
                    }
                }
                else
                {
                    cout << "输入的是符号";
                }
            }
            else
            {
                cout << "输入的是数字";
            }
        }
        if (vss < 47)
        {
            cout << "47";
        }
    }
    if (vss >= 123)
    {
        cout << "符号";
    }
    return 0;
}
