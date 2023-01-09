#include <iostream>
#include <windows.h>
#include <wingdi.h>
using namespace std;

class Drug // 药
{
  public:
    int Recover{100};
};
class Role // 角色类
{
  public: // 类 初始化列表
    int HP;
    int maxHP;

  public:
    Role()
    {
        HP = 1000;
        maxHP = 2500;
    }

    void GetHp()
    {
        cout << "HP:" << HP << "\\" << maxHP << endl;
    }
    void EatMed(Drug& hpMed)
    {
        HP += hpMed.Recover;
        HP = HP > maxHP ? maxHP : HP;
    }
};

int main()
{
    Role user;
    Drug med;
    while (1)
    {
        int a;
        cin >> a;
        user.GetHp();     // 读HP
        user.EatMed(med); // 吃药动作
        user.GetHp();     // 读HP
    }
}
