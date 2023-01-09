#include <iostream>
#include <iterator>
#include <minwindef.h>
#include <ostream>
#include <windows.h>
using namespace std;

class Role
{
  public:
    int HP{}; //// HP 是首地址  0xbf265ffa60
    int MP{};
    int ATK{};     //// ATK
    int price{};   ////价钱
    int diamond{}; ////钻石
    Role& SetHP(int newHP);
    Role& SetMP(int newmp);
    Role& SetATK(int newATK);
};

Role& Role::SetHP(int newHP)
{
    HP = newHP;
    cout << "this 内" << &HP << "----" << &newHP << endl;
    cout << "this地址" << this << endl;
    return *this;
    ////带*  表示这个地址的值  不带* 表示这个地址
    ////this 地址0xe232dffc50
    ////HP   地址0xe232dffc50
    ////newHP地址0xe232dffc18
    ////传递过来的是eva HP的地址 HP
    ////在函数内的HP，是调用者本身的HP
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

    // todo 将eva的HP 2000  传递过去
    // todo 函数接收到 200 后 eva.HP = newHP  并将这个地址返回给 eva
    eva.SetATK(100).SetHP(2000).SetMP(40000);
    //??  this 指向 的地址 是调用者 本身的地址

    cout << eva.HP << "----" << eva.MP << "----" << eva.ATK << endl;
    cout << &eva.HP << "----" << &eva.MP << "----" << &eva.ATK << endl;
}
