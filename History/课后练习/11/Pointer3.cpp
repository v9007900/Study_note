#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int a{888}; // 0x61fe14
    int *z{&a};

    int *z1{(int *)0x61fe0c}; //��ȡĳ�� ��ַ
    // z1 = (int *)0x61fe0c;

    cout << "z:" << z << "  *z" << *z << endl;

    cout << "z1:" << z1 << "  *z1" << *z1 << endl;

    int **z3{&z1};

    cout << "z3:" << z3 << "  *z3" << *z3 << endl;

    int ***z4{&z3};

    cout << "z4:" << z4 << "  *z4" << *z4 << endl;

    // to do dasdsa

    // ��ַ:0x61fe0c  ֵ888
    // ��ַ:0x61fe0c  ֵ888  16, 124, 16
    // ��ַ:0x61fe00  ֵ0x61fe0c
    // ��ַ:0x61fdf8  ֵ0x61fe00
    int *zs{(int *)0x61fdf8};

    cout << zs << endl;
    

    cout << zs+0x4 << endl;
}
