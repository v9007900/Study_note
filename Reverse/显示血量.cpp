#include <iostream>
#include <windows.h>
struct Role
{
    int bdz[4];      //不知道
    int HP[2];       //生命值
    int PS[2];       //体力值
    int MP[2];       //魔法值
    int ATK;         //攻击力
    int DEF;         //防御力
    int SF;          //身法
    int LV;          //等级
    int BDZ_1;       //不知道
    int EXP[2];      //不知道
    int MS;          //移速
    int STAT;        //状态
    int DIR;         //朝向
    int BDZ_2[2];    //不知道
    int X;           // X坐标
    int Y;           // Y坐标
    int BDZ_3[36];   //不知道
    char Name[0x20]; //角色名字
};
HANDLE hprocess;
BOOL ReadRole(unsigned address, Role *role)
{
    int value{};
    SIZE_T readByte{};
    BOOL bRet = ReadProcessMemory(hprocess, (LPCVOID)address, (LPVOID)role, sizeof(Role), &readByte);
    return bRet;
}
int main()
{
    DWORD pid;
    Role user;
linput:
    std::cout << "请输入游戏进程ID:" << 23676;
    std::cin >> pid;
    hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); // 得到进程句柄，PAA=获取最大读取权限
    if (hprocess)
    {
        while (1)
        {
            if (ReadRole(0x4CEF08, &user))
            {
                system("cls");
                std::cout << "角色姓名[" << user.Name << "]" << std::endl;
                std::cout << "角色等级[" << user.LV << "]" << std::endl;
                std::cout << "角色经验[" << user.EXP[0] << "/" << user.EXP[1] << "]" << std::endl;
                std::cout << "角色生命[" << user.HP[0] << "/" << user.HP[1] << "]" << std::endl;
                std::cout << "角色体力[" << user.PS[0] << "/" << user.PS[1] << "]" << std::endl;
                std::cout << "角色蓝条[" << user.MP[0] << "/" << user.MP[1] << "]" << std::endl;
                std::cout << "角色攻击[" << user.ATK << "]" << std::endl;
                std::cout << "角色防御[" << user.DEF << "]" << std::endl;
                std::cout << "角色身法[" << user.SF << "]" << std::endl;
                std::cout << "角色移速[" << user.MS << "]" << std::endl;
                std::cout << "角色状态[" << user.STAT << "]" << std::endl;
                std::cout << "角色朝向[" << user.DIR << "]" << std::endl;
                std::cout << "角色X坐标[" << user.X << "]" << std::endl;
                std::cout << "角色Y坐标[" << user.Y << "]" << std::endl;
                Sleep(500);
                int HP = 99999;
                size_t hasWrite;
                WriteProcessMemory(hprocess, (LPVOID)(0x4CEF18, 0x4CEF1C), &HP, sizeof(HP), NULL);
            }
            else
            {
                std::cout << "游戏内存读取失败！";
                break;
            }
        }
    }
    else
    {
        std::cout << "请用管理员运行本程序";
        goto linput;
    }
}