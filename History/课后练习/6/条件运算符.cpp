#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    int a, b, c;

    cout << "��һ������:";
    cin >> a;
    cout << "�ڶ�������:";
    cin >> b;

    //  x = bool ? y : z ; ��ͬ�� ����if
    //  if(a > b)
    //  c=a
    //  else c = b

    // x=bool?Y:Z�� bool ��Ӧ a > b
    c = (a > b ? a : b) + 50000; //? bool ����
    // ������   ����    c=a    ������   c=b

    cout << c << char(10) << endl;

    if (a > b)
    {
        c = a;
        cout << c;
    }
    else if (a < b)
    {
        c = b;
        cout << c << char(10) << char(10);
    }

    int cs;
    cout << "\n����һ����,�Զ�����1�����������Ժ�Ľ��:";
    cin >> cs;
    int ends;
    ends = cs ? (10000 / cs) : 0;
    cout << ends;

    return 0;
}
