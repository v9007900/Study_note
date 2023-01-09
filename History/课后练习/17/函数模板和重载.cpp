#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

template <typename one>
one Add(one a, one b) //// 函数模板
{
    cout << "1----" << &a << "----" << &b << endl;
    return a < b ? a : b;
}

int* Add(int* a, int* b) ////函数重载，执行大于函数模板
{
    cout << "2----" << &a << "----" << &b << endl;
    return *a > *b ? a : b;
}

float* Add(float* a, float* b) ////函数重载，执行大于函数模板
{
    cout << "2" << endl;
    return *a > *b ? a : b;
}

char* Add(char* a, char* b) ////函数重载，执行大于函数模板
{
    cout << "2" << endl;
    return *a > *b ? a : b;
}

int main()
{
    int a{300};
    int b{500};
    int c;
    c = *Add(&a, &b);
    cout << "3----" << &a << "----" << &b << endl;
    cout << c << endl;

    c = Add(a, b);
    cout << "4----" << &a << "----" << &b << endl;
    cout << c << endl;
}
