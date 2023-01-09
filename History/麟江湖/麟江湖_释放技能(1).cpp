#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

/*
内力[1000\1000] 最高生命[3000\3000] 基础攻击力[50]
1,  治愈        消耗 100 内力恢复最大生命值的10%
2,  金刚掌      消耗  50 内力对远程目标造成基础攻击+50点伤害
3,  麻痹术      消耗  50 内力进制目标攻击3个回合
4,  鹰抓攻      消耗  50 10个回合内，对目标造成伤害将恢复伤害量20%的内力 伤害量60%的生命
5,  绝处逢生    消耗 100 内力对目标造成基础攻击力+已损失血量的伤害
6,  易筋经      消耗  50 300内力 使内力和生命值互换 攻击力提高1000%
*/
struct Roles // 角色数据
{
    int HP{};      // 基础血量
    int MaxHP{};   // 最大血量
    int MP{};      // 内力值
    int MaxMP{};   // 最大内力值
    int ATK{};     // 攻击力
    int cantact{}; // 禁止攻击
    int buff{};    // 回合
    bool cant;     // 限制技
};

int main()
{
    Roles Lead{3000, 3000, 1000, 1000, 50};
    Roles boss{30000, 30000, 500, 500, 50};
    int inKey, damage; // inKey =  获取键盘按下的 ACll码

huilai:
    system("cls");
    printf("\n\n\t\t生命[ %d / %d ]\t\tBOSS生命[ %d / %d ]", Lead.HP, Lead.MaxHP, boss.HP, boss.MaxHP);
    printf("\n\t\t内力[ %d / %d ]\t\tBOSS内力[ %d / %d ]", Lead.MP, Lead.MaxMP, boss.MP, boss.MaxMP);
    printf("\n\t\t攻击力[ %d ]\t\t\tBOSS攻击力[ %d ]", Lead.ATK, boss.ATK);
    cout << "\n\t\tBUFF:" << Lead.buff;

    inKey = _getch();
    damage = 0;

    switch (inKey)
    {
    case 49: // 1  治愈        消耗 100 内力恢复最大生命值的10%
        if (Lead.MP > 99)
        {
            Lead.MP -= 100; // 当前内力值 -100
            Lead.HP += 300; // 当前血量值 +300
            Lead.HP = Lead.HP > Lead.MaxHP ? Lead.MaxHP : Lead.HP;
            // 当前血量 大于等于 最大血量 ? 大于返回最大血量，不大于返回基础血量
        }
        break; // 跳到末尾
    case 50:   // 2  金刚掌      消耗  50 内力对远程目标造成基础攻击+50点伤害
        if (Lead.MP >= 50)
        {
            Lead.MP -= 50;
            damage = 50 + Lead.ATK;
        }
        break;
    case 51: // 3  麻痹术      消耗  50 内力进制目标攻击3个回合
        if (Lead.MP >= 50)
        {
            Lead.MP -= 50;
            boss.cantact = 3;
        }
        break;
    case 52: // 4  鹰抓攻      消耗  50 10个回合内，对目标造成伤害将恢复伤害量20%的内力 伤害量60%的生命
        Lead.buff = 10;
        break;
    case 53: // 5  绝处逢生    消耗 100 内力对目标造成基础攻击力+已损失血量的伤害
        if (Lead.MP >= 100)
        {
            Lead.MP -= 100;
            damage = (Lead.MaxHP - Lead.HP) + Lead.ATK;
        }
        break;
    case 54: // 6  易筋经      消耗  50 300内力 使内力和生命值互换 攻击力提高1000%
        if ((Lead.MP >= 300) && (Lead.cant == true))
        {
            int ls = Lead.MaxHP;
            Lead.MaxHP = Lead.MaxMP;
            Lead.MaxMP = ls;
            ls = Lead.HP;
            Lead.HP = Lead.MP;
            Lead.MP = ls;
            Lead.ATK *= 10;
            Lead.cant = false;
        }
        break;
    default:
        break;
    }

    if (boss.cantact > 0)
    {
        boss.cantact--;
    }
    else
        Lead.HP -= boss.ATK;

    boss.HP -= damage;
    if (Lead.buff > 0)
    {
        Lead.buff--;
        Lead.HP += damage * 0.6;
        Lead.MP += damage * 0.2;
        Lead.HP = Lead.HP > Lead.MaxHP ? Lead.MaxHP : Lead.HP;
        Lead.MP = Lead.MP > Lead.MaxMP ? Lead.MaxMP : Lead.MP;
    }
    if (Lead.HP < 1)
    {
        system("cls");
        cout << "游戏失败";
        system("break");
    }
    else if (boss.HP < 1)
    {
        system("cls");
        cout << "游戏胜利";
        system("break");
    }

    goto huilai;
}