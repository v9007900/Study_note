#include <conio.h>
#include <iostream>
#include <stdio.h>
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
    int HP;    // ����HP
    int MaxHP; // ���Ѫ��
    int MP;    // ����MP
    int MaxMP; // �������
    int ATK;   // ������
    int PAks;  // ��ֹ����
    int Rbuff; // �غ�
    bool cant; // ������
};
struct Skill // ����
{
    int Cure;      // ���� 100 �����ָ��������ֵ��10%
    int VajraPalm; // ����  50 ������Զ��Ŀ����ɻ�������+50���˺�
    int Paralyze;  // ����  50 ������ֹĿ�깥��3���غ�
    int EGAk;  // ����  50 10���غ��ڣ���Ŀ������˺����ָ��˺���20%������ �˺���60%������
    int BSFTD; // �� 100 ������Ŀ����ɻ���������+����ʧѪ�����˺�
    int TCCl;  // ����  50 300���� ʹ����������ֵ���� ���������1000%
};
int main()
{
    Roles roles[2]{{3000, 3000, 2000, 2000, 50, 0, 0, 1},  // ����
                   {3000, 3000, 2000, 2000, 50, 0, 0, 1}}; // roles[1]

    Skill Skills[6]{{300, 0, 100, 0, 0, 0}, /*������       Cure hp-maxhp-mp-maxmp-��ֹ����-�غ�-������*/
                    {0, 0, 50, 0, 50, 0},   /*�����       Paralyze*/
                    {0, 0, 50, 0, 0, 3},    /*�����       Paralyze*/
                    {0, 0, 50, 0, 0, 0},    /*ӥץ��       EGAk*/
                    {0, 0, 100, 0, 0, 0},   /*��������     BSFTD*/
                    {0, 0, 50, 0, 0, 0}};   /*�׽       TCCl*/

    char inKey = _getch(45);
    /* int *ptra{(int *)&roles[0]};  // 0x61fdc0
    int *ptrb{(int *)&Skills[0]}; // 0x61fd30 */

    do
    {

        /* printf("\n\n\t\t����[ %d / %d ]\t\tboss����[ %d / %d ]", roles[0].HP, roles[0].MaxHP, roles[1].HP,
        roles[1].MaxHP); printf("\n\t\t����[ %d / %d ]\t\tboss����[ %d / %d ]", roles[0].MP, roles[0].MaxMP,
        roles[1].MP, roles[1].MaxMP); printf("\n\t\t������[ %d ]\t\t\tboss������[ %d ]", roles[0].ATK, roles[1].ATK); */

        if (inKey > 57 && inkey < 48)
        {
            if (inkey == 47 && roles[0].HP < 90)
            {
                roles[0].HP += Skills[0].Cure;
                roles[0].MP -= Skills[0].Cure;
            }
        }

        cout << roles[0].MP;
    } while (true);
}
