#include <iostream>
#include <windows.h>
using namespace std;

// 指针 a  有count个元素
/* void sort(int* a, unsigned int count)
{
    for (int j = 1; j < count; j++)
        for (int i = 1; i < count; i++)
        {
            int tmp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = tmp;
        }
} */

void sort(int* a, unsigned int count)
{
    // 使用 qsort 函数
    std::qsort(a, count, sizeof(int), [](const void* a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        if (arg1 < arg2)
            return -1;
        if (arg1 > arg2)
            return 1;
        return 0;
    });
}

int main()
{
    int a[4]{222, 999, 777, 444};
    sort(a, 4);
    for (auto x : a)
    {
        cout << x << endl;
    }
}
