#include <iostream>
using namespace std;

#pragma pack(1) ////     �޸�class struct �ڴ������ֽ���Ϊ (n)

class Addx {
public:

    char  a[3]; // 3�ֽ�     [][][]����  ��1�ֽ�
    int   b;    // 4�ֽ�     [][][][]
    short c;    // 2�ֽ�     [][]�������� ��2�ֽ�
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
    int size = sizeof(arr); // size = arr �����ֽ�

    unsigned char *ptr {(unsigned char *)&arr}; // ����ָ��ptr ָ��arr�׵�ַ

    // �鿴�ڴ�
    for (int i = 0; i < size; i++) {
        printf("[%x]", *ptr);
        ptr++;
    }
}
