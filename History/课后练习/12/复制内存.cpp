#include <iostream>
#include <windows.h>
using namespace std;

int main() {

  int a[]{2147483647, 2147483647, 2147483647, 2147483647,
          2147483647, 2147483647, 2147483647, 2147483647};
  int *ptr = new int[5];

  memset(a, 0x1, 4 * 7);
  // �����ڴ�(a,����Ϊ0��4*7=28�ֽ�)

  memcpy(ptr, a, 7 * sizeof(int));
  // �����ڴ棬ptr ���� a  7 ���ڴ� * int

  /* memset(ptr, 0x00, 4 * 7);
  //�����ڴ�(a,����ΪX��4*7=28�ֽ�) */

  for (int i = 0; i < 7; i++)
    cout << ptr[i] << "----" << &ptr[i] << endl;
}
