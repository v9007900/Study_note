#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");

    struct CAR //�ṹ��
    {
        char logo{'A'};
        unsigned short wheel{19};
        unsigned price{90000};
    };

    CAR CARA{'C', 25, 500};
    CAR CARB{'B', 30, 800};
    CAR CARC{'S', 40, 900};

    cout << "����logo" << CARA.logo << "\t��������" << CARA.wheel << "\t�����ۼ�" << CARA.price << endl;
    cout << "����logo" << CARB.logo << "\t��������" << CARB.wheel << "\t�����ۼ�" << CARB.price << endl;
    cout << "����logo" << CARC.logo << "\t��������" << CARC.wheel << "\t�����ۼ�" << CARC.price << endl;

    return 0;
}
