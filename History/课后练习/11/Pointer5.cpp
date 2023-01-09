#include <iostream>
#include <windows.h>
using namespace std;

const int a = 1000;

const int *const ptra{&a};

int *ptrA{(int *)&a};

*ptrA = 9500;

cout << *ptra << endl;
