#include <iostream>
#include <stdio.h>

int str_len(char const *ptr, int i = 0)  // �����ַ�����Ч���ȣ��������ģ�����
{
    for (; *ptr != '\0'; ++ptr, ++i)
        if (*ptr < 0) ++ptr;
    return i;
}

int *get_next(const char *&ch2, int str_len1 = NULL)  // ���� next����
{
    if (str_len1 == NULL) str_len1 = str_len(ch2);  // ���û�д��ݳ��ȣ����Լ�����?

    int *next = new int[str_len1]();  // ���� next ����

    std::fill(next, next + str_len1, -1);  // ������Ԫ�س�ʼ��Ϊ -1

    for (int i = 1; i < str_len1; ++i) {
        int j = next[i - 1];
        while (j >= 0 && ch2[j] != ch2[i]) j = next[j];
        next[i] = j + 1;
    }
    return next;
}

int kmp_search(const char *Str_ves, const char *Find)  // �ַ��� ģ������
{
    int str_len1 = str_len(Str_ves);  // Ŀ���ַ���
    int str_len2 = str_len(Find);     // ɸѡ�ַ���
    int i = 0, j = 0;                 // i = Ŀ���ַ���  j ��ɸѡ�ַ���

    int *next = get_next(Str_ves, str_len2);  // next ���麯��

    while (i < str_len1 && j < str_len2)  // ���? Ŀ����ɸѡһ�£�ͬ++
        (j == -1 || Str_ves[i] == Find[j]) ? ++i, ++j : j = next[j];
    delete[] next;  // �ͷ� next���� �ڴ�
    if (j == str_len2) return i - str_len2;
    else return false;
}


int main()
{
    char ch1[] {"1112111233343332"};
    char ch2[] {"CABACABBACABACA"};                                  // 16
    char ch3[] {"һ������5648SDS����ʮ��"};  // 15
    char ch4[] {"43"};


    int sst = kmp_search(ch1, "43");

    printf("Location:%d\n", sst);

    int aa = 0;
    int ac = 0;


    ac = str_len("һ������5648SDS����ʮ��123");

    std::cout << "aa" << aa << std::endl;
    std::cout << "ac" << ac << std::endl;

    char chs[] {"hello world"};


    for (int i = 0, len_1 = str_len(chs); i < len_1; i++) {
        if (i == len_1 - 1) {
            chs[i] ^= chs[0];
            chs[0] ^= chs[i];
            chs[i] ^= chs[0];
        }
    }
    printf("��λ����:%s", chs);
}
