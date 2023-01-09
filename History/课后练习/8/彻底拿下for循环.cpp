#include <iostream>
#include <windows.h>
using namespace std;
#include <cmath>

int main()
{
    // system("mode con cols=40 lines=15");
    // system("color 8E");

    bool bcase{};
    for (int i = 3; i < 1000; i += 2)
    { // 3+2=5+2=7+=9+2=11
        bcase = false;
        for (int c = 3; c <= sqrt(i); c += 2)
        { // 3<=i 3 5 7 9 11
            if (i % c == 0)
            {
                bcase = true;
                break;
            }
        }
        if (!bcase)
            _sleep(50);
        cout << i << endl;
    }
}
