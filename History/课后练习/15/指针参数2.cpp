#include "Windows.h"

#include <iostream>
using namespace std;

struct Role
{
    int HP;  // Ѫ��
    int MP;  // ħ��ֵ
    int Atk; // ������
};

// �����ʼѪ����ħ��ֵ���������ĳ���
const int INITIAL_USER_HP = 1600;
const int INITIAL_USER_MP = 100;
const int INITIAL_USER_ATK = 100;
const int INITIAL_MONSTER_HP = 1500;
const int INITIAL_MONSTER_MP = 100;
const int INITIAL_MONSTER_ATK = 100;

// ����һ��ս���������ɫ user ����� monster �����ܣ��� gameOver ��Ϊ true
void DoBattle(Role& user, Role& monster, bool& gameOver)
{
    Sleep(500);
    cout << "��ɫ" << user.HP << "----" << user.MP << "----" << user.Atk << endl;
    cout << "����" << monster.HP << "----" << monster.MP << "----" << monster.Atk << endl;

    // �� monster ���������ߣ�user ������������
    user.HP -= monster.Atk;
    // �� user ���������ߣ�monster ������������
    monster.HP -= user.Atk;

    if (user.HP <= 0)
    {
        // �����ɫ user �����ܣ������ "��ɫ����" ���� gameOver ��Ϊ true
        std::cout << "��ɫ����";
        gameOver = true;
        return;
    }
    else if (monster.HP <= 0)
    {
        // ������� monster �����ܣ������ "����������" ���� gameOver ��Ϊ true
        std::cout << "����������";
        gameOver = true;
        return;
    }
}

int main()
{
    // ��ʼ����ɫ user �͹��� monster
    Role user{INITIAL_USER_HP, INITIAL_USER_MP, INITIAL_USER_ATK};
    Role monster{INITIAL_MONSTER_HP, INITIAL_MONSTER_MP, INITIAL_MONSTER_ATK};

    // ����һ���������͵ı��� gameOver�������ж���Ϸ�Ƿ����
    bool gameOver = false;

    // ֻҪ��Ϸû�н������ͼ���ѭ��
    while (!gameOver)
    {
        // ���ú��� DoBattle������һ��ս��
        DoBattle(user, monster, gameOver);
    }
}