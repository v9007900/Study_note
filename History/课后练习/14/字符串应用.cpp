#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    string stra{"id=user;pass=632105;role=��Ӣ��"};
    string strin;
    string strout; while (1)
    {
        cout << "������Ҫ���ĵ�����:\n";
        cin >> strin;
        int finds = stra.find(strin+"=");
        if (finds == string::npos)
        {
            cout<<"���ĵĲ�����";
        }
        else
        {
            int lend = stra.find(";",finds);
            strout = stra.substr(finds + strin.length() + 1, lend - finds - strin.length() - 1);
            cout << strout << endl;
        }
    }
}
