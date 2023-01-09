#include <iostream>
#include <windows.h>
#include <iomanip>
#include <locale> //字符 头文件
using namespace std;

int main()
{
	system("mode con cols=60 lines=20");
	system("color 8E");
	cout << fixed;			 // 3E20 = 300000000000000000000.000000
	cout << scientific;		 // 3.14 = 3.140000e+00
	cout << defaultfloat;	 //恢复默认
	cout << setprecision(5); // 3.1445646 = 3.144(5)

	cout << dec;	  //输出十进制
	cout << hex;	  //输出十六进制
	cout << oct;	  //输出八进制
	cout << showbase; //十六进制和八进制显示前缀

	cout << setfill('=') << setw(40) << '=' << endl; // setfill = 替换留空部分 setwcc = 留空行数
	cout << 3.1445646 << endl;

	return 0;
}
