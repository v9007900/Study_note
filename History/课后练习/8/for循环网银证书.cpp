#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    // system("mode con cols=40 lines=10");
    // system("color 8E");
    int Pass1{0}, Pass2{0};

    cout << "��������:";
    cin >> Pass1;
    cout << "ȷ������:";
    cin >> Pass2;
    if (Pass1 == Pass2)
    {
        cout << "������ȷ,\n��������������ƽ�...\n";
        system("cls");
        _getch();

        for (int i = 0; i < 999999; i++)
        {
            if (i != Pass2)
            {
                cout << i << endl;
            }
            else
            {
                cout << "�ƽ�ɹ���������:" << i << endl;
                goto mima;
            }
        }
    }
    else
    {
        cout << "����������������롣";
    }
mima:
    return 0;
}
