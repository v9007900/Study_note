#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int Pass1, Pass2, Pass3{-1};

    /* while (Pass1 != Pass2)
    {
        system("cls");
        cout << "��������:";
        cin >> Pass1;
        cin >> Pass2;
        cout << "ȷ������:";
    }

    cout << "��ʼִ���ƽ����" << endl;

    while (Pass2 != Pass3)
        Pass3++;

    cout << "�����ƽ�ɹ�" << Pass3; */

    do
    {
        system("cls");
        cout << "��������:";
        cin >> Pass1;
        cout << "ȷ������:";
        cin >> Pass2;
    } while (Pass1 != Pass2);

    do Pass3++;while (Pass2 != Pass3); cout << "�����ƽ�ɹ�" << Pass3;
}
