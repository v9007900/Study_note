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
    bool Act(Role* beacter)
    {
        cout << "bool beacter----" << beacter << endl; ////  0xbf265ffa60
        beacter->HP -= ATK;
        cout << &beacter->HP << endl; ////  0xbf265ffa60
        return beacter->HP > 0;
    }
    Role* Axx(Role* HP);
    ////Role 指针 指向HP 接收到zss的地址    2

  private:
};
Role* Role::Axx(Role* HPP) //// 定义在 class 里的函数
{
    ////Role 将指针Axx 定义在Role 里面    1
    //// 返回 接收地址的HP 大于 HP的话 返回 HPP 自己，不大于的话，this
    return HPP->HP > HP ? HPP : this;
    ////  HPP指向的是zss的HP地址  this 是传递着的HP地址
}

int main()
{
    Role npc{800, 500, 120, 6000, 200};
    Role zss{1000, 1000, 59, 1000, 200};
    Role lss{1000, 1000, 59, 1000, 200};
    zss.Act(&lss); // 将lss 地址传递给zss.Act

    Role* stdd = npc.Axx(&zss);
    ////Role 定义一个指针 stdd 指向npc.(传递zss的地址)
    ////将NPC 和  zss的血量传递过去比较

    cout << lss.HP;
    cout << endl << sizeof(npc);
    cout << endl << sizeof(Role);
    cout << endl << stdd << "----" << &npc.HP << endl;
    cout << &npc.HP;
}
