#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char vss; // a=97   A=65
    cout << "������ĸ:";
    cin >> vss;
    if (vss <= 122) //��� С��122 ���� ����122 �жϷ���
    {
        if (vss >= 48)
        {

            if (vss >= 58)
            {
                if (vss >= 65)
                {
                    if (vss >= 91)
                    {
                        if (vss >= 97)
                        {
                            char b = vss - 32;
                            cout << b;
                        }
                        else
                        {
                            cout << "������Ƿ���";
                        }
                    }
                    else
                    {
                        char b = vss + 32;
                        cout << b;
                    }
                }
                else
                {
                    cout << "������Ƿ���";
                }
            }
            else
            {
                cout << "�����������";
            }
        }
        if (vss < 47)
        {
            cout << "47";
        }
    }
    if (vss >= 123)
    {
        cout << "����";
    }
    return 0;
}
