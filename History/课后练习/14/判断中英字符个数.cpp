#include <iostream>
#include <sstream>
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
    // ���ÿ���̨���ڵ�����������
    system("mode con cols=40 lines=15");

    // ���ÿ���̨���ڵ���ɫ
    system("color 8E");

    // �ӱ�׼�������ж�ȡ�ַ���
    string strin{};
    cin >> strin;

    // ���ַ���ת��Ϊ����
    int xc = stoi(strin);

    // �����ַ����ĳ���
    int length{0};
    for (int i = 0; strin[i]; i++)
    {
        // ����ַ����г����������ַ�����Ҫ������һ���ֽ�
        if (strin[i] < 0)
            i++;
        length++;
    }

    // ����ַ����ĳ��Ⱥ�ת���������ֵ
    cout << length << (char)10 << xc << endl;

    // ʹ�� printf �������ת���������ֵ
    printf_s("%s", xc);
}