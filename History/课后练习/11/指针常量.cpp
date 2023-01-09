#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");

    int a{500};
    int b{600};
    const int aa{700};
    const int bb{800};

    const int *ptra{&a}; //常量类型  指向地址可修改，值不可修改
    int* const ptrb{&b}; //常量指针  指向值可修改，地址不可修改
    

    ptra = &b;  //指向的地址可修改
    *ptrb = 1000;//指向的值可修改

    

    cout << ptra << "   " << *ptra << endl;
    cout << ptrb << "   " << *ptrb << endl;
}
