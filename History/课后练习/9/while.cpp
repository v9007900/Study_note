#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    char inkey; //��ذ��µ��ǲ���Yy
    int intin;  //�������
    cout << "����һ����";
    cin >> intin; //���� �����
    bool bacse{}; //����ֵ bacse ����
    for (int i = 3; i <= sqrt(intin); i += 2)
        // 1~3 ������������3��ʼѭ��
        // iС�ڵ��� sqrt(��ƽ����) ������1000  10 10  intin = 10  i=3<=10  3+2=5=7=9  ѭ�����ν�����
        if (intin % i == 0) // 1000 % i 3 5 7 9  = 0
        {
            bacse = true; // 0Ϊ��  bacse��תΪ1
            cout << "bacse=" << bacse << endl;
            break; //��������ѭ������if
        }
    if (bacse) // 1 ִ��������  bareak ��������
    {
        cout << "bacse2=" << bacse << endl;
        cout << "�������������\n"; // 1 ���� cout
    }
    else // 0 ִ��else
    {
        cout << "���������\n"; // 0 ����cout
    }

    cout << "���Ҫ������һ�������밴[Y] ������������Ƴ�����\n";
    cin >> inkey;                        //�жϰ���
    while (inkey == 'Y' || inkey == 'y') //���µ��� Y ���� y
    {
        int intin; //�������
        cout << "����һ����:";
        cin >> intin;                                          //�������
        bool bcase{};                                          //����ֵ bacse ����
        bcase = (intin % 2 != 0);                              //�ж� �����ֵ%2�Ƿ����0 1000%2=0
        for (int i = 3; (bcase) && (i <= sqrt(intin)); i += 2) // i=3  bacse������0 �� i С�ڵ���  ����ֵ��ƽ����   bcase������ִ�к����жϣ�������ֱ����������Լ����
            if (intin % i == 0)                                // 10%3=0  ��������
            {
                bcase = false; // 1ת��Ϊ0
                break;         //���� if
            }
        if (bcase) //�ж� 1 ִ��COUT 0 else
        {
            cout << "�����������\n";
        }
        else
        {
            cout << "�������������\n";
        }

        cout << "���Ҫ������һ�����㣬�밴[Y] ���������ⰴ���Ƴ�����";
        cin >> inkey;
    }
}
