#include <iostream>
#include <iterator>
#include <minwindef.h>
#include <ostream>
#include <windows.h>
using namespace std;

class crole
{
  public:
    int HP{}; //// HP ���׵�ַ  0xbf265ffa60
    int MP{};
    int ATK{};     //// ATK
    int price{};   ////��Ǯ
    int diamond{}; ////��ʯ
    bool Act(crole* beacter)
    {
        cout << "bool beacter----" << beacter << endl; ////  0xbf265ffa60
        beacter->HP -= ATK;
        cout << &beacter->HP << endl; ////  0xbf265ffa60
        return beacter->HP > 0;
    }

  private:
};

int main()
{
    crole npc{1200, 500, 120, 6000, 200};
    crole zss{1000, 1000, 59, 1000, 200};
    crole lss{1000, 1000, 59, 1000, 200};
    zss.Act(&lss); // ��lss ��ַ���ݸ�zss.Act
    cout << "lss-------------" << &lss << endl;
    cout << &npc.HP << "----" << &zss.HP << "----" << &lss.MP << "----" << &lss.HP << endl;
    ////MP�� HP ��� һ�� int  4
    ////NPC----0x852d9ff7b0----1968-32
    ////ZSS----0x852d9ff790----1936-32
    ////LSS----0x852d9ff770----1904-32

    int* add{&lss.HP};
    int s{0};
    for (int i = 0; i <= 32; i ++)
    {
        s++;
        cout << "��ַ:" << &add[i] << "----ֵ:" << add[i] << "----" << i << endl;
    }
}
