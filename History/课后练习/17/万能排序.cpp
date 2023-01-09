#include <iostream>
#include <windows.h>
using namespace std;

template <typename Sort>
void Swap(Sort& a, Sort& b)
{
    Sort tmp{a};
    a = b;
    b = tmp;
    /* a ^= b;
    b ^= a;
    a ^= b; */
}

template <typename Sorts>
void SORT(Sorts ary[], unsigned int count, bool Bigsort = true)
{
    for (unsigned i = 1; i < count; i++)
        for (unsigned x = 1; x < count; x++)
            if (Bigsort ? ary[x] > ary[x - 1] : ary[x] < ary[x - 1])
                Swap(ary[x], ary[x - 1]);
}
int main()
{
    int ara[7]{123, 456, 789, 50, 651, 156, 156165};
    short arb[7]{255, 123, 50, 16, 16, 154, 15615};
    string arc[7]{"sda", "khdsada", "kjhdsa", "das", "fs", "fda", "dshufy"};

    SORT(ara, 7, 0);
    for (auto i : ara)
        cout << i << endl;
    cout << endl;

    SORT(arb, 7, 0);
    for (auto i : arb)
        cout << i << endl;
    cout << endl;

    SORT(arc, 7, 0);
    for (auto i : arc)
        cout << i << endl;
}
