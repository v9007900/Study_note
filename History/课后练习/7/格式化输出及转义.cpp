#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a = _getch(), b = _getch(); //��ȡ���̰��� ASCLL ����
    printf("%d\t%d\n", a, b);        //��������
    printf("%+05d\n", a, b);         //�ַ�����  0=�����ʾ  5=�ַ�����  + = ��ʾ����

    //  % d = ʮ����
    //  %o = �˽���
    //  %u = �޷���ʮ����
    //  %x = ʮ������

    return 0;
}
