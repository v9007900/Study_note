#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");

    char a; //????
    cin >> a;
    if ((a > 64) && (a < 91))
    {
        cout << "true";
    }
    else
        cout << "false";

    char a; //????¸
    cin >> a;
    if ((a > 96) && (a < 123))
    {
        cout << "true";
    }
    else
        cout << "false";

    char a; //???????
    cin >> a;
    if (((a > 64) && (a < 91)) || ((a > 96) && (a < 123)))
    {
        cout << "true";
    }
    else
        cout << "false";

    char a; //???????
    cin >> a;
    if ((a > 47) && (a < 58))
    {
        cout << "true";
    }
    else

        return 0;
}
