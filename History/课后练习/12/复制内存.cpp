#include <iostream>
#include <windows.h>
using namespace std;

int main() {

  int a[]{2147483647, 2147483647, 2147483647, 2147483647,
          2147483647, 2147483647, 2147483647, 2147483647};
  int *ptr = new int[5];

  memset(a, 0x1, 4 * 7);
  // 设置内存(a,设置为0，4*7=28字节)

  memcpy(ptr, a, 7 * sizeof(int));
  // 复制内存，ptr 复制 a  7 个内存 * int

  /* memset(ptr, 0x00, 4 * 7);
  //设置内存(a,设置为X，4*7=28字节) */

  for (int i = 0; i < 7; i++)
    cout << ptr[i] << "----" << &ptr[i] << endl;
}
