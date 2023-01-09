#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;
#define Edition "V1.3"
#define Website "官方网站:http://edoyun.ke.qq.com"

int main()
{
    system("mode con cols=50 lines=20");
    system("color 8E");
    cout << "\n\n";
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "\n\n\n\t      ";
    cout << "麟江湖“控制台”版" << Edition << endl;
    cout << "\n\n\n\t\t";
    cout << "正在加载游戏···\n";
    cout << "\t\t    ";
    cout << "进度[8/100]";
    cout << "\n\n\n\t ";
    cout << Website << endl;
    cout << setfill('=') << setw(50) << '=' << endl;

    // 登录页
    system("pause");                              // 暂停
    system("cls");                                // 清屏
    int Birth, Weight, Height, Gender, Telephone; // 出生,体重,身高,性别,电话
    cout << "\n\n";
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "出生年:";
    cin >> Birth;
    cout << "体重(单位KG):";
    cin >> Weight;
    cout << "身高(厘米):";
    cin >> Height;
    cout << "性别(0 代表女 1代表男)";
    cin >> Gender;
    cout << "手机号:";
    cin >> Telephone;
    // 电话 1888888888 身高 185 体重 60 出生 2022 性别 1
    unsigned long long Encryption = Telephone * Height * Weight;
    cout << "加密编码:" << Encryption << Birth << Gender << endl;
    cout << setfill('=') << setw(50) << '=' << endl;

    // 930529060092641281

    return 0;
}