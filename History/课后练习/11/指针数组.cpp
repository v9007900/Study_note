#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    int Array[5]{111, 222, 333, 444, 555};
    int *ptra[5]{&Array[0]};

    int Arraa[5]{222,222,000,000,000};

    /* ptra[0] = (int *)0xf31768; //�޸�ָ��ĵ�ַ */

    for (int i = 0; i < 5; i++)
    {
        ptra[i] = &Array[i];
        //ָ���ֵ   ȡArray��ֵ

        *ptra[i] = Arraa[i];
        //ѭ��д�� ֵ

        cout << ptra[i] << "  " << *ptra[i] << endl;
    }
}
