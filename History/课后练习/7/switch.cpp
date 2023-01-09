#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    unsigned int sid, spr;
    cin >> sid;
    switch (sid) //循环的值 要循环的指令
    {
    case 15692:    //需要满足的条件
        spr = 500; //满足条件后执行
        cout << "123";
        break; //满足条件，跳出括号，不在继续执行下方指令
    case 65421:
        spr = 450;
        break;
    case 96412:
        spr = 400;
        break;
    case 666:
        [[fallthrough]]; //加这个  不写 break 不会报错
    case 321:
        spr = sid * 2; //当需要执行的指令 相同时，并列一起即可
        break;
    default:     //如上方全部条件未满足，继续往下执行
        spr = 0; // 上方全部条件未满足 spr = 0  下方if判断spr=0不显示
        cout << "未中奖" << char(10);

    } //如 上方满足其一，执行括号外的指令

    if (spr) //判断 =1 执行  =0不执行
        cout << "获得奖金:" << spr << "日元";

    return 0;
}