#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int a{500};
    int b{600};
    const int aa{700};
    const int bb{800};

    const int *ptra{&a}; //��������  ָ���ַ���޸ģ�ֵ�����޸�
    int* const ptrb{&b}; //����ָ��  ָ��ֵ���޸ģ���ַ�����޸�
    

    ptra = &b;  //ָ��ĵ�ַ���޸�
    *ptrb = 1000;//ָ���ֵ���޸�

    

    cout << ptra << "   " << *ptra << endl;
    cout << ptrb << "   " << *ptrb << endl;
}
