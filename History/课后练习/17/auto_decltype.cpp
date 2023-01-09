#include <iostream>
#include <windows.h>
using namespace std;

decltype(auto) Add(char& ary, char& bry)
{
    return ary > bry ? ary : bry;
}

int main()
{
    char a{30}, b{50};
    char c = Add(a, b);
    cout << c;
}
