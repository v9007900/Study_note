#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

template <typename one>
one Add(one a, one b)
{
    return a + b;
}
int main()
{
    ////       <int>  ǿ��ת��int
    cout << Add<int>(55.61f, 12.158f) << endl; ////��� 67.7687
    cout << Add(30, 50) << endl;               ////��� 80
    cout << Add((char)30, (char)50) << endl;   ////��� P
}
