#include <iostream>
#include <windows.h>
struct Role
{
    int bdz[4];      //��֪��
    int HP[2];       //����ֵ
    int PS[2];       //����ֵ
    int MP[2];       //ħ��ֵ
    int ATK;         //������
    int DEF;         //������
    int SF;          //��
    int LV;          //�ȼ�
    int BDZ_1;       //��֪��
    int EXP[2];      //��֪��
    int MS;          //����
    int STAT;        //״̬
    int DIR;         //����
    int BDZ_2[2];    //��֪��
    int X;           // X����
    int Y;           // Y����
    int BDZ_3[36];   //��֪��
    char Name[0x20]; //��ɫ����
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
    std::cout << "��������Ϸ����ID:" << 23676;
    std::cin >> pid;
    hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); // �õ����̾����PAA=��ȡ����ȡȨ��
    if (hprocess)
    {
        while (1)
        {
            if (ReadRole(0x4CEF08, &user))
            {
                system("cls");
                std::cout << "��ɫ����[" << user.Name << "]" << std::endl;
                std::cout << "��ɫ�ȼ�[" << user.LV << "]" << std::endl;
                std::cout << "��ɫ����[" << user.EXP[0] << "/" << user.EXP[1] << "]" << std::endl;
                std::cout << "��ɫ����[" << user.HP[0] << "/" << user.HP[1] << "]" << std::endl;
                std::cout << "��ɫ����[" << user.PS[0] << "/" << user.PS[1] << "]" << std::endl;
                std::cout << "��ɫ����[" << user.MP[0] << "/" << user.MP[1] << "]" << std::endl;
                std::cout << "��ɫ����[" << user.ATK << "]" << std::endl;
                std::cout << "��ɫ����[" << user.DEF << "]" << std::endl;
                std::cout << "��ɫ��[" << user.SF << "]" << std::endl;
                std::cout << "��ɫ����[" << user.MS << "]" << std::endl;
                std::cout << "��ɫ״̬[" << user.STAT << "]" << std::endl;
                std::cout << "��ɫ����[" << user.DIR << "]" << std::endl;
                std::cout << "��ɫX����[" << user.X << "]" << std::endl;
                std::cout << "��ɫY����[" << user.Y << "]" << std::endl;
                Sleep(500);
                int HP = 99999;
                size_t hasWrite;
                WriteProcessMemory(hprocess, (LPVOID)(0x4CEF18, 0x4CEF1C), &HP, sizeof(HP), NULL);
            }
            else
            {
                std::cout << "��Ϸ�ڴ��ȡʧ�ܣ�";
                break;
            }
        }
    }
    else
    {
        std::cout << "���ù���Ա���б�����";
        goto linput;
    }
}