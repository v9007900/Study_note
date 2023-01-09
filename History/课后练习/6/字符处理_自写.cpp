#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");

    char a; //新的开始
    cin >> a;
    if ((a > 47) && (a < 58))
    { //判断是不是数字
        cout << "true";
    }
    else
        cout << "false";
    return 0;
}

/*
    1,是否为大写字母  > 64  < 91  ?
    2,是否为小写字母  > 96 < 123  ?
    3,是否为字母     > 64 < 91  > 96 < 123?
    4,是否为数字     ( > 47 ~ < 58 )?

    5,是字母或者数字
    6,是否为空白      127 141 143 144 157 160
    7,是否为空格      (32))
    8,是不是标点符号   >57  <65  >90  <97  <122
    9,能不能打印
    10,是不是控制字符
    11,是不是图形字符
    12,将字符转化为大写  (97~122)  -32
    13,将字符转化为小写  (65~90)   +32
*/