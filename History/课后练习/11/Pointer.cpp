#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    int aa{500};
    char bb{69};
    double cc{20};

    int *a{&aa};    //  & 指向aa的地址
    char *b{&bb};   //  & 指向bb的地址
    double *c{&cc}; //  & 指向cc的地址

    cout << sizeof(*a) << sizeof(*b) << sizeof(*c) << endl; // 4 1 8
    cout << sizeof(a) << sizeof(b) << sizeof(c) << endl;    // 8 8 8

    cout << "a:" << *a << "b:" << *b << "c:" << *c << endl; // 500 DC 7.88
    cout << "a:" << a << "b:" << b << "c:" << c << endl;    // 0x61fe04b

    指针本质是地址
    使用时，加*表示得到这个地址所存的值
    不加*得到的是 地址   int 指针 +1 是+4字节  char 指针+ 1 加 1字节

    cout << char(10) << char(10);

    int asd{123456}; //  asd 的地址是 0x61fde4
    int *ccc{&asd};  //指针 指向地址是，一定要加 &&&&&&&&&&  //0x61fde4

     int *ssw{0x61fdec};

    cout << asd << endl;
    for (int i = 0; i < asd; i++)
    {

        (ccc)++;
        // cout << ccc << endl;
        cout << asd << endl;
        // _sleep(500);
    }
    int a[8]{
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        89,
    };
    int *b{a};
    *(b++);
    cout << *b;

    cout << ssw << endl;

    int asd{123456}; //  asd 的地址是 0x61fde4
    int *ccc{&asd};  //指针 指向地址是，一定要加 &&&&&&&&&&  //0x61fde4

    int *ssw{};

    cout << ccc << endl;
    cout << *ccc << endl;
    cout << ssw + 0x61fe0c << endl;
}
