#include <iostream>
#include <windows.h>
#include <winnls.h>
using namespace std;

void SORT(int ary[], unsigned int count, bool Bigsort = true)
{
    for (int j = 1; j < count; j++)
        for (int i = 1; i < count; i++)
        {
            if (Bigsort ? ary[i] < ary[i - 1] : ary[i] > ary[i - 1])
            {
                ary[i] ^= ary[i - 1];
                ary[i - 1] ^= ary[i];
                ary[i] ^= ary[i - 1];
                /* int tmp = ary[i];
                ary[i] = ary[i - 1];
                ary[i - 1] = tmp;  */
                cout << ary[i] << "----" << ary[i - 1] << endl;
            }
        }
}

int main()
{
    int a[5]{333, 444, 222, 111, 555};
    SORT(a, 5);
    for (auto x : a)
    {
        cout << x << endl;
    }
}

/*
第一轮:数组 ary[i] = 1 < count[5] ,成立 i +1
    嵌套 第一轮:数组 ary[i] = 2 < count[5] ,成立  ary[2]=222
        tmp = ary[i]=2 数值是222
        ary[i]2 = ary[i-1] 1 444  ary[i]2  此时 ary[2] = 444
        ary[2 - 1] = tmp ; ary[1] = 222




*/