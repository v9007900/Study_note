#include <iostream>
#include <windows.h>
using namespace std;

template <typename Tda, typename Tdb, typename Tdc, typename Tdd>
Tda eva(Tda a, Tdb b, Tdc c, Tdd d)
{
    return (a + b + c + d) / 10;
}
int main()
{
    ////����ģ�壬�ɸ�ÿ����ֵָ����ͬ����
    cout << eva<int, double, char, unsigned int>(100, 200.45f, 20, 25535) << endl;
    ////���ָֻ��һ������ô���в����������������
    cout << eva<double>(100, 25535.41651, 100, 500);
}
