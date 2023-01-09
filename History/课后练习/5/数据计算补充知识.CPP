#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    unsigned int Diamonds{6000};         //钻石
    unsigned int vip_exp{80000};         //消费
    unsigned xbase = Diamonds ^ vip_exp; //充值
    cout << "充值数量:" << xbase << endl;
    cout << "钻石数量:" << Diamonds << endl;
    cout << "消费数量:" << vip_exp << endl;

    cout << "修改钻石数量:";
    cin >> Diamonds;
    cout << "修改累计消费:";
    cin >> vip_exp;

    unsigned RealDiamond = xbase ^ vip_exp;
    unsigned RealvIpExp = xbase ^ RealDiamond;
    cout << "实际钻石数:" << RealDiamond << endl;
    cout << "实际消费是:" << RealvIpExp << endl;
    cout << "实际充值是:" << xbase << endl;

    return 0;
}
