#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;

int main()
{

�Զ����ǩ����: //���һ���㣬ִ�е� goto ��ת���������ƿ��Զ���+:
    printf("��ת����\n");
    system("pause");
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a{};
    printf("\n�����д��ת��ΪСд:");
linput1: //��ǩ ��ִ�е� goto �� ����ת���˼���ִ��
    scanf("%s", &a);
    if (a > 64 && a < 97)
    {
        a += 32;
        printf("ת�����:%d", a);
        cout << (char)a << endl;
        goto �Զ����ǩ����; // �ص� ��ǩ��
    }
    else
    {
        printf("����������%d\n", a);
        goto linput1; // �ص� ��ǩ1��
    }
    return 0;
}
