#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    int Array[5]{111, 222, 333, 444, 555};
    int *ptra[5]{&Array[0]};

    int Arraa[5]{222,222,000,000,000};

    /* ptra[0] = (int *)0xf31768; //修改指向的地址 */

    for (int i = 0; i < 5; i++)
    {
        ptra[i] = &Array[i];
        //指向的值   取Array的值

        *ptra[i] = Arraa[i];
        //循环写入 值

        cout << ptra[i] << "  " << *ptra[i] << endl;
    }
}
