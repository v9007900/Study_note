#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
    char c{};
    cin >> c; //����C  67

    for (char a = c + 1; a < 90; a++) // a=C(67)+1=68  a++=69
    {
        if (!((a - c - 1) % 5) && (a > (c + 1)))
        { // a(69)-C(68)-1=0%0=0  ���� ��ת0=1  a(69)>(c68+1=69)����������
            cout << "  " << (int)a << endl;
        }
        cout << (int)a;
    }

    return 0;
}
