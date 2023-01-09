#include <fstream>
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

// ������  ��ɫ�ࡢ
class Role
{
  private: // ˽��,��ֹ�����д
    // ID ����  �ɶ� ��д
    string Name{};
    // �ȼ�     �ɶ� ��д
    unsigned short LV{}; // short ˫�ֽ�  65535
    // Ѫ��     �ɶ� ����д
    int HP{};
    // ����     �ɶ� ����д
    int MP{};
    // ������   �ɶ� ����д
    int ATK{};

  public:                       // ������ʽӿ�
    Role& SetName(string _Name) // д�� ID
    {
        Name = _Name;
        return *this;
    }

    Role& SetLv(unsigned short _LV) // д��ȼ�
    {
        if (_LV < 0 || _LV >= 3) // �ж�д���Ƿ�����
        {
            cout << "��⵽�Ƿ��޸�";
            return *this;
        }
        LV += _LV;
        return *this;
    }

    // ������д�벿��

    void ReadAll(); // ��ȡȫ����Ϣ

    int GetHP() // ��ȡHP
    {
        return HP;
    }

    // ��������
    bool ATkk(Role* _Atk)
    {
        _Atk->HP -= ATK;
        return _Atk->HP > 0;
    }
};

void Role::ReadAll() // ��ȡȫ����Ϣ
{
    cout << "ID:" << Name << endl;
    cout << "�ȼ�:" << LV << endl;
    HP = LV * 5;
    cout << "Ѫ��:" << HP << endl;
    MP = LV * 125;
    cout << "����:" << MP << endl;
    ATK = LV * 10;
    cout << "����:" << ATK << endl;
}

int main()
{
    Role role_1;
    Role role_2;

    for (int i = 0; i < 100; i++)
    {
        Sleep(5);
        system("cls");
        role_2.SetName("BOSS1").SetLv(1);
        role_1.SetName("BOSS2").SetLv(1);
        role_1.ReadAll();
        role_2.ReadAll();
    }
    role_1.ATkk(&role_2);

    // cout << role_2.GetHP();

    if (role_1.GetHP() <= 0)
    {
        cout << "��ʤ";
    }
    else
    {
        cout << "ս��";
    }
}
