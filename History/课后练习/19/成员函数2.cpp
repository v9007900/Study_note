#include <iostream>
#include <iterator>
#include <minwindef.h>
#include <ostream>
#include <windows.h>
using namespace std;

class Role
{
  public:
    int HP{}; //// HP ���׵�ַ  0xbf265ffa60
    int MP{};
    int ATK{};     //// ATK
    int price{};   ////��Ǯ
    int diamond{}; ////��ʯ
    Role& SetHP(int newHP);
    Role& SetMP(int newmp);
    Role& SetATK(int newATK);
};

Role& Role::SetHP(int newHP)
{
    HP = newHP;
    cout << "this ��" << &HP << "----" << &newHP << endl;
    cout << "this��ַ" << this << endl;
    return *this;
    ////��*  ��ʾ�����ַ��ֵ  ����* ��ʾ�����ַ
    ////this ��ַ0xe232dffc50
    ////HP   ��ַ0xe232dffc50
    ////newHP��ַ0xe232dffc18
    ////���ݹ�������eva HP�ĵ�ַ HP
    ////�ں����ڵ�HP���ǵ����߱����HP
}

Role& Role::SetMP(int newMP)
{
    MP = newMP;
    return *this;
}
Role& Role::SetATK(int newATK)
{

    ATK = newATK;
    return *this;
}

int main()
{
    int a = 200;
    int* p = &a;
    int& c = *p;
    // cout << c << endl;
    // cout << &c << "--" << &p << "--" << &a << endl;

    Role npc{800, 500, 120, 6000, 200};
    Role eva{1000, 1000, 59, 1000, 200};
    Role dve{1000, 1000, 59, 1000, 200};

    // todo ��eva��HP 2000  ���ݹ�ȥ
    // todo �������յ� 200 �� eva.HP = newHP  ���������ַ���ظ� eva
    eva.SetATK(100).SetHP(2000).SetMP(40000);
    //??  this ָ�� �ĵ�ַ �ǵ����� ����ĵ�ַ

    cout << eva.HP << "----" << eva.MP << "----" << eva.ATK << endl;
    cout << &eva.HP << "----" << &eva.MP << "----" << &eva.ATK << endl;
}
