#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

void AddXc(char *CC) // ����ss ��ȡss ����
{
    int a = 0;
    cout << endl << endl;
    for (int i = 0; CC[i] != '\0'; i++) a = i;
    printf("����ss=%d\n", a);
}

void Add(char *p1, char *p2) //!! �������ַ�������ƴ��
{
    // *++p1  �ȶ�p1 ����++   �����ȡֵ �ж�  ������ɺ���++ �ͻ�ȡֵ �� ����p1
    // �ж� �ڽ�������++ �Ƚ������� Ȼ��ȡֵ�ж� �����'\0'
    // �ͻ�ֹͣ�ڵ����֣�i++�Ͳ����ڽ����� ������4 ����Ǻ���++ ��ȡֵ�ж�
    // �������ڽ���++ ���� '\0'��ʱ�� �����+1  ������ \0 �����while �Ͳ����滻\0
    while (*++p1) {};
    while ((*p1++ = *p2++)) {};
    printf("Add p1:%s\n", p1 - 11);
}

void remove_space(char *ptr, char &RCC) // ȥ�ո�
{
    char *Tls {ptr}; // �����ַ���
    while (*Tls) {
        // ��� ���� �ո� *ptr = �����ַ��� ���� ptrָ����һ����ַ
        if (*Tls != RCC) {
            *ptr = *Tls;
            ptr++;
        }
        Tls++;
    }
    *ptr = 0;
}

char *my_strchr(char *str, char ch) // ���� ��ַ  �Ͳ��Ҷ���
{
    for (; *str != '\0'; str++)
        if (*str == ch) return str;
    return NULL;
}

char *my_strstr(char *src, char *dest) // ģ�������ַ���
{
    char *fsrc  = src;  // ����Դ�ַ���ָ��
    char *rsrc  = src;  // ��¼��ͬ�ַ����׵�ַ
    char *tdest = dest; // ����ָ��
    while (*fsrc)       // ����srcȫ������
    {
        rsrc = fsrc; // ��¼ fsrc ָ��ɨ�赽��λ��
        // ����ͬ�ַ���ʱ �����ڲ�ѭ���Ƚ�
        while (*fsrc == *tdest && *fsrc != '\0') fsrc++, tdest++;
        if (*tdest == '\0') return rsrc; // �жϲ����ַ��Ƿ����� \0
        tdest = dest;                    // ����ָ�� �ع�����ʼ�׵�ַ
        fsrc  = rsrc;                    // ����ָ�� �ص���¼ָ��λ��
        fsrc++;
    }
    return NULL;
}

int main()
{
    int   i      = 0;
    char  a[]    = {"hellol world hello"}, b[] {"llo"}, c {}; // ע���Ƿ�ռ���ڴ�
    char  ss[93] = {"o s  u  a  d h d s   hellou i a  s  a i h world  s u dh   i u su s u   u    u u sudhs sa s s"};
    char *ptr    = a;
    char  RCC    = 32; // ���� �� ȥ���ַ�

    remove_space(ss, RCC);        // ȥ�� SS �ַ����е� �ո�
    Add(a, b);                    //!! ������bƴ��������aĩβ
    printf("ȥ�ո��:%s\n", ss);  // ���ȥ���ո��Ľ��
    printf("ABƴ�Ӻ�:%s\n\n", a); // ���  a ����  ƴ�Ӻ�Ľ��

    unsigned char *ptrs {(unsigned char *)ss};         //!! ���� �޷���ָ�� ָ��SS ǿתΪ �޷�������
    for (int i {0}, sc {8}; i < (320 >> 2); i++, sc--) //!!��� *ptr ����80���ֽ�����
    {
        if (sc == 0) cout << endl, sc = 8;
        printf("0x%-4x", *++ptrs);
    }
    cout << endl;

    cout << "a�������:";
    for (int i = 0; i < sizeof(a) + 50; i++) // ��� a ���鳤��+10���ַ�
        printf("%c", (unsigned char)a[i]);
    cout << endl;

    AddXc(ss);                                   // ���� ss �ַ�����
    cout << "sizeof(ss):" << sizeof(ss) << endl; // ��ȡss�ַ����鳤��

    ptr = ss;
    for (; *ptr++; i++) // ��� ss�ַ��� \0 �ĳ���
        if (!*ptr) cout << "SS �ַ�����ĳ���:" << i << endl;

    char *Ptt = my_strchr(ss, 'o');
    if (Ptt == NULL) printf("δ�ҵ���ĸ\n");
    else printf("�ҵ���ĸ \"%c\"\n", *Ptt);

    char *pdd = my_strstr(a, b);
    printf("%s\n", pdd);

    if (true) cout << "123";
    int  y  = 20;
    char sc = (char)y;
    if (true) cout << "123";
    if (true) cout << "123";
    int const *str {&y};
}
