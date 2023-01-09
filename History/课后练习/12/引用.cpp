#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {
  system("mode con cols=40 lines=15");
  system("color 8E");
  int a{5250};
  int &la1{a};
  int &la2{a};
  int &la3{la2};
  la3 = 123;

  cout << la1 << "----" << la2 << "----" << la3 << endl;
  cout << &la1 << "----" << &la2 << "----" << &la3 << endl;

  int *ptra{&la1};
  cout << ptra << "----" << *ptra << endl;

  /*输出结果，引用，不分配内存，与目标同内存 同值
  123----123----123
  0x61fdfc----0x61fdfc----0x61fdfc
  0x61fdfc----123
   */

  int a20[]{1, 2, 3, 4, 56, 78};
  for (int &x : a20) { // 条件 引用的&x == a20 的数组
    x++;
    printf_s("%d----", x);
  }
}
