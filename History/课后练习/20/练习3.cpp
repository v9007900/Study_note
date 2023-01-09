#include <iostream>
#include <iterator>
#include <windows.h>
using namespace std;

int main()
{
    int* ptr{(int*)0x4DF0E54};
    for (int i = 0; i < 16; i++)
    {
        cout << ptr + i << endl;
    }
}
