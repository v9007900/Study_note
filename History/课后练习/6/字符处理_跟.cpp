#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a, b;
    bool c;

    cout << "�����ַ�";
    cin >> a;

    b = tolower(a); //ת��Ϊ Сд
    cout << b << endl;
    b = toupper(a); // ת��Ϊ ��д
    cout << b << endl;
    c = islower(a); //�ж��Ƿ�ΪСд
    cout << boolalpha << c;

    return 0;
}
