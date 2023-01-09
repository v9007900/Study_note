#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

class Role
{
  public:
    int HP{};
    int MP{};

    Role() = default; ////默认构造函数

    Role(int _HP, int _MP) : HP{_HP}, MP{_MP}
    {
    }

    Role(int _HP, int _MP) //// 初始化 类 2
    {
        HP = _HP;
        MP = _MP;
    }
    Role(Role& r) //// 初始化 类 3
    {
        HP = r.HP;
        MP = r.MP;
    }

    int Getlv() const;    //!!  读取私有函数
    void Setlv(int* _lv); //??   写入私有函数
  private:
    int lv;
};

int Role::Getlv() const //!!读取 私有区域的变量
{
    return lv;
}

void Role::Setlv(int* _lv) //??  给私有区域 写入值
{
    lv = *_lv;
    cout << "_lv地址" << _lv << endl;
}

int main()
{
    Role role{100, 100};
    Role lv2{200, 200};
    Role lv3{300, 300}; ////3500  1500
    Role lv4(Role as);

    cout << lv3.HP << "----" << lv3.MP << endl;
    cout << lv2.HP << "----" << lv2.MP << endl;
    cout << role.HP << "----" << role.MP << endl;

    cout << endl << setfill('=') << setw(30) << '=' << endl;

    lv2.HP = 5000; ////初始化 5000
    Role lv1{lv2}; ////初始化 lv2

    int aa = 6000;  ////初始化6000
    lv2.Setlv(&aa); ////传递 aa 地址
    cout << "aa地址" << &aa << endl;
    cout << lv1.HP << "----" << lv2.Getlv();
    cout << endl << setfill('=') << setw(30) << '=' << endl;
    cout << "lv1 HP:" << lv1.HP << "lv1 MP:" << lv1.MP << endl;
    cout << "lv2 HP:" << lv2.HP << "lv2 MP:" << lv2.MP << endl;
    cout << "lv1 lv:" << lv1.Getlv() << "lv2 lv:" << lv2.Getlv();
}
