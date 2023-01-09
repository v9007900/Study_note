#include <iostream>
#include <ostream>
#include <windows.h>
#include <xmemory>
#include <xutility>
using namespace std;

class Role
{
  public:
    // 重载运算符 +
    Role operator+(Role& P);

    int HP;
    int MP;
};

Role Role::operator+(Role& P) // 重载运算符 +
{
    Role temp;
    temp.HP = this->HP + P.HP;
    temp.MP = this->MP + P.MP;
    cout << &temp << endl;
    return temp;
}

bool operator<(Role& P1, Role& P2)
{
    return P1.HP < P2.HP;
}

ostream& operator<<(ostream& cout, Role& P)
{
    cout << "HP:" << P.HP << "MP:" << P.MP;
    return cout;
}

void Add()
{
    Role p1;
    p1.HP = 15;
    p1.MP = 10;
    Role p2;
    p2.HP = 20;
    p2.MP = 15;

    Role p4 = p1.operator+(p2);
    Role p3 = p1 + p2;
    for (int i = 0; i < 10; i++)
    {
        cout << "P4-HP" << p4.HP << endl;
        cout << "P4-MP" << p4.MP << endl;
        cout << "P3-HP" << p3.HP << endl;
        cout << "P3-MP" << p3.MP << endl;
    }

    if (p1 < p2)
        cout << "是的 小于p2" << endl;
    else
        cout << "没有小于p2" << endl;
}
int main()
{
    Add();
    int* atc{(int*)Add};
    cout << atc << *atc << endl;
    Role p;
    p.HP = 100;
    p.MP = 1200;
    cout << p << endl << "2123" << endl;
}
