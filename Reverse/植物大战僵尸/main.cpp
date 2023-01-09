#include "ncdx.h"
int main()
{
    int Yg = R4(R4(R4(0x6A9EC0) + 0x768) + 0x5560);    // Yg=阳光  R4=读写的意思，这里需要读最后的值，需要读3次
    UINT_PTR Ygdz = R4(R4(0x6A9EC0) + 0x768) + 0x5560; // Ygdz=阳光地址,UINT_PTR用来表示无符号指针，具有通用性，在64位的占用8个字节
    printf("阳光=%d\n", Yg);
    printf("阳光地址=%X\n", Ygdz);
    W4(Ygdz, 99999);
    getchar(); //等待键盘输入
}