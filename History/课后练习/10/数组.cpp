#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    int a[10]{}; //��100������
    int b{};     //��������
    int i;

    // cout << "a �У�" << sizeof(a) / sizeof(int) << "������" << endl;

    while (b < 10) //�ж� ���ʱ��ִ��  �� ��ִ��  ��ʱb=0
    {
        cout << "����ѧ��(����0�鿴�ѵǼǵ�ѧ����Ϣ):";
        cin >> a[b];   //����a �� b������ ����
        if (a[b] == 0) //�ж�  �����ֵ �ǲ��� 0
        {
            //�������0  ��ִ�� for  ѭ����ӡ�� ѧ��
            for (i = 0; i < b; i++) //���Ϊ 0   ��ʱ b=1 i=0 i+1
            {
                cout << i << "��ѧ����:" << a[i] << endl; // i+1  1��ѧ����ѧ���� a�����е�i��
            }
        }
        for (i = 0; i < 98; i++)
        {
            if (a[b] == a[i])
            {
                cout << "�ظ���Ϣ" << endl;
            }
        }
        cout << a[b];
        b++; // b=1
    }
}
