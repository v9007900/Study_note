#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;
#define Edition "V1.3"
#define Website "�ٷ���վ:http://edoyun.ke.qq.com"

int main()
{
    system("mode con cols=50 lines=20");
    system("color 8E");
    cout << "\n\n";
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "\n\n\n\t      ";
    cout << "�뽭��������̨����" << Edition << endl;
    cout << "\n\n\n\t\t";
    cout << "���ڼ�����Ϸ������\n";
    cout << "\t\t    ";
    cout << "����[8/100]";
    cout << "\n\n\n\t ";
    cout << Website << endl;
    cout << setfill('=') << setw(50) << '=' << endl;

    // ��¼ҳ
    system("pause");                              // ��ͣ
    system("cls");                                // ����
    int Birth, Weight, Height, Gender, Telephone; // ����,����,���,�Ա�,�绰
    cout << "\n\n";
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "������:";
    cin >> Birth;
    cout << "����(��λKG):";
    cin >> Weight;
    cout << "���(����):";
    cin >> Height;
    cout << "�Ա�(0 ����Ů 1������)";
    cin >> Gender;
    cout << "�ֻ���:";
    cin >> Telephone;
    // �绰 1888888888 ��� 185 ���� 60 ���� 2022 �Ա� 1
    unsigned long long Encryption = Telephone * Height * Weight;
    cout << "���ܱ���:" << Encryption << Birth << Gender << endl;
    cout << setfill('=') << setw(50) << '=' << endl;

    // 930529060092641281

    return 0;
}