#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

int str_len(char const *ptr, int i = 0)  // 计算字符串有效长度（包括中文）长度
{
    for (; *ptr != '\0'; ++ptr, ++i)
        if (*ptr < 0) ++ptr;
    return i;
}
void func(const char *ch3, char *ch4)
{
    while ((*ch4++ = *ch3++)) {}
}

int main()
{
    char  cs[] {"Hello world"};
    char *ch1 {cs};
    char  ch2[20] {};
    func(ch1, ch2);

    printf("ch1 ----%s----\n", ch1);
    printf("ch2 ----%s----\n", ch2);
}

// main-1-cha1--0000000ddd7ff6fc--ch2--0000000ddd7ff6e0
// func-1--ch1--0000000ddd7ff6fc--ch2--0000000ddd7ff6e0
// func-1--ch1--0000000ddd7ff708--ch2--0000000ddd7ff6ec
// main-1-cha1--0000000ddd7ff6fc--ch2--0000000ddd7ff6e0

// main-1-cha1--000000d388bffd98--ch2--000000d388bffd80
// func-1--ch1--000000d388bffd98--ch2--000000d388bffd80
// func-1--ch1--000000d388bffda4--ch2--000000d388bffd8c
// main-1-cha1--000000d388bffd98--ch2--000000d388bffd80
