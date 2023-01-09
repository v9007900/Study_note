#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int a, b;
    cout << "年龄:";
    cin >> a;
    cout << "成绩:";
    cin >> b;

    //（1）年龄小于18岁，成绩大于等于90分
    //（2）年龄大于等于18岁，成绩小于等于90分

    // 18以内  90以上 输出1
    // 18以上  90以下 输出1

    //条件1 小于18  条件2小于90
    //年龄小于18  为 1 执行
    //成绩小于90  为 1 执行
    // 1 与  1  不满足 异或^ 条件 输出2
    //年龄大于18  成绩小于90
    // 1 与 0  满足 年龄大于18  成绩小于90的条件  输出 1

    if ((a < 20) ^ (b < 80))
    {
        cout << "1";
    }
    else
        cout << "2";
    return 1;
}

/*









*/