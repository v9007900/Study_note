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
    bool Act(Role* beacter)
    {
        cout << "bool beacter----" << beacter << endl; ////  0xbf265ffa60
        beacter->HP -= ATK;
        cout << &beacter->HP << endl; ////  0xbf265ffa60
        return beacter->HP > 0;
    }
    Role* Axx(Role* HP);
    ////Role ָ�� ָ��HP ���յ�zss�ĵ�ַ    2

  private:
};
Role* Role::Axx(Role* HPP) //// ������ class ��ĺ���
{
    ////Role ��ָ��Axx ������Role ����    1
    //// ���� ���յ�ַ��HP ���� HP�Ļ� ���� HPP �Լ��������ڵĻ���this
    return HPP->HP > HP ? HPP : this;
    ////  HPPָ�����zss��HP��ַ  this �Ǵ����ŵ�HP��ַ
}

int main()
{
    Role npc{800, 500, 120, 6000, 200};
    Role zss{1000, 1000, 59, 1000, 200};
    Role lss{1000, 1000, 59, 1000, 200};
    zss.Act(&lss); // ��lss ��ַ���ݸ�zss.Act

    Role* stdd = npc.Axx(&zss);
    ////Role ����һ��ָ�� stdd ָ��npc.(����zss�ĵ�ַ)
    ////��NPC ��  zss��Ѫ�����ݹ�ȥ�Ƚ�

    cout << lss.HP;
    cout << endl << sizeof(npc);
    cout << endl << sizeof(Role);
    cout << endl << stdd << "----" << &npc.HP << endl;
    cout << &npc.HP;
}
