#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    string stra{"111"};
    stra.append("222ABC���").append("����12312", 4); //.append  �����޵��ӣ������ڵ�ֻ��ȡ�����ڵ�����
    cout << stra << endl;

    string strb;
    strb = stra.substr(2).substr(3, 4);// �ӵ���λ ��ʼ��ȡ ����λ��ʼ����λ��ȡ
    cout << strb << endl; // 111222ABC�������
                          // 2ABC
}
