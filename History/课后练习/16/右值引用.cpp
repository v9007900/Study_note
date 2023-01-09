#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

void Add(int&& a)
{
    cout << a << endl;
    cout << &a << endl; // 0x61fe18
}
int main()
{
    Add(320 + 250);
    char* str = (char*)Add;
    for (int i = 0; i < 30; i++)
    {
        printf_s("%02x\n", (unsigned char)str[i]);
    }
}
