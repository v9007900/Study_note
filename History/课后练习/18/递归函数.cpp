#include <iostream>
#include <windows.h>
using namespace std;

int eva(int xdd)
{
    cout << xdd << endl;
    if (xdd == 1)
        return 0;
    return xdd + eva(xdd - 1);
    ////xdd(10) + eva(xdd 10-1)=xdd(10)-9
}
int main()
{
    cout << eva(10);
    int a{0}, b{0}, c{250};
    a = --c;
    b = c--;

    cout << endl << a << endl << b;
}
