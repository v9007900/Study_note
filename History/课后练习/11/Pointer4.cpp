#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int a[]{
        10001,
        20001,
        30001,
        4000,
    };
    int *ptr{&a[0]};

    (*ptr)++; //  ������=*ptr+1  ��ʱ�ӵ���ָ���ַ�� ֵ

    cout << *ptr << "   " << a[0] << endl; // 10002
    cout << *ptr << "   " << ptr << endl;

    *ptr++; //   �������� =  ��+1 ��ʱ��ptr ָ������ڴ��ַ +1 ��ı��ַ
    cout << *ptr << "   " << ptr << endl;

}
