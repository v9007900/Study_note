#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

void AddXc(char *CC) // 遍历ss 获取ss 长度
{
    int a = 0;
    cout << endl << endl;
    for (int i = 0; CC[i] != '\0'; i++) a = i;
    printf("遍历ss=%d\n", a);
}

void Add(char *p1, char *p2) //!! 将两个字符串进行拼接
{
    // *++p1  先对p1 进行++   随后在取值 判断  如果换成后置++ 就会取值 后 进行p1
    // 判断 在进行自增++ 先进行自增 然后取值判断 如果是'\0'
    // 就会停止在第四轮，i++就不会在进行了 所以是4 如果是后置++ 先取值判断
    // 结束后在进行++ 遇到 '\0'的时候 会继续+1  跳过了 \0 下面的while 就不会替换\0
    while (*++p1) {};
    while ((*p1++ = *p2++)) {};
    printf("Add p1:%s\n", p1 - 11);
}

void remove_space(char *ptr, char &RCC) // 去空格
{
    char *Tls {ptr}; // 遍历字符串
    while (*Tls) {
        // 如果 不是 空格 *ptr = 遍历字符串 并且 ptr指向下一个地址
        if (*Tls != RCC) {
            *ptr = *Tls;
            ptr++;
        }
        Tls++;
    }
    *ptr = 0;
}

char *my_strchr(char *str, char ch) // 传入 地址  和查找对象
{
    for (; *str != '\0'; str++)
        if (*str == ch) return str;
    return NULL;
}

char *my_strstr(char *src, char *dest) // 模糊查找字符串
{
    char *fsrc  = src;  // 遍历源字符串指针
    char *rsrc  = src;  // 记录相同字符串首地址
    char *tdest = dest; // 查找指针
    while (*fsrc)       // 遍历src全部内容
    {
        rsrc = fsrc; // 记录 fsrc 指针扫描到的位置
        // 有相同字符串时 进行内部循环比较
        while (*fsrc == *tdest && *fsrc != '\0') fsrc++, tdest++;
        if (*tdest == '\0') return rsrc; // 判断查找字符是否遇到 \0
        tdest = dest;                    // 查找指针 回滚到初始首地址
        fsrc  = rsrc;                    // 遍历指针 回到记录指针位置
        fsrc++;
    }
    return NULL;
}

int main()
{
    int   i      = 0;
    char  a[]    = {"hellol world hello"}, b[] {"llo"}, c {}; // 注释是否占用内存
    char  ss[93] = {"o s  u  a  d h d s   hellou i a  s  a i h world  s u dh   i u su s u   u    u u sudhs sa s s"};
    char *ptr    = a;
    char  RCC    = 32; // 查找 并 去掉字符

    remove_space(ss, RCC);        // 去掉 SS 字符串中的 空格
    Add(a, b);                    //!! 将数组b拼接在数组a末尾
    printf("去空格后:%s\n", ss);  // 输出去除空格后的结果
    printf("AB拼接后:%s\n\n", a); // 输出  a 数组  拼接后的结果

    unsigned char *ptrs {(unsigned char *)ss};         //!! 定义 无符号指针 指向SS 强转为 无符号类型
    for (int i {0}, sc {8}; i < (320 >> 2); i++, sc--) //!!输出 *ptr 后面80个字节内容
    {
        if (sc == 0) cout << endl, sc = 8;
        printf("0x%-4x", *++ptrs);
    }
    cout << endl;

    cout << "a数组后续:";
    for (int i = 0; i < sizeof(a) + 50; i++) // 输出 a 数组长度+10的字符
        printf("%c", (unsigned char)a[i]);
    cout << endl;

    AddXc(ss);                                   // 计算 ss 字符长度
    cout << "sizeof(ss):" << sizeof(ss) << endl; // 获取ss字符数组长度

    ptr = ss;
    for (; *ptr++; i++) // 输出 ss字符到 \0 的长度
        if (!*ptr) cout << "SS 字符数组的长度:" << i << endl;

    char *Ptt = my_strchr(ss, 'o');
    if (Ptt == NULL) printf("未找到字母\n");
    else printf("找到字母 \"%c\"\n", *Ptt);

    char *pdd = my_strstr(a, b);
    printf("%s\n", pdd);

    if (true) cout << "123";
    int  y  = 20;
    char sc = (char)y;
    if (true) cout << "123";
    if (true) cout << "123";
    int const *str {&y};
}
