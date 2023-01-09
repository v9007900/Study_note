#include <iostream>
#include <windows.h>
using namespace std;

struct Role
{
    char Name[0x20]; // 存储角色名称
    int hp;          // 存储角色血量
    int mp;          // 存储角色魔法值
    int damage;      // 存储角色攻击力
};

// 执行攻击行为
// 参数 Acter 是行动的角色
// 参数 beact 是被攻击的角色
// 返回值是被攻击者是否死亡
bool Act(const Role& Acter, Role*& beact)
{
    beact->hp -= Acter.damage; // 减少被攻击者的血量
    bool bend = beact->hp < 0; // 判断被攻击者是否死亡
    beact = (Role*)&Acter;     // 如果死亡，则更新指针
    cout << "beact:" << beact << endl;
    return bend;
}

int main()
{
    Role user{"小怪兽", 200, 300, 850};   // 定义一个角色，并初始化
    Role monster{"大怪兽", 800, 900, 50}; // 定义一个角色，并初始化

    Role* ptr = &monster; // 定义一个指针，并指向 monster
    int beact;
    if (Act(user, ptr)) // 如果攻击成功
        cout << ptr->Name << (char)10 << "怪物死亡" << endl;
    // 输出怪物名称和死亡信息
    cout << ptr << "----" << &ptr << endl;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "monster: " << &monster << endl;
}

