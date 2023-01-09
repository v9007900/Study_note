#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char cins{};
    cout << "输入一个字符:";
    cin >> cins; // 47以上符号 58以下符号
    if ((cins > 47) && (cins < 58))
    { //大于 47 是数字  小于 58 是 数字+符号
        cout << "输入的是一个数字:" << cins;
    }
    else if ((cins >= 65) && (cins <= 90))
    { //大于等于 65 是大写字母  小于等于 90 是大写字母
        cout << "输入的是大写字母:" << cins << "转换成小写:" << char(cins + 32);
    }
    else if ((cins > 96) && (cins < 123))
    { //大于 96 是小写字母 小于 123 是小写字母
        cout << "输入的是小写字母:" << cins << "转换成大写:" << char(cins - 32);
    }
    return 1;
}

/*
    如果 (cins 大于 47) 和 (cins 小于 58)
    {满足条件 执行括号内的命令
    }
    否则执行括号外↓
    如果 (cins 大于等于65) 和 （cins 小于等于 90)
    {满足条件，执行括号内的指令
    }
    不满足条件，执行括号外的指令
    重复.....
*/