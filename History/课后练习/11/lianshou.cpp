#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int a[10]{105, 98, 73, 58, 32, 31, 25, 22, 3, 1};
    int acount = sizeof(a)/sizeof(int);
    int* anew = new int[acount+1];

    int x;
    cout<<"输入一个值";
    cin>>x;

    int getindex{-1};
    if (/* condition */)
    {
        /* code */
    }
    
    cout << getIndex;
}
