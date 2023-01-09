#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

class Role
{
  public:
    int HP{};
    int MP{};

    Role() = default; ////Ĭ�Ϲ��캯��

    Role(int _HP, int _MP) : HP{_HP}, MP{_MP}
    {
    }

    Role(int _HP, int _MP) //// ��ʼ�� �� 2
    {
        HP = _HP;
        MP = _MP;
    }
    Role(Role& r) //// ��ʼ�� �� 3
    {
        HP = r.HP;
        MP = r.MP;
    }

    int Getlv() const;    //!!  ��ȡ˽�к���
    void Setlv(int* _lv); //??   д��˽�к���
  private:
    int lv;
};

int Role::Getlv() const //!!��ȡ ˽������ı���
{
    return lv;
}

void Role::Setlv(int* _lv) //??  ��˽������ д��ֵ
{
    lv = *_lv;
    cout << "_lv��ַ" << _lv << endl;
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

    lv2.HP = 5000; ////��ʼ�� 5000
    Role lv1{lv2}; ////��ʼ�� lv2

    int aa = 6000;  ////��ʼ��6000
    lv2.Setlv(&aa); ////���� aa ��ַ
    cout << "aa��ַ" << &aa << endl;
    cout << lv1.HP << "----" << lv2.Getlv();
    cout << endl << setfill('=') << setw(30) << '=' << endl;
    cout << "lv1 HP:" << lv1.HP << "lv1 MP:" << lv1.MP << endl;
    cout << "lv2 HP:" << lv2.HP << "lv2 MP:" << lv2.MP << endl;
    cout << "lv1 lv:" << lv1.Getlv() << "lv2 lv:" << lv2.Getlv();
}
