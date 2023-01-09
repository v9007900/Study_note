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
    ////函数模板，可给每个数值指定不同类型
    cout << eva<int, double, char, unsigned int>(100, 200.45f, 20, 25535) << endl;
    ////如果只指定一个，那么所有参数都将是这个类型
    cout << eva<double>(100, 25535.41651, 100, 500);
}
