#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    unsigned long long Account, Pass;
    cout << "�뽭�� ��Ϸע��\n\n�������˺�:";
    cin >> hex >> Account;
    cout << "��������:";
    cin >> Pass;

    if ((Account > 0xfffff) && (Pass > 0xfffff))
    {
        unsigned long long Ver1, Ver2;
        cout << "��¼��Ϸ\n\n�˺�:";
        cin >> Ver1; // ��֤1
        cout << "����:";
        cin >> Ver2; // ��֤2
        if ((Ver1 == Account) && (Ver2 == Pass))
        {
            cout << "��¼�ɹ�";
        }
        else
            cout << "�˺Ż��������";
    }
    else
        cout << "ע��ʧ�ܣ��˺Ż����벻����λ";

    return 0;
}
