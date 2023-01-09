
#define Voids 100

#if Voids == 101
#include <stdalign.h>

#elif Voids == 100
#include <iostream>
using namespace std;

#endif

int main()
{
    cout << __func__ << endl;    // 获取当前函数名
    cout << __DATE__ << endl;    // 文件的编译日期
    cout << __TIME__ << endl;    // 当前转换单元的转换时间
    cout << __FILE__ << endl;    // 源文件的名称
    cout << __LINE__ << endl;    // 当前的行号
    cout << __cplusplus << endl; //

    ////main
    ////Dec 17 2022
    ////02:05:01
    ////预处理指令的逻辑.cpp
    ////19
    ////201402
}
