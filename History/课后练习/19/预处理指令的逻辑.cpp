
#define Voids 100

#if Voids == 101
#include <stdalign.h>

#elif Voids == 100
#include <iostream>
using namespace std;

#endif

int main()
{
    cout << __func__ << endl;    // ��ȡ��ǰ������
    cout << __DATE__ << endl;    // �ļ��ı�������
    cout << __TIME__ << endl;    // ��ǰת����Ԫ��ת��ʱ��
    cout << __FILE__ << endl;    // Դ�ļ�������
    cout << __LINE__ << endl;    // ��ǰ���к�
    cout << __cplusplus << endl; //

    ////main
    ////Dec 17 2022
    ////02:05:01
    ////Ԥ����ָ����߼�.cpp
    ////19
    ////201402
}
