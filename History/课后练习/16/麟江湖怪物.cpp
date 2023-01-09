#include <iostream>
#include <ostream>
#include <windows.h>
#include <winnt.h> // 引用Windows API的头文件
using namespace std;

// 定义角色结构体
typedef struct Role
{
    char* Name; // 角色名称
    int HP;     // 角色生命值
    int Hp_Max; // 角色最大生命值
    int MP;     // 角色魔法值
    int Mp_Max; // 角色最大魔法值
    int LV{1};  // 角色等级
} *PROLE, ROLE; // 定义指针与结构体名称别名

// 计算字符串长度
int clen(const char* str_ptr)
{
    int i;
    for (i = 0; str_ptr[i]; i++)
        ;
    cout << i << endl;
    cout << "clen的str:" << &str_ptr << "----" << str_ptr << endl; // 获取这个指针的值和地址
    // 第一个str:0x61fdb0----一袋米要抗几楼

    return ++i;
}

// 分配字符串内存
char* cstr(const char*& str_ptr)
{
    int len = clen(str_ptr);
    char* strrt = new char[len];
    memcpy(strrt, str_ptr, len);
    cout << "cstr的str:" << &str_ptr << "----" << str_ptr << endl; // 获取这个指针的值和地址
    // 第二个str:0x61fdf0----一袋米要抗几楼
    return strrt;
}

// 创建怪物角色
// str - 怪物的名字
// HP - 怪物的生命值
// MP - 怪物的魔法值
Role& CreateMonster(const char* str, int HP, int MP)
{
    // 使用 new 关键字分配内存，并创建一个 PROLE 类型的指针
    // 在这里，PROLE 指向一个 ROLE 类型的指针
    PROLE rt = new ROLE{cstr(str), HP, HP, MP, MP, 1};
    cout << "第三个str:" << &rt << "----" << rt << endl;
    //  返回 PROLE 指针
    return *rt;
}

int main()
{
    // char* str;
    //  创建一个 PROLE 类型的指针，并通过 CreateMonster 函数返回
    ROLE& role = CreateMonster("一袋米要抗二楼", 1500, 1500);
    cout << "main入口1:" << &role << "----" << &role << endl; // 获取这个指针的值和地址

    // 通过 . 访问 PROLE 指针指向的 ROLE 类型的成员
    cout << role.Name << endl;
    cout << role.HP << "/" << role.Hp_Max << endl;
    cout << role.MP << "/" << role.Mp_Max << endl;
}
