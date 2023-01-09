#include <iostream>
#include <windows.h>
using namespace std;

struct Role
{
    int HP;  // 血量
    int MP;  // 魔法值
    int Atk; // 攻击力
};

int Exp(const Role* rl)
{
    // 计算传入角色的经验值
    return rl->HP + rl->MP;
}

int Add(int* x, int* y)
{
    // 为两个整型指针指向的值乘上不同的倍数，并返回两个数的和
    (*x) *= 100;
    (*y) *= 10;
    return (*x) + (*y);
}

bool Act(Role* acter, Role* beacter)
{
    // 模拟两个角色的战斗
    // acter 对 beacter 进行攻击，减少 beacter 的血量
    beacter->HP -= acter->Atk;
    // 返回 beacter 是否被击败
    return beacter->HP <= 0;
}

int main()
{
    int x = 2, y = 1;
    int c = Add(&x, &y);

    Role rl{500, 1250};
    c = Exp(&rl);
    cout << "HP=" << rl.HP << endl;

    Role user{1500, 100, 100};
    Role monster{1500, 100, 100};

    // 定义一个布尔类型的变量 gameOver，用来判断游戏是否结束
    bool gameOver = false;

    // 只要游戏没有结束，就继续循环
    while (!gameOver)
    {
        cout << "角色" << user.HP << "----" << user.MP << "----" << user.Atk << endl;
        cout << "怪物" << monster.HP << "----" << monster.MP << "----" << monster.Atk << endl;

        // 调用函数 Act，把 monster 当做攻击者，user 当做被攻击者
        if (Act(&monster, &user))
        {
            // 如果角色 user 被击败，则输出 "角色死亡" 并将 gameOver 设为 true
            cout << "角色死亡";
            gameOver = true;
        }
        // 调用函数 Act，把 user 当做攻击者，monster 当做被攻击者
        else if (Act(&user, &monster))
        {
            // 如果怪物 monster 被击败，则输出 "怪物死亡！" 并将 gameOver 设为 true
            cout << "怪物死亡！";
            gameOver = true;
        }
    }
}