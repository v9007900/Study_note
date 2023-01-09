#include <iostream>
#include <sstream>
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
    // 设置控制台窗口的列数和行数
    system("mode con cols=40 lines=15");

    // 设置控制台窗口的颜色
    system("color 8E");

    // 从标准输入流中读取字符串
    string strin{};
    cin >> strin;

    // 将字符串转换为整数
    int xc = stoi(strin);

    // 计算字符串的长度
    int length{0};
    for (int i = 0; strin[i]; i++)
    {
        // 如果字符串中出现了中文字符，需要跳过下一个字节
        if (strin[i] < 0)
            i++;
        length++;
    }

    // 输出字符串的长度和转换后的整数值
    cout << length << (char)10 << xc << endl;

    // 使用 printf 函数输出转换后的整数值
    printf_s("%s", xc);
}