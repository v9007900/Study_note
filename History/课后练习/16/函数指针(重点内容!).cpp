#include <iostream>
#include <windows.h>
using namespace std;

typedef char (*ptra)(int, int); //// ����һ���������͵�ָ�� ptra,  ��ptra��

using ptrb = char (*)(int, int); //// ���庯������ָ�룬��ͬ�Ķ��巽ʽ
using ptrc = int (*)(int, int);  ////using

int Add(int a, int b)
{
    // return
    a += b;
    return a + b;
}

void Xdd(int a, int b)
{
    // return
    a += b;
}

struct Role
{
    int Hp;
    int Mp;
};

int Eep(int a, int b, ptrc x) // TODO    ָ�뺯�����÷�
{
    return x(a, b);
}
int Exp(Role Rll)
{
    return Rll.Hp - Rll.Mp;
}
int main()
{
    cout << Eep(20, 30, Add) << endl; // TODO   Eep (a,b,x=ָ��һ������������)

    char (*ptr)(int, int) = (char (*)(int, int))Add; //// ָ��Add��ָ�룬    ǿ��ת��int

    ptra Addx = (ptra)Add; ////��ͬ������
    ptrb Xddx = (ptrb)Xdd; ////�����ָ�����ͣ������� (ת��)������

    cout << "--------" << ptr(30, 35) << endl << endl;
    cout << Xddx(45, 45);

    ptrc Pexp = (ptrc)Exp;
    cout << Pexp(350, 350) << endl;
}
