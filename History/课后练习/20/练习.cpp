#include <fstream>
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

// 定义类  角色类、
class Role
{
  private: // 私有,禁止随意读写
    // ID 名字  可读 可写
    string Name{};
    // 等级     可读 可写
    unsigned short LV{}; // short 双字节  65535
    // 血量     可读 不可写
    int HP{};
    // 蓝量     可读 不可写
    int MP{};
    // 攻击力   可读 不可写
    int ATK{};

  public:                       // 给与访问接口
    Role& SetName(string _Name) // 写入 ID
    {
        Name = _Name;
        return *this;
    }

    Role& SetLv(unsigned short _LV) // 写入等级
    {
        if (_LV < 0 || _LV >= 3) // 判断写入是否正常
        {
            cout << "检测到非法修改";
            return *this;
        }
        LV += _LV;
        return *this;
    }

    // 上面是写入部分

    void ReadAll(); // 读取全部信息

    int GetHP() // 读取HP
    {
        return HP;
    }

    // 攻击部分
    bool ATkk(Role* _Atk)
    {
        _Atk->HP -= ATK;
        return _Atk->HP > 0;
    }
};

void Role::ReadAll() // 读取全部信息
{
    cout << "ID:" << Name << endl;
    cout << "等级:" << LV << endl;
    HP = LV * 5;
    cout << "血量:" << HP << endl;
    MP = LV * 125;
    cout << "蓝条:" << MP << endl;
    ATK = LV * 10;
    cout << "攻击:" << ATK << endl;
}

int main()
{
    Role role_1;
    Role role_2;

    for (int i = 0; i < 100; i++)
    {
        Sleep(5);
        system("cls");
        role_2.SetName("BOSS1").SetLv(1);
        role_1.SetName("BOSS2").SetLv(1);
        role_1.ReadAll();
        role_2.ReadAll();
    }
    role_1.ATkk(&role_2);

    // cout << role_2.GetHP();

    if (role_1.GetHP() <= 0)
    {
        cout << "获胜";
    }
    else
    {
        cout << "战败";
    }
}
