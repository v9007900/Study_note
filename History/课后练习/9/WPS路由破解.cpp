#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    int Key{42958676};
    int i=0;

huiqu:
    
    if (i != Key)
    {
        i++;
        goto huiqu;
    }
    cout << "1·����������:" << i << endl;

    for (i = 0; i != Key; i++)
    {
    }
    cout << "2·����������:" << i << endl;

    i = 0;
    while (i != Key)
    {
        i++;
    }
    cout << "3·����������:" << i << endl;

    i = 0;
    do
    {
        i++;
    } while (i != Key);
    cout << "4·����������:" << i << endl;
}
