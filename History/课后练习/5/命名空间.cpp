#include <iostream>
#include <windows.h>

// using namespace std;

namespace People // ���ƿռ� ��
{
	int HP(500);  //Ѫ�� 500
	int MP(800);  //���� 800
	int PS(600);  //���� 600
	int ATK(100); //���� 100

	namespace Equipment //�Ӽ� ���ƿռ� ����
	{
		int TheSword(100); //��
		int Axe(200);	   //��
	}
}

int bloodVolume;

int main()
{
	system("mode con cols=60 lines=20");
	system("color 8E");
	using namespace People; //ʹ�òֿ������������  �������Ӽ�
	using std::cin;			//ָ��ʹ�òֿ����cin
	using std::cout;		//ָ��ʹ�òֿ����cout
	int STK = ATK + Equipment ::TheSword;
	cout << "������:" << STK << char(10);
	cout << "HP:" << HP << char(10) << "MP:" << MP << char(10) << "PS:" << PS;
	return 0;
}
