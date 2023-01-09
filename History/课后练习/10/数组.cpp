#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=15");
    system("color 8E");
    int a[10]{}; //有100个数组
    int b{};     //输入内容
    int i;

    // cout << "a 有：" << sizeof(a) / sizeof(int) << "个数组" << endl;

    while (b < 10) //判断 真的时候执行  假 不执行  此时b=0
    {
        cout << "输入学号(输入0查看已登记的学生信息):";
        cin >> a[b];   //数组a 的 b个数组 输入
        if (a[b] == 0) //判断  输入的值 是不是 0
        {
            //输入的是0  才执行 for  循环打印出 学号
            for (i = 0; i < b; i++) //如果为 0   此时 b=1 i=0 i+1
            {
                cout << i << "号学生号:" << a[i] << endl; // i+1  1号学生的学号是 a数组中第i个
            }
        }
        for (i = 0; i < 98; i++)
        {
            if (a[b] == a[i])
            {
                cout << "重复信息" << endl;
            }
        }
        cout << a[b];
        b++; // b=1
    }
}
