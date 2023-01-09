#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
// id=Tomy;Clare;exp=9523;sunny;exp=9460;id=DyBaby;exp=2156;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520;
typedef struct role
{
    string id;
    int exp;

} * Prole;

int main()
{
    string strData = "id=Tomy Clare;exp=9523;id=sunny;exp=9460;id=DyBaby;exp=2156;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520";

    int istart{}, iend{}, icount{};
    for (int i = 0; i < strData.length(); i++)
    {
        if (strData[i] == ';')
        {
            icount++;
            i += 3;
        }
    }

    Prole prole = new role[icount / 2];
    do
    {
        istart = strData.find("id=", istart);
        if (istart == string::npos)
            break;
        iend = strData.find(";", istart + 3);
        prole[icount].id = strData.substr(istart + 3, iend - istart - 3);
        istart = iend + 1;
        istart = strData.find("exp=", istart);
        iend = strData.find(";", istart + 4);
        prole[icount++].exp = stoi(strData.substr(istart + 4, iend - istart - 4));

    } while(1);
}
