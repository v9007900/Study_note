#include <iostream>
#include <windows.h>
using namespace std;

int chartoint(const char* str)
{
    // ��¼���
    int result = 0;

    // �����ַ���
    for (; *str != '\0'; str++)
    {
        // ���ַ�ת��Ϊ����
        int number = *str - '0';

        // �ۼ�����
        result = result * 10 + number;
    }

    // ���ؽ��
    return result;
}
