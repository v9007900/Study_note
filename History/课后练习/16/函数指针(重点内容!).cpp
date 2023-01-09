#include <iostream>
#include <windows.h>
using namespace std;

typedef char (*ptra)(int, int); //// 定义一个函数类型的指针 ptra,  （ptra）

using ptrb = char (*)(int, int); //// 定义函数类型指针，不同的定义方式
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

int Eep(int a, int b, ptrc x) // TODO    指针函数的用法
{
    return x(a, b);
}
int Exp(Role Rll)
{
    return Rll.Hp - Rll.Mp;
}
int main()
{
    cout << Eep(20, 30, Add) << endl; // TODO   Eep (a,b,x=指顶一个函数来处理)

    char (*ptr)(int, int) = (char (*)(int, int))Add; //// 指向Add的指针，    强制转换int

    ptra Addx = (ptra)Add; ////等同于上面
    ptrb Xddx = (ptrb)Xdd; ////定义的指针类型，变量名 (转换)函数体

    cout << "--------" << ptr(30, 35) << endl << endl;
    cout << Xddx(45, 45);

    ptrc Pexp = (ptrc)Exp;
    cout << Pexp(350, 350) << endl;
}
