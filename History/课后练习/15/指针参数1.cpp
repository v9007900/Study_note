#include <iostream>
#include <windows.h>
using namespace std;

struct Role
{
    int HP;  // Ѫ��
    int MP;  // ħ��ֵ
    int Atk; // ������
};

int Exp(const Role* rl)
{
    // ���㴫���ɫ�ľ���ֵ
    return rl->HP + rl->MP;
}

int Add(int* x, int* y)
{
    // Ϊ��������ָ��ָ���ֵ���ϲ�ͬ�ı������������������ĺ�
    (*x) *= 100;
    (*y) *= 10;
    return (*x) + (*y);
}

bool Act(Role* acter, Role* beacter)
{
    // ģ��������ɫ��ս��
    // acter �� beacter ���й��������� beacter ��Ѫ��
    beacter->HP -= acter->Atk;
    // ���� beacter �Ƿ񱻻���
    return beacter->HP <= 0;
}

int main()
{
    int x = 2, y = 1;
    int c = Add(&x, &y);

    Role rl{500, 1250};
    c = Exp(&rl);
    cout << "HP=" << rl.HP << endl;

    Role user{1500, 100, 100};
    Role monster{1500, 100, 100};

    // ����һ���������͵ı��� gameOver�������ж���Ϸ�Ƿ����
    bool gameOver = false;

    // ֻҪ��Ϸû�н������ͼ���ѭ��
    while (!gameOver)
    {
        cout << "��ɫ" << user.HP << "----" << user.MP << "----" << user.Atk << endl;
        cout << "����" << monster.HP << "----" << monster.MP << "----" << monster.Atk << endl;

        // ���ú��� Act���� monster ���������ߣ�user ������������
        if (Act(&monster, &user))
        {
            // �����ɫ user �����ܣ������ "��ɫ����" ���� gameOver ��Ϊ true
            cout << "��ɫ����";
            gameOver = true;
        }
        // ���ú��� Act���� user ���������ߣ�monster ������������
        else if (Act(&user, &monster))
        {
            // ������� monster �����ܣ������ "����������" ���� gameOver ��Ϊ true
            cout << "����������";
            gameOver = true;
        }
    }
}