#include <iostream>
#include <windows.h>
using namespace std;

// 930529060092641281

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    long long An_Code{930529060092641281};          //Ӳ���� 0x FFFF FFFF //ffff ffff
    long long Bn_Code(0xF468D47EF594A5B8LL);        //���ò�����
    unsigned long long Dn_Code = An_Code ^ Bn_Code; // D = A ^ B
    cout << hex << endl;                            //���ʮ������
    Dn_Code = Dn_Code ^ An_Code;                    // D = D ^ A
    cout << Dn_Code << endl;                        // f468 d47e f594 a5b8

    unsigned short Cn_Code1, Cn_Code2, Cn_Code3, Cn_Code4;
    cin >> hex; //�л�Ϊ16��������
    cout << "������1:";
    cin >> Cn_Code1;
    cout << "������2:";
    cin >> Cn_Code2;
    cout << "������3:";
    cin >> Cn_Code3;
    cout << "������4:";
    cin >> Cn_Code4;

    long long A{};
    long long is{};

    is = Cn_Code1;
    is <<= 48;

    A = is;
    is = Cn_Code2;
    is <<= 32;

    A |= is;
    is = Cn_Code3;
    is <<= 16;

    A |= is;
    A |= Cn_Code4;
    A ^= Bn_Code;

    cout << A;
}
