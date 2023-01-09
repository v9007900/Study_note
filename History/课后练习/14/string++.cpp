#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    string stra{"111"};
    stra.append("222ABC你好").append("中文12312", 4); //.append  可无限叠加，括号内的只截取货号内的内容
    cout << stra << endl;

    string strb;
    strb = stra.substr(2).substr(3, 4);// 从第五位 开始截取 第五位开始第四位截取
    cout << strb << endl; // 111222ABC你好中文
                          // 2ABC
}
