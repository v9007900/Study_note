#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
huiqu:
  unsigned x;
  cin >> x;
  // int *ptr = (int *)malloc(x * sizeof(int));
  int *ptra = (int *)calloc(x, sizeof(int));

  if (ptra != nullptr) {
    cout << "--------初始地址--------" << ptra << endl;
    ptra[0] = 2147483647;
    ptra[1] = 2147483647;
    ptra[2] = 2147483647;

    cout << ptra[0] << "----" << &ptra[0] << endl;
    cout << ptra[1] << "----" << &ptra[1] << endl;
    cout << ptra[2] << "----" << &ptra[2] << endl;
  } else {
    cout << "内存分配失败";
  }

  cout << "重新分配地址" << endl;
  // 重新分配地址小于之前不改变地址，大于之前会拷贝到新地址
  cin >> x;
  ptra = (int *)realloc(ptra, x);
  cout << "--------重配地址--------" << ptra << endl;
  cout << ptra[0] << "----" << &ptra[0] << endl;
  cout << ptra[1] << "----" << &ptra[1] << endl;
  cout << ptra[2] << "----" << &ptra[2] << endl;
  char keys = _getch();

  if (keys == 65 || keys == 97) {
    goto huiqu;
  } else {
    free(ptra);
  }

  int *ptrb = new int; // C++ 分配内存方式
  printf_s("\n\n\n===========================\n");

  for (int i = 0; i < 100; i++) {
    if (ptrb == nullptr)
      cout << "内存分配失败！" << endl;
    ptrb[i] = 2147483647;
  }

  for (int i = 0; i < 1000; i++) { //
    cout << &ptrb[i] << "----" << i << "----" << ptrb[i] << endl;
    Sleep(0);
  }
  delete ptrb; // new int[x]  释放内存
}
