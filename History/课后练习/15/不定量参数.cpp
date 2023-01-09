#include <iostream>
#include <windows.h>
using namespace std;

int chartoint(const char* str)
{
    // 记录结果
    int result = 0;

    // 遍历字符串
    for (; *str != '\0'; str++)
    {
        // 把字符转换为数字
        int number = *str - '0';

        // 累加数字
        result = result * 10 + number;
    }

    // 返回结果
    return result;
}
