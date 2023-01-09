#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main()
{
    char  ch[500] {"geosad"};
    char *ptr {ch};
    ptr += 6;
    for (int i = 0; i < 900; i++, ptr++) *ptr = 0x41;
    printf("%s", ch);

    unsigned const char ch1[] {
        "geosadAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAACA"};
    unsigned char const *ptr2 {ch1};
    for (int i = 0; *ptr2; ptr2++, i++)
        if (*(ptr2 + 1) == '\0') printf("\n%d\n\n", i);

    char *ptrd {(char *)&ch1}; // 用指针指向了一个常量字符串，对齐进行了修改
    ptrd += 20;
    *ptrd = '=';
    printf("ch1的值---%c\n", *ptrd);

    const char chs[] {"Hello world"};
    char      *ptrr {(char *)&chs};
    ptrr += 5, *ptrr = '9';
    printf("\nptrr = %c\n", *ptrr);



    ////常量指针 和 指针常量区域
    int        a {100}; //  const 值 可以通过指针 间接修改
    int        b {300};
    const int *p1 {&a}; //!! 指针在 const 右边  读 常量指针  解读 int类型 常量 指针 p1  值不可修改 地址可修改 易道云写法 误我
    int *const p2 {&a}; //!! 指针在 const 左边  读 指针常量  解读 int类型 指针 常量 p2  值可修改 地址不可修改
    *p2 = 500;
    int const *p3 {&a}; //!! 指针在 const 右边  读 常量指针  解读 int类型 常量 指针 p3  值不可修改 地址可修改
    p3                  = &b;
    int const *const p4 = {&a};



    cout << "P1--" << *p1 << endl;
    cout << "p2--" << *p2 << endl;
    cout << "p3--" << *p3 << endl;
}
