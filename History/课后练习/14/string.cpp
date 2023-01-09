#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    /* 语言 实现 字符相加
    char stra[0x10]{"1234"};
    char strb[0x10]{"5678"};
    char strc[0x20]{};
    memcpy(strc, stra, strlen(stra));                    //将 stra 拷贝到strc
    memcpy(strc + strlen(stra), strb, strlen(strb) + 1); //在strc 后面 加上 strb
    cout << strc;
    c 语言 实现 字符相加 */

    /* string aa, bb,cc;
    aa = "3333";
    cin >> bb;
    cc = bb + aa ;
    printf_s("%d",&cc); */

    /* string stra {"吃葡萄不吐葡萄皮！ABCDEF"};// 无需考虑数据溢出，随意输入字符
    cin >> stra;
    cout<<stra; */

    string stra{"ABCD4564", 3}; // 字符串  截取显示的长度
    cout << stra << endl;               //输出  ABC

    string strb{"输入账号",0,10};//限制输入，从第 0 位置 截取到 第 10 位
    cin >> strb;
    cout << strb << endl;


    string strc(6,'a');//打印 6个 a
    cout << strc << endl;


    string strd,ls;// 字符 拼接
    ls = "123";
    strd = ls + "456";  // 变量a+变量b  输出变量c
    cout <<strd << endl;


    int age;
    cin >> age;
    string straa,lss;
    lss="用户的身高是:";
    straa = lss + to_string(age); // to_string 将 数字 转换为 字符
    cout<<straa;

}