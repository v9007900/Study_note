#include <iostream>
#include <windows.h>
#include <locale.h> //中文
using namespace std;

int main()
{
    /*  setlocale(LC_ALL,"chs");
        int x[0x10];
        char name[0x10];
        cout<<x<<(char)10<<name; */

    string aa = "&#xf011";
    char std[0xff];
    cin >> std;
    cout << strlen(std); //输出字符个数
}
