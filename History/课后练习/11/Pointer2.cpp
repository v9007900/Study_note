#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int a[5]{123, 456, 789, 111, 122};
    int *b[100];

    for (int i = 0; i < 100; i++)
    {
        b[i] = &a[i];
        cout << *b[i] << "    " << b[i] << endl;
    }




    
}
