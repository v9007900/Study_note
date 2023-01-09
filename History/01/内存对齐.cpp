#include <iostream>
using namespace std;

#pragma pack(1) ////     修改class struct 内存对齐的字节数为 (n)

class Addx {
public:

    char  a[3]; // 3字节     [][][]【】  补1字节
    int   b;    // 4字节     [][][][]
    short c;    // 2字节     [][]【】【】 补2字节
};

int main()
{
    Addx arr;
    arr.a[0] = (char)0x10;
    arr.a[1] = (char)0x20;
    arr.a[2] = (char)0x30;
    arr.b    = 0x77665544;
    arr.c    = 0x9988;
    cout << sizeof(arr) << endl;
    int size = sizeof(arr); // size = arr 的总字节

    unsigned char *ptr {(unsigned char *)&arr}; // 定义指针ptr 指向arr首地址

    // 查看内存
    for (int i = 0; i < size; i++) {
        printf("[%x]", *ptr);
        ptr++;
    }
}
