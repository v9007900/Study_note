#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int a[3][3][5]{{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
                   {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
                   {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}}};
    // 0            0                 1                 2
    // 1
    // 2              0��1��2��3��4

    for (int b = 0; b < 3; b++)
    {
        for (int c = 0; c < 3; c++)
        {
            for (int d = 0; d < 5; d++)
            {
                cout << "��" << b+1 << "��¥  ��" << c+1 << "��  ��" << d+1 << "ͬѧ ѧ����:" << a[b][c][d] << endl;
            }
        }
    }


int c,d,e;

    for (int b: a[d][c])
    {
        for (int i:a[e])
        {
            /* code */
        }
        
    }
    











}
