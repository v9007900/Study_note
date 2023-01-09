#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int a, b, c;

    cout << "第一个整数:";
    cin >> a;
    cout << "第二个整数:";
    cin >> b;

    //  x = bool ? y : z ; 等同于 下面if
    //  if(a > b)
    //  c=a
    //  else c = b

    // x=bool?Y:Z； bool 对应 a > b
    c = (a > b ? a : b) + 50000; //? bool 真或假
    // 条件？   成立    c=a    不成立   c=b

    cout << c << char(10) << endl;

    if (a > b)
    {
        c = a;
        cout << c;
    }
    else if (a < b)
    {
        c = b;
        cout << c << char(10) << char(10);
    }

    int cs;
    cout << "\n输入一个数,自动计算1万除以这个数以后的结果:";
    cin >> cs;
    int ends;
    ends = cs ? (10000 / cs) : 0;
    cout << ends;

    return 0;
}
