#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    int a[]{1, 23, 465, 498546, 5464, 65465, 7, 456, 465, 456, 465, 46};
    int b = 7;
    int i{};
    i = 0;
    while (b != a[i])
    {
        i++;
        cout << a[i] << endl;
    }
    cout << a[i];

    // cout << "2";
    // cout << a[i];
}
