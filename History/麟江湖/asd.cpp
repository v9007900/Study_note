#include <conio.h>
#include <iostream>
#include <stdio.h>
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
    int HP;    // 基础HP
    int MaxHP; // 最大血量
    int MP;    // 基础MP
    int MaxMP; // 最大蓝量
    int ATK;   // 攻击力
    int PAks;  // 禁止攻击
    int Rbuff; // 回合
    bool cant; // 限制器
};
struct Skill // 技能
{
    int Cure;      // 消耗 100 内力恢复最大生命值的10%
    int VajraPalm; // 消耗  50 内力对远程目标造成基础攻击+50点伤害
    int Paralyze;  // 消耗  50 内力静止目标攻击3个回合
    int EGAk;  // 消耗  50 10个回合内，对目标造成伤害将恢复伤害量20%的内力 伤害量60%的生命
    int BSFTD; // 耗 100 内力对目标造成基础攻击力+已损失血量的伤害
    int TCCl;  // 消耗  50 300内力 使内力和生命值互换 攻击力提高1000%
};
int main()
{
    Roles roles[2]{{3000, 3000, 2000, 2000, 50, 0, 0, 1},  // 主角
                   {3000, 3000, 2000, 2000, 50, 0, 0, 1}}; // roles[1]

    Skill Skills[6]{{300, 0, 100, 0, 0, 0}, /*治愈术       Cure hp-maxhp-mp-maxmp-禁止攻击-回合-限制器*/
                    {0, 0, 50, 0, 50, 0},   /*金刚掌       Paralyze*/
                    {0, 0, 50, 0, 0, 3},    /*麻痹术       Paralyze*/
                    {0, 0, 50, 0, 0, 0},    /*鹰抓攻       EGAk*/
                    {0, 0, 100, 0, 0, 0},   /*绝处逢生     BSFTD*/
                    {0, 0, 50, 0, 0, 0}};   /*易筋经       TCCl*/

    char inKey = _getch(45);
    /* int *ptra{(int *)&roles[0]};  // 0x61fdc0
    int *ptrb{(int *)&Skills[0]}; // 0x61fd30 */

    do
    {

        /* printf("\n\n\t\t生命[ %d / %d ]\t\tboss生命[ %d / %d ]", roles[0].HP, roles[0].MaxHP, roles[1].HP,
        roles[1].MaxHP); printf("\n\t\t内力[ %d / %d ]\t\tboss内力[ %d / %d ]", roles[0].MP, roles[0].MaxMP,
        roles[1].MP, roles[1].MaxMP); printf("\n\t\t攻击力[ %d ]\t\t\tboss攻击力[ %d ]", roles[0].ATK, roles[1].ATK); */

        if (inKey > 57 && inkey < 48)
        {
            if (inkey == 47 && roles[0].HP < 90)
            {
                roles[0].HP += Skills[0].Cure;
                roles[0].MP -= Skills[0].Cure;
            }
        }

        cout << roles[0].MP;
    } while (true);
}
