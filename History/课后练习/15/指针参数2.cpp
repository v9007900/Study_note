#include "Windows.h"

#include <iostream>
using namespace std;

struct Role
{
    int HP;  // 血量
    int MP;  // 魔法值
    int Atk; // 攻击力
};

// 定义初始血量、魔法值、攻击力的常量
const int INITIAL_USER_HP = 1600;
const int INITIAL_USER_MP = 100;
const int INITIAL_USER_ATK = 100;
const int INITIAL_MONSTER_HP = 1500;
const int INITIAL_MONSTER_MP = 100;
const int INITIAL_MONSTER_ATK = 100;

// 进行一次战斗，如果角色 user 或怪物 monster 被击败，则将 gameOver 设为 true
void DoBattle(Role& user, Role& monster, bool& gameOver)
{
    Sleep(500);
    cout << "角色" << user.HP << "----" << user.MP << "----" << user.Atk << endl;
    cout << "怪物" << monster.HP << "----" << monster.MP << "----" << monster.Atk << endl;

    // 把 monster 当做攻击者，user 当做被攻击者
    user.HP -= monster.Atk;
    // 把 user 当做攻击者，monster 当做被攻击者
    monster.HP -= user.Atk;

    if (user.HP <= 0)
    {
        // 如果角色 user 被击败，则输出 "角色死亡" 并将 gameOver 设为 true
        std::cout << "角色死亡";
        gameOver = true;
        return;
    }
    else if (monster.HP <= 0)
    {
        // 如果怪物 monster 被击败，则输出 "怪物死亡！" 并将 gameOver 设为 true
        std::cout << "怪物死亡！";
        gameOver = true;
        return;
    }
}

int main()
{
    // 初始化角色 user 和怪物 monster
    Role user{INITIAL_USER_HP, INITIAL_USER_MP, INITIAL_USER_ATK};
    Role monster{INITIAL_MONSTER_HP, INITIAL_MONSTER_MP, INITIAL_MONSTER_ATK};

    // 定义一个布尔类型的变量 gameOver，用来判断游戏是否结束
    bool gameOver = false;

    // 只要游戏没有结束，就继续循环
    while (!gameOver)
    {
        // 调用函数 DoBattle，进行一次战斗
        DoBattle(user, monster, gameOver);
    }
}