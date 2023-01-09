#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

int main()
{

自定义标签名字: //标记一个点，执行到 goto 跳转回来，名称可自定义+:
    printf("跳转到次\n");
    system("pause");
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a{};
    printf("\n输入大写，转化为小写:");
linput1: //标签 当执行到 goto 处 会跳转到此继续执行
    scanf("%s", &a);
    if (a > 64 && a < 97)
    {
        a += 32;
        printf("转化结果:%d", a);
        cout << (char)a << endl;
        goto 自定义标签名字; // 回到 标签处
    }
    else
    {
        printf("请重新输入%d\n", a);
        goto linput1; // 回到 标签1处
    }
    return 0;
}
