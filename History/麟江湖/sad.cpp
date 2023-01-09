#include <iostream>
#include <windows.h>
using namespace std;

int main()
{

    int a{100};

    int* b{&a};
    b++;
    cout << b << (char)10 << *b;
}
