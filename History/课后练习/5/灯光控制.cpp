#include <iostream>
#include <windows.h>
#include <bitset>
using namespace std;

// ����1յ�Ƶ���� ������յ��  ����iΪ��Ҫ���Ƶ��ǵڼ�յ�� ����default_dll_lamp Ϊ��ǰ�ƹ�����
unsigned oneControlOpen(unsigned asaa, unsigned �ƹ�)
{
    // unsigned asaa{ 0b00000000000000000000000000001000 }; asaa����ʾ��
    �ƹ� |= asaa;

    return �ƹ�;
}
unsigned oneControlShut(unsigned asaa, unsigned �ƹ�)
{
    �ƹ� &= asaa;

    return �ƹ�;
}
// 1�ֽ�8λ ���ǿ��Ƶƹ�ֻ��2��״̬ �ոպ�ʹ��16������F ��0

int main()
{

    // �趨����Ϊ1 �ص�Ϊ0
    // ʹ�� unsigned  ��ֹλ������ָ���0��1���������

    unsigned �ƹ�{0b00000000001000000000000000000000}; //Ĭ�ϵƹ�

    cout << "Ĭ�ϵƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);
    // unsigned all_lamp{ 0b11111111111111111111111111111111 };

    //------------------------Before �����ƹ����------------------------
    �ƹ� = oneControlOpen(0b1000, �ƹ�);
    cout << "���Ʋ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);

    �ƹ� = oneControlShut(0b11111111111111111111111111110111, �ƹ�);
    cout << "�صƲ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);
    //------------------------End �����ƹ����------------------------

    //------------------------Before ����ƹ����------------------------

    //���򿪹ص� ������Ϊ16����
    �ƹ� = oneControlOpen(0xFF, �ƹ�);
    cout << "���򿪵Ʋ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);
    �ƹ� = oneControlShut(0xFFFFFF00, �ƹ�);
    cout << "����صƲ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);
    //------------------------End ����ƹ����------------------------

    //------------------------Before ȫ���ƹ����------------------------
    �ƹ� = oneControlOpen(0xFFFFFFFF, �ƹ�);
    cout << "ȫ�����Ʋ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);

    �ƹ� = oneControlShut(0, �ƹ�);
    cout << "ȫ���صƲ���-��ǰ�ƹ�״̬��" << std::bitset<32>(�ƹ�) << char(10);
    //------------------------End  ȫ���ƹ����------------------------
}
