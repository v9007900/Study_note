#include <iostream>
#include <windows.h>
#include <wingdi.h>
using namespace std;

class Drug // ҩ
{
  public:
    int Recover{100};
};
class Role // ��ɫ��
{
  public: // �� ��ʼ���б�
    int HP;
    int maxHP;

  public:
    Role()
    {
        HP = 1000;
        maxHP = 2500;
    }

    void GetHp()
    {
        cout << "HP:" << HP << "\\" << maxHP << endl;
    }
    void EatMed(Drug& hpMed)
    {
        HP += hpMed.Recover;
        HP = HP > maxHP ? maxHP : HP;
    }
};

int main()
{
    Role user;
    Drug med;
    while (1)
    {
        int a;
        cin >> a;
        user.GetHp();     // ��HP
        user.EatMed(med); // ��ҩ����
        user.GetHp();     // ��HP
    }
}
