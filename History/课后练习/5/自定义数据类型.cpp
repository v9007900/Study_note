#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");

    struct CAR //结构名
    {
        char logo{'A'};
        unsigned short wheel{19};
        unsigned price{90000};
    };

    CAR CARA{'C', 25, 500};
    CAR CARB{'B', 30, 800};
    CAR CARC{'S', 40, 900};

    cout << "车辆logo" << CARA.logo << "\t车辆轮子" << CARA.wheel << "\t车辆售价" << CARA.price << endl;
    cout << "车辆logo" << CARB.logo << "\t车辆轮子" << CARB.wheel << "\t车辆售价" << CARB.price << endl;
    cout << "车辆logo" << CARC.logo << "\t车辆轮子" << CARC.wheel << "\t车辆售价" << CARC.price << endl;

    return 0;
}
