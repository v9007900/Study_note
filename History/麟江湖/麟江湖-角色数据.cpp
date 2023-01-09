#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

enum class Sect : char // 枚举  门派  数据范围【-127~128】
{
    Wudang,    // 武当  数据范围【-127~128】
    MountEmei, // 峨眉  数据范围【-127~128】
    Edoyun,    // 易云  数据范围【-127~128】
    Sunflower, // 葵花  数据范围【-127~128】
    TangClan,  // 唐门  数据范围【-127~128】
};

struct Equipment // 结构体 装备
{
    unsigned char LV{0}; // 等级  数据范围0~255
    unsigned char EV{0}; // 强化  数据范围0~255
};

struct ATTRIBMAX // 属性上限
{
    int value{500};          // 当前数值  数据范围-2147483648~2147483647
    unsigned maxvalue{1000}; // 数值上限  数据范围 0~4294967295
    // 单独用unsigned 表示unsigned int 能存储的数据范围是0~4294967295
};

struct Role // 结构体 角色
{

    unsigned char LV{10};       // 人物等级   数据范围0~255
    Sect Sects{Sect::TangClan}; // 结构体 门派  门派选择  唐门
    Equipment Arms{9, 15};      // 武器   用英文,分割
    Equipment Armor{8, 13};     // 护甲   用英文,分割
    Equipment Jewelr{11, 12};   // 首饰   用英文,分割
    long long exp{4515514};     // 经验值
    ATTRIBMAX HP{800, 1000};    // 结构体 属性上限   HP 当前血量 最大血量
    ATTRIBMAX MP{200, 1000};    // 结构体 属性上限   MP 当前蓝量 最大蓝量

    unsigned Money{1000};  // 金币
    unsigned Diamond{500}; // 钻石
    unsigned char luck{6}; // 幸运值
    unsigned vip_exp{20};  // 累计消费

    double X{124};
    double y{545};
    double Z{654};
};

int main()
{
    system("mode con cols=40 lines=20");
    system("color 8E");
    Role Lead; // 结构体-角色 主角
    cout << "等级:" << (int)Lead.LV << endl;
    cout << "门派" << (int)Lead.Sects << endl;
    cout << "武器:" << (int)Lead.Arms.LV << "阶"
         << "强化:+" << (int)Lead.Arms.EV << endl;
    cout << "护甲:" << (int)Lead.Armor.LV << "阶"
         << "强化:+" << (int)Lead.Armor.EV << endl;
    cout << "首饰:" << (int)Lead.Jewelr.LV << "阶"
         << "强化:+" << (int)Lead.Jewelr.EV << endl;
    cout << "经验值:" << Lead.exp << endl;
    cout << "生命:[" << Lead.HP.value << "/" << Lead.HP.maxvalue << "]" << endl;
    cout << "内力:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "内力:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "内力:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "X坐标:" << (int)Lead.X << "  Y坐标:" << Lead.y << "  Z坐标:" << Lead.Z << endl;
    cout << "金币:" << Lead.Money << endl;
    cout << "钻石:" << Lead.Diamond << endl;
    cout << "幸运值:" << (int)Lead.luck << endl;
    cout << "累计消费:" << Lead.vip_exp << endl;
    return 0;
}
