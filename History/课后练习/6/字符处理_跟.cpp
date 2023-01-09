#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    char a, b;
    bool c;

    cout << "输入字符";
    cin >> a;

    b = tolower(a); //转化为 小写
    cout << b << endl;
    b = toupper(a); // 转化为 大写
    cout << b << endl;
    c = islower(a); //判断是否为小写
    cout << boolalpha << c;

    return 0;
}
