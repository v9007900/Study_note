#include <iostream>  // 包含标准输入/输出库
#include <ostream>   // 包含标准输出流
using namespace std; // 使用命名空间 std

// 定义函数 Add，该函数接收两个指向整数的指针作为参数
// 函数内部，将两个指针所指向的整数分别乘以 9 和 8
// 最后返回两个整数的和
int Add(int* a, int* b)
{
    // 乘以 9 和 8
    (*a) *= 9;
    (*b) *= 8;
    // 输出 a 和 b 的值（实际上是地址）
    cout << "Add----" << a << "----" << b << endl;
    // 返回两个整数的和
    return (*a) + (*b);
}

int main()
{
    int x{1}, y{2};                                     // 定义整数 x 和 y，并初始化为 1 和 2
    cout << "初始值----" << x << "----" << y << endl;   // 输出 x y 初始值
    int c = Add(&x, &y);                                // 调用函数 Add，并将函数返回的和赋值给 c
    cout << "传参值----" << &x << "----" << &y << endl; // 输出 x y 地址
    cout << "c----" << c << endl;                       // 输出 c 的值
}