#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int Pass1{0}, Pass2{0};

congxin:
    cout << "��������:";
    cin >> Pass1;
    cout << "ȷ������:";
    cin >> Pass2;

    if (int Crack{0}; Pass1 == Pass2)
    {
        cout << "������ȷ,\n��������������ƽ�...\n";
        system("cls");
        _getch();
    kaishi:
        if (Crack != Pass1)
        {
            Crack++;
            printf("�ƽ����%d\n", Crack);
            goto kaishi;
        }
        else
        {
            cout << "�����ƽ�ɹ�:" << Crack << endl;
            goto congxin;
        }
    }
    else
    {
        cout << "����������������롣";
    }
    return 0;
}
