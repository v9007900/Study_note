#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    char inkey; //监控按下的是不是Yy
    int intin;  //输入的数
    cout << "输入一个数";
    cin >> intin; //键入 随机数
    bool bacse{}; //布尔值 bacse 真或假
    for (int i = 3; i <= sqrt(intin); i += 2)
        // 1~3 不是质数，从3开始循环
        // i小于等于 sqrt(求平方根) 如输入1000  10 10  intin = 10  i=3<=10  3+2=5=7=9  循环三次结束，
        if (intin % i == 0) // 1000 % i 3 5 7 9  = 0
        {
            bacse = true; // 0为真  bacse反转为1
            cout << "bacse=" << bacse << endl;
            break; //结束本次循环，到if
        }
    if (bacse) // 1 执行括号内  bareak 跳到这里
    {
        cout << "bacse2=" << bacse << endl;
        cout << "这个数不是质数\n"; // 1 跳到 cout
    }
    else // 0 执行else
    {
        cout << "这个是质数\n"; // 0 跳到cout
    }

    cout << "如果要进行下一次运算请按[Y] 按其它任意键推出程序\n";
    cin >> inkey;                        //判断按下
    while (inkey == 'Y' || inkey == 'y') //按下的是 Y 或者 y
    {
        int intin; //输入的数
        cout << "输入一个数:";
        cin >> intin;                                          //输入的数
        bool bcase{};                                          //布尔值 bacse 真或假
        bcase = (intin % 2 != 0);                              //判断 输入的值%2是否等于0 1000%2=0
        for (int i = 3; (bcase) && (i <= sqrt(intin)); i += 2) // i=3  bacse不等于0 切 i 小于等于  输入值的平方根   bcase成立才执行后面判断，不成立直接跳过，节约计算
            if (intin % i == 0)                                // 10%3=0  条件成立
            {
                bcase = false; // 1转换为0
                break;         //跳到 if
            }
        if (bcase) //判断 1 执行COUT 0 else
        {
            cout << "这个数是质数\n";
        }
        else
        {
            cout << "这个数不是质数\n";
        }

        cout << "如果要进行下一次运算，请按[Y] 按其它任意按键推出程序";
        cin >> inkey;
    }
}
