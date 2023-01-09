#include <iostream>
#include <windows.h>
#include <bitset>
using namespace std;

// 控制1盏灯的情况 控制那盏灯  参数i为需要控制的是第几盏灯 参数default_dll_lamp 为当前灯光的情况
unsigned oneControlOpen(unsigned asaa, unsigned 灯光)
{
    // unsigned asaa{ 0b00000000000000000000000000001000 }; asaa参数示例
    灯光 |= asaa;

    return 灯光;
}
unsigned oneControlShut(unsigned asaa, unsigned 灯光)
{
    灯光 &= asaa;

    return 灯光;
}
// 1字节8位 我们控制灯光只有2中状态 刚刚好使用16进制数F 和0

int main()
{

    // 设定开灯为1 关灯为0
    // 使用 unsigned  防止位运算出现负数0补1的意外情况

    unsigned 灯光{0b00000000001000000000000000000000}; //默认灯光

    cout << "默认灯光状态：" << std::bitset<32>(灯光) << char(10);
    // unsigned all_lamp{ 0b11111111111111111111111111111111 };

    //------------------------Before 单个灯光控制------------------------
    灯光 = oneControlOpen(0b1000, 灯光);
    cout << "开灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);

    灯光 = oneControlShut(0b11111111111111111111111111110111, 灯光);
    cout << "关灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);
    //------------------------End 单个灯光控制------------------------

    //------------------------Before 区域灯光控制------------------------

    //区域开关灯 参数改为16进制
    灯光 = oneControlOpen(0xFF, 灯光);
    cout << "区域开灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);
    灯光 = oneControlShut(0xFFFFFF00, 灯光);
    cout << "区域关灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);
    //------------------------End 区域灯光控制------------------------

    //------------------------Before 全部灯光控制------------------------
    灯光 = oneControlOpen(0xFFFFFFFF, 灯光);
    cout << "全部开灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);

    灯光 = oneControlShut(0, 灯光);
    cout << "全部关灯操作-当前灯光状态：" << std::bitset<32>(灯光) << char(10);
    //------------------------End  全部灯光控制------------------------
}
