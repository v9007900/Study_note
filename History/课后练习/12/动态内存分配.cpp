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
    cout << "--------��ʼ��ַ--------" << ptra << endl;
    ptra[0] = 2147483647;
    ptra[1] = 2147483647;
    ptra[2] = 2147483647;

    cout << ptra[0] << "----" << &ptra[0] << endl;
    cout << ptra[1] << "----" << &ptra[1] << endl;
    cout << ptra[2] << "----" << &ptra[2] << endl;
  } else {
    cout << "�ڴ����ʧ��";
  }

  cout << "���·����ַ" << endl;
  // ���·����ַС��֮ǰ���ı��ַ������֮ǰ�´�����µ�ַ
  cin >> x;
  ptra = (int *)realloc(ptra, x);
  cout << "--------�����ַ--------" << ptra << endl;
  cout << ptra[0] << "----" << &ptra[0] << endl;
  cout << ptra[1] << "----" << &ptra[1] << endl;
  cout << ptra[2] << "----" << &ptra[2] << endl;
  char keys = _getch();

  if (keys == 65 || keys == 97) {
    goto huiqu;
  } else {
    free(ptra);
  }

  int *ptrb = new int; // C++ �����ڴ淽ʽ
  printf_s("\n\n\n===========================\n");

  for (int i = 0; i < 100; i++) {
    if (ptrb == nullptr)
      cout << "�ڴ����ʧ�ܣ�" << endl;
    ptrb[i] = 2147483647;
  }

  for (int i = 0; i < 1000; i++) { //
    cout << &ptrb[i] << "----" << i << "----" << ptrb[i] << endl;
    Sleep(0);
  }
  delete ptrb; // new int[x]  �ͷ��ڴ�
}
