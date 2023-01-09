#include <iostream>
#include <windows.h>
using namespace std;

int main()
{

    int  aa {100}, bb {100}, cc {100};
    int *ptr {&aa};


    *ptr = 50 < bb ? *ptr + 50 : *ptr + -50;
    //   (条件)           成立 返回+  不成立返回-    相当于 if
    cout << *ptr;
}
