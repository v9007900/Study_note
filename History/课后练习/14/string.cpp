#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    /* ���� ʵ�� �ַ����
    char stra[0x10]{"1234"};
    char strb[0x10]{"5678"};
    char strc[0x20]{};
    memcpy(strc, stra, strlen(stra));                    //�� stra ������strc
    memcpy(strc + strlen(stra), strb, strlen(strb) + 1); //��strc ���� ���� strb
    cout << strc;
    c ���� ʵ�� �ַ���� */

    /* string aa, bb,cc;
    aa = "3333";
    cin >> bb;
    cc = bb + aa ;
    printf_s("%d",&cc); */

    /* string stra {"�����Ѳ�������Ƥ��ABCDEF"};// ���迼��������������������ַ�
    cin >> stra;
    cout<<stra; */

    string stra{"ABCD4564", 3}; // �ַ���  ��ȡ��ʾ�ĳ���
    cout << stra << endl;               //���  ABC

    string strb{"�����˺�",0,10};//�������룬�ӵ� 0 λ�� ��ȡ�� �� 10 λ
    cin >> strb;
    cout << strb << endl;


    string strc(6,'a');//��ӡ 6�� a
    cout << strc << endl;


    string strd,ls;// �ַ� ƴ��
    ls = "123";
    strd = ls + "456";  // ����a+����b  �������c
    cout <<strd << endl;


    int age;
    cin >> age;
    string straa,lss;
    lss="�û��������:";
    straa = lss + to_string(age); // to_string �� ���� ת��Ϊ �ַ�
    cout<<straa;

}