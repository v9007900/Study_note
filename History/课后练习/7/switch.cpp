#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    unsigned int sid, spr;
    cin >> sid;
    switch (sid) //ѭ����ֵ Ҫѭ����ָ��
    {
    case 15692:    //��Ҫ���������
        spr = 500; //����������ִ��
        cout << "123";
        break; //�����������������ţ����ڼ���ִ���·�ָ��
    case 65421:
        spr = 450;
        break;
    case 96412:
        spr = 400;
        break;
    case 666:
        [[fallthrough]]; //�����  ��д break ���ᱨ��
    case 321:
        spr = sid * 2; //����Ҫִ�е�ָ�� ��ͬʱ������һ�𼴿�
        break;
    default:     //���Ϸ�ȫ������δ���㣬��������ִ��
        spr = 0; // �Ϸ�ȫ������δ���� spr = 0  �·�if�ж�spr=0����ʾ
        cout << "δ�н�" << char(10);

    } //�� �Ϸ�������һ��ִ���������ָ��

    if (spr) //�ж� =1 ִ��  =0��ִ��
        cout << "��ý���:" << spr << "��Ԫ";

    return 0;
}