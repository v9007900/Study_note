#include <iostream>
#include <ostream>
#include <stdio.h>

using namespace std;


int main()
{
    char *arr[6] {(char *)"DDD", (char *)"AAA", (char *)"BBB", (char *)"FFF", (char *)"EEE", (char *)"CCC"};
    bool  PaNg = false;

    for (int s = 0; s < 2; s++, PaNg = !PaNg) {

        for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {

            for (int j = 1; j < sizeof(arr) / sizeof(arr[0]); j++) {        // 从 1 开始，否则-1会访问 arr[-1] 未知内存
                if (PaNg ? *arr[j] > *arr[j - 1] : *arr[j] < *arr[j - 1]) { // 对指针进行解引用在 判断，否则判断的就是 指针数组的地址

                    char *temp = arr[j];
                    arr[j]     = arr[j - 1];
                    arr[j - 1] = temp;

                    // arr[j] ^= arr[j - 1];
                    // arr[j - 1] ^= arr[j];
                    // arr[j] ^= arr[j - 1];
                }
            }
        }
        if (!PaNg) printf("正序排列\n");
        else printf("倒叙排列\n");
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) printf("%10s\n", arr[i]);
    }
    // cout << endl << sizeof(arr) / sizeof(arr[0]) << endl;
    // cout << sizeof(arr) << endl;
}

// 输出内容

// 正序排列
//        AAA
//        BBB
//        CCC
//        DDD
//        EEE
//        FFF
// 倒叙排列
//        FFF
//        EEE
//        DDD
//        CCC
//        BBB
//        AAA
