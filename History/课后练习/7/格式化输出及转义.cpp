#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a = _getch(), b = _getch(); //获取键盘按键 ASCLL 编码
    printf("%d\t%d\n", a, b);        //正常输入
    printf("%+05d\n", a, b);         //字符对齐  0=替代显示  5=字符长度  + = 显示正负

    //  % d = 十进制
    //  %o = 八进制
    //  %u = 无符号十进制
    //  %x = 十六进制

    return 0;
}
