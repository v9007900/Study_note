#include "ncdx.h"
int main()
{
    int Yg = R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560);    // Yg=����  R4=��д����˼��������Ҫ������ֵ����Ҫ��3��
    UINT_PTR Ygdz = R4(R4(0x6A9EC0) + 0x768) + 0x5560; // Ygdz=�����ַ,UINT_PTR������ʾ�޷���ָ�룬����ͨ���ԣ���64λ��ռ��8���ֽ�
    printf("����=%d\n", Yg);
    printf("�����ַ=%X\n", Ygdz);
    W4(Ygdz, 99999);
    getchar(); //�ȴ���������
}