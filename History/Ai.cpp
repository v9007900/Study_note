#include <iostream>
#include <ostream>
#include <string.h>
#include <string>
#include <windows.h>
using namespace std;

// ������  ��ɫ�ࡢ

class Role {
private: // ˽��,��ֹ�����д
         // ID ����  �ɶ���д
  string Name{};
  // �ȼ�     �ɶ� ��д
  unsigned short LV{}; // short ˫�ֽ�  65535
  // Ѫ��     �ɶ� ��д
  int HP{};
  // ����     �ɶ� ��д
  int MP{};
  // ������   �ɶ� ����д
  int ATK{};

public:                       // ������ʽӿ�
  Role &SetName(string _Name) // д�� ID
  {
    Name = _Name;
    return *this;
  }

  Role &SetLv(unsigned short _LV) // д��ȼ�
  {
    if (_LV < 0 || _LV >= 3) // �ж�д���Ƿ�����
    {
      cout << "��⵽�Ƿ��޸�";
      return *this;
    }
    LV += _LV;
    return *this;
  }

  // ������д�벿��

  void ReadAll(); // ��ȡȫ����Ϣ
};

void Role::ReadAll() // ��ȡȫ����Ϣ
{
  cout << "ID:" << Name << endl;
  cout << "�ȼ�:" << LV << endl;
  HP = LV * 5;
  cout << "Ѫ��:" << HP << endl;
  MP = LV * 125;
  cout << "����:" << MP << endl;
  ATK = LV * 10;
  cout << "����:" << ATK << endl;
}

int main() {
  Role role_1;
  Role role_2;

  for (int i = 0; i < 100; i++) {
    Sleep(500);
    system("cls");
    role_2.SetName("�Ϲ�����").SetLv(1);
    role_1.SetName("�Ϲ�����").SetLv(1);
    role_1.ReadAll();
    role_2.ReadAll();
  }
}

void stdd(){

};