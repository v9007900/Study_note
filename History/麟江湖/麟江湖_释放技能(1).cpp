#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

/*
����[1000\1000] �������[3000\3000] ����������[50]
1,  ����        ���� 100 �����ָ��������ֵ��10%
2,  �����      ����  50 ������Զ��Ŀ����ɻ�������+50���˺�
3,  �����      ����  50 ��������Ŀ�깥��3���غ�
4,  ӥץ��      ����  50 10���غ��ڣ���Ŀ������˺����ָ��˺���20%������ �˺���60%������
5,  ��������    ���� 100 ������Ŀ����ɻ���������+����ʧѪ�����˺�
6,  �׽      ����  50 300���� ʹ����������ֵ���� ���������1000%
*/
struct Roles // ��ɫ����
{
    int HP{};      // ����Ѫ��
    int MaxHP{};   // ���Ѫ��
    int MP{};      // ����ֵ
    int MaxMP{};   // �������ֵ
    int ATK{};     // ������
    int cantact{}; // ��ֹ����
    int buff{};    // �غ�
    bool cant;     // ���Ƽ�
};

int main()
{
    Roles Lead{3000, 3000, 1000, 1000, 50};
    Roles boss{30000, 30000, 500, 500, 50};
    int inKey, damage; // inKey =  ��ȡ���̰��µ� ACll��

huilai:
    system("cls");
    printf("\n\n\t\t����[ %d / %d ]\t\tBOSS����[ %d / %d ]", Lead.HP, Lead.MaxHP, boss.HP, boss.MaxHP);
    printf("\n\t\t����[ %d / %d ]\t\tBOSS����[ %d / %d ]", Lead.MP, Lead.MaxMP, boss.MP, boss.MaxMP);
    printf("\n\t\t������[ %d ]\t\t\tBOSS������[ %d ]", Lead.ATK, boss.ATK);
    cout << "\n\t\tBUFF:" << Lead.buff;

    inKey = _getch();
    damage = 0;

    switch (inKey)
    {
    case 49: // 1  ����        ���� 100 �����ָ��������ֵ��10%
        if (Lead.MP > 99)
        {
            Lead.MP -= 100; // ��ǰ����ֵ -100
            Lead.HP += 300; // ��ǰѪ��ֵ +300
            Lead.HP = Lead.HP > Lead.MaxHP ? Lead.MaxHP : Lead.HP;
            // ��ǰѪ�� ���ڵ��� ���Ѫ�� ? ���ڷ������Ѫ���������ڷ��ػ���Ѫ��
        }
        break; // ����ĩβ
    case 50:   // 2  �����      ����  50 ������Զ��Ŀ����ɻ�������+50���˺�
        if (Lead.MP >= 50)
        {
            Lead.MP -= 50;
            damage = 50 + Lead.ATK;
        }
        break;
    case 51: // 3  �����      ����  50 ��������Ŀ�깥��3���غ�
        if (Lead.MP >= 50)
        {
            Lead.MP -= 50;
            boss.cantact = 3;
        }
        break;
    case 52: // 4  ӥץ��      ����  50 10���غ��ڣ���Ŀ������˺����ָ��˺���20%������ �˺���60%������
        Lead.buff = 10;
        break;
    case 53: // 5  ��������    ���� 100 ������Ŀ����ɻ���������+����ʧѪ�����˺�
        if (Lead.MP >= 100)
        {
            Lead.MP -= 100;
            damage = (Lead.MaxHP - Lead.HP) + Lead.ATK;
        }
        break;
    case 54: // 6  �׽      ����  50 300���� ʹ����������ֵ���� ���������1000%
        if ((Lead.MP >= 300) && (Lead.cant == true))
        {
            int ls = Lead.MaxHP;
            Lead.MaxHP = Lead.MaxMP;
            Lead.MaxMP = ls;
            ls = Lead.HP;
            Lead.HP = Lead.MP;
            Lead.MP = ls;
            Lead.ATK *= 10;
            Lead.cant = false;
        }
        break;
    default:
        break;
    }

    if (boss.cantact > 0)
    {
        boss.cantact--;
    }
    else
        Lead.HP -= boss.ATK;

    boss.HP -= damage;
    if (Lead.buff > 0)
    {
        Lead.buff--;
        Lead.HP += damage * 0.6;
        Lead.MP += damage * 0.2;
        Lead.HP = Lead.HP > Lead.MaxHP ? Lead.MaxHP : Lead.HP;
        Lead.MP = Lead.MP > Lead.MaxMP ? Lead.MaxMP : Lead.MP;
    }
    if (Lead.HP < 1)
    {
        system("cls");
        cout << "��Ϸʧ��";
        system("break");
    }
    else if (boss.HP < 1)
    {
        system("cls");
        cout << "��Ϸʤ��";
        system("break");
    }

    goto huilai;
}