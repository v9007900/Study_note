#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

template <typename one>
one Add(one a, one b) //// ����ģ��
{
    cout << "1----" << &a << "----" << &b << endl;
    return a < b ? a : b;
}

int* Add(int* a, int* b) ////�������أ�ִ�д��ں���ģ��
{
    cout << "2----" << &a << "----" << &b << endl;
    return *a > *b ? a : b;
}

float* Add(float* a, float* b) ////�������أ�ִ�д��ں���ģ��
{
    cout << "2" << endl;
    return *a > *b ? a : b;
}

char* Add(char* a, char* b) ////�������أ�ִ�д��ں���ģ��
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
