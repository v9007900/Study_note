#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int a[]{
        10001,
        20001,
        30001,
        4000,
    };
    int *ptr{&a[0]};

    (*ptr)++; //  带括号=*ptr+1  此时加的是指向地址的 值

    cout << *ptr << "   " << a[0] << endl; // 10002
    cout << *ptr << "   " << ptr << endl;

    *ptr++; //   不带括号 =  先+1 此时的ptr 指向的是内存地址 +1 会改变地址
    cout << *ptr << "   " << ptr << endl;

}
