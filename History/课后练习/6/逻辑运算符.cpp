#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char cins{};
    cout << "����һ���ַ�:";
    cin >> cins; // 47���Ϸ��� 58���·���
    if ((cins > 47) && (cins < 58))
    { //���� 47 ������  С�� 58 �� ����+����
        cout << "�������һ������:" << cins;
    }
    else if ((cins >= 65) && (cins <= 90))
    { //���ڵ��� 65 �Ǵ�д��ĸ  С�ڵ��� 90 �Ǵ�д��ĸ
        cout << "������Ǵ�д��ĸ:" << cins << "ת����Сд:" << char(cins + 32);
    }
    else if ((cins > 96) && (cins < 123))
    { //���� 96 ��Сд��ĸ С�� 123 ��Сд��ĸ
        cout << "�������Сд��ĸ:" << cins << "ת���ɴ�д:" << char(cins - 32);
    }
    return 1;
}

/*
    ��� (cins ���� 47) �� (cins С�� 58)
    {�������� ִ�������ڵ�����
    }
    ����ִ���������
    ��� (cins ���ڵ���65) �� ��cins С�ڵ��� 90)
    {����������ִ�������ڵ�ָ��
    }
    ������������ִ���������ָ��
    �ظ�.....
*/