#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

// ��ȡ�ַ�������
int clen(const char* str) // char���͵�ָ�� str      1
{
    int i;
    for (i = 0; str[i]; i++)
        ;
    cout << i;
    // cout << "��һ��str:" << &str << "----" << str << endl; // ��ȡ���ָ���ֵ�͵�ַ
    return ++i;
}

// �����ַ���
char* cstr(const char* str) // Ҳ��һ��char���͵�ָ�� str     1
{
    // ��ȡ�ַ�������
    int len = clen(str);
    // �����ڴ�
    char* strrt = new char[len]; // �ڴ��ַ�ڶ��ϣ�����}�������

    // �����ַ���
    memcpy(strrt, str, len);

    // ���ظ��Ƶ��ַ���
    return strrt;
}

int main()
{
    char* str; // ����char ���͵�ָ�룬����ָ�붼ָ��str��û�ж��������  1
    str = cstr("78945624");
    cout << str << endl;
    delete[] str; // �ͷ�str�ڴ�
    cout << str << endl;
}
// �ó������ڸ����ַ�������������ƺ���ַ������� main �����У�ͨ������ cstr ���������ַ���
// "78945624"���������ƺ���ַ��������