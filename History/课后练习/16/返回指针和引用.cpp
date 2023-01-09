#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

// 获取字符串长度
int clen(const char* str) // char类型的指针 str      1
{
    int i;
    for (i = 0; str[i]; i++)
        ;
    cout << i;
    // cout << "第一个str:" << &str << "----" << str << endl; // 获取这个指针的值和地址
    return ++i;
}

// 复制字符串
char* cstr(const char* str) // 也是一个char类型的指针 str     1
{
    // 获取字符串长度
    int len = clen(str);
    // 分配内存
    char* strrt = new char[len]; // 内存地址在堆上，遇到}不会结束

    // 复制字符串
    memcpy(strrt, str, len);

    // 返回复制的字符串
    return strrt;
}

int main()
{
    char* str; // 还是char 类型的指针，三个指针都指向str，没有额外变量，  1
    str = cstr("78945624");
    cout << str << endl;
    delete[] str; // 释放str内存
    cout << str << endl;
}
// 该程序用于复制字符串，并输出复制后的字符串。在 main 函数中，通过调用 cstr 函数复制字符串
// "78945624"，并将复制后的字符串输出。