
#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

////����һ���ͷ��ڴ�ĺ�
#define RELEASE(x)                                                                                                     \
    delete[] x;                                                                                                        \
    x = nullptr;
#define eva(x) std::cout << x << endl // ����һ���滻cout�ĺ� #x ����ֱ�������ַ���

int main()
{
    int* add = new int;
    printf("%d\n", *add);

    // RELEASE(add);

    printf("%d\n", *add);

    eva(15415);
}
