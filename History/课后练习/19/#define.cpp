
#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

////定义一个释放内存的宏
#define RELEASE(x)                                                                                                     \
    delete[] x;                                                                                                        \
    x = nullptr;
#define eva(x) std::cout << x << endl // 定义一个替换cout的宏 #x 可以直接输入字符串

int main()
{
    int* add = new int;
    printf("%d\n", *add);

    // RELEASE(add);

    printf("%d\n", *add);

    eva(15415);
}
