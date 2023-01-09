#include <fstream>
#include <iostream>
#include <ostream>
#include <windows.h>
using namespace std;

// 105,98,73,58,32,31,25,22,3,1
// 1,3,22,25,31,32,58,73,98,105

int main() {

  int a01[]{1, 3, 22, 25, 31, 32, 58, 73, 98, 105};
  int a02[]{105, 98, 73, 58, 32, 31, 25, 22, 3, 1};

  int acout = sizeof(a01) / sizeof(int); // 整个数组数量/int 4字节
  int *anew = new int[acout + 1];

  // cout << sizeof(anew) << endl;
  int key;
  cout << "输入数值";
  cin >> key; //  输入 103

  int getIndex{acout};
  bool bacse = a01[0] > a01[1];

  for (int i = 0; i < acout; i++) {
    if (bacse ^ (key < a01[i])) {
      getIndex = i;
      break;
    }
  }

  memcpy(anew, a01, getIndex * sizeof(int));
  // 读内存，( 容器 , 目标 a01  复制字节  0*4)
  memcpy(anew + getIndex + 1, anew + getIndex,
         (acout - getIndex) * sizeof(int));
  //
  anew[getIndex] = key;
  for (int i = 0; i <= acout; i++) {
    cout << anew[i] << endl;
  }
}
