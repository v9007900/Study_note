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

            for (int j = 1; j < sizeof(arr) / sizeof(arr[0]); j++) {        // �� 1 ��ʼ������-1����� arr[-1] δ֪�ڴ�
                if (PaNg ? *arr[j] > *arr[j - 1] : *arr[j] < *arr[j - 1]) { // ��ָ����н������� �жϣ������жϵľ��� ָ������ĵ�ַ

                    char *temp = arr[j];
                    arr[j]     = arr[j - 1];
                    arr[j - 1] = temp;

                    // arr[j] ^= arr[j - 1];
                    // arr[j - 1] ^= arr[j];
                    // arr[j] ^= arr[j - 1];
                }
            }
        }
        if (!PaNg) printf("��������\n");
        else printf("��������\n");
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) printf("%10s\n", arr[i]);
    }
    // cout << endl << sizeof(arr) / sizeof(arr[0]) << endl;
    // cout << sizeof(arr) << endl;
}

// �������

// ��������
//        AAA
//        BBB
//        CCC
//        DDD
//        EEE
//        FFF
// ��������
//        FFF
//        EEE
//        DDD
//        CCC
//        BBB
//        AAA
