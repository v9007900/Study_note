#include <iostream>
#include <windows.h>
#include <iomanip>
#include <locale> //�ַ� ͷ�ļ�
using namespace std;

int main()
{
	system("mode con cols=60 lines=20");
	system("color 8E");
	cout << fixed;			 // 3E20 = 300000000000000000000.000000
	cout << scientific;		 // 3.14 = 3.140000e+00
	cout << defaultfloat;	 //�ָ�Ĭ��
	cout << setprecision(5); // 3.1445646 = 3.144(5)

	cout << dec;	  //���ʮ����
	cout << hex;	  //���ʮ������
	cout << oct;	  //����˽���
	cout << showbase; //ʮ�����ƺͰ˽�����ʾǰ׺

	cout << setfill('=') << setw(40) << '=' << endl; // setfill = �滻���ղ��� setwcc = ��������
	cout << 3.1445646 << endl;

	return 0;
}
