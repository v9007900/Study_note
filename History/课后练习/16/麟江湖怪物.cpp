#include <iostream>
#include <ostream>
#include <windows.h>
#include <winnt.h> // ����Windows API��ͷ�ļ�
using namespace std;

// �����ɫ�ṹ��
typedef struct Role
{
    char* Name; // ��ɫ����
    int HP;     // ��ɫ����ֵ
    int Hp_Max; // ��ɫ�������ֵ
    int MP;     // ��ɫħ��ֵ
    int Mp_Max; // ��ɫ���ħ��ֵ
    int LV{1};  // ��ɫ�ȼ�
} *PROLE, ROLE; // ����ָ����ṹ�����Ʊ���

// �����ַ�������
int clen(const char* str_ptr)
{
    int i;
    for (i = 0; str_ptr[i]; i++)
        ;
    cout << i << endl;
    cout << "clen��str:" << &str_ptr << "----" << str_ptr << endl; // ��ȡ���ָ���ֵ�͵�ַ
    // ��һ��str:0x61fdb0----һ����Ҫ����¥

    return ++i;
}

// �����ַ����ڴ�
char* cstr(const char*& str_ptr)
{
    int len = clen(str_ptr);
    char* strrt = new char[len];
    memcpy(strrt, str_ptr, len);
    cout << "cstr��str:" << &str_ptr << "----" << str_ptr << endl; // ��ȡ���ָ���ֵ�͵�ַ
    // �ڶ���str:0x61fdf0----һ����Ҫ����¥
    return strrt;
}

// ���������ɫ
// str - ���������
// HP - ���������ֵ
// MP - �����ħ��ֵ
Role& CreateMonster(const char* str, int HP, int MP)
{
    // ʹ�� new �ؼ��ַ����ڴ棬������һ�� PROLE ���͵�ָ��
    // �����PROLE ָ��һ�� ROLE ���͵�ָ��
    PROLE rt = new ROLE{cstr(str), HP, HP, MP, MP, 1};
    cout << "������str:" << &rt << "----" << rt << endl;
    //  ���� PROLE ָ��
    return *rt;
}

int main()
{
    // char* str;
    //  ����һ�� PROLE ���͵�ָ�룬��ͨ�� CreateMonster ��������
    ROLE& role = CreateMonster("һ����Ҫ����¥", 1500, 1500);
    cout << "main���1:" << &role << "----" << &role << endl; // ��ȡ���ָ���ֵ�͵�ַ

    // ͨ�� . ���� PROLE ָ��ָ��� ROLE ���͵ĳ�Ա
    cout << role.Name << endl;
    cout << role.HP << "/" << role.Hp_Max << endl;
    cout << role.MP << "/" << role.Mp_Max << endl;
}
