#include <iostream>
#include <windows.h>
using namespace std;

struct Role
{
    char Name[0x20]; // �洢��ɫ����
    int hp;          // �洢��ɫѪ��
    int mp;          // �洢��ɫħ��ֵ
    int damage;      // �洢��ɫ������
};

// ִ�й�����Ϊ
// ���� Acter ���ж��Ľ�ɫ
// ���� beact �Ǳ������Ľ�ɫ
// ����ֵ�Ǳ��������Ƿ�����
bool Act(const Role& Acter, Role*& beact)
{
    beact->hp -= Acter.damage; // ���ٱ������ߵ�Ѫ��
    bool bend = beact->hp < 0; // �жϱ��������Ƿ�����
    beact = (Role*)&Acter;     // ��������������ָ��
    cout << "beact:" << beact << endl;
    return bend;
}

int main()
{
    Role user{"С����", 200, 300, 850};   // ����һ����ɫ������ʼ��
    Role monster{"�����", 800, 900, 50}; // ����һ����ɫ������ʼ��

    Role* ptr = &monster; // ����һ��ָ�룬��ָ�� monster
    int beact;
    if (Act(user, ptr)) // ��������ɹ�
        cout << ptr->Name << (char)10 << "��������" << endl;
    // ����������ƺ�������Ϣ
    cout << ptr << "----" << &ptr << endl;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "monster: " << &monster << endl;
}

