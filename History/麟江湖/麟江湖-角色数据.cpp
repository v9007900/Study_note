#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

enum class Sect : char // ö��  ����  ���ݷ�Χ��-127~128��
{
    Wudang,    // �䵱  ���ݷ�Χ��-127~128��
    MountEmei, // ��ü  ���ݷ�Χ��-127~128��
    Edoyun,    // ����  ���ݷ�Χ��-127~128��
    Sunflower, // ����  ���ݷ�Χ��-127~128��
    TangClan,  // ����  ���ݷ�Χ��-127~128��
};

struct Equipment // �ṹ�� װ��
{
    unsigned char LV{0}; // �ȼ�  ���ݷ�Χ0~255
    unsigned char EV{0}; // ǿ��  ���ݷ�Χ0~255
};

struct ATTRIBMAX // ��������
{
    int value{500};          // ��ǰ��ֵ  ���ݷ�Χ-2147483648~2147483647
    unsigned maxvalue{1000}; // ��ֵ����  ���ݷ�Χ 0~4294967295
    // ������unsigned ��ʾunsigned int �ܴ洢�����ݷ�Χ��0~4294967295
};

struct Role // �ṹ�� ��ɫ
{

    unsigned char LV{10};       // ����ȼ�   ���ݷ�Χ0~255
    Sect Sects{Sect::TangClan}; // �ṹ�� ����  ����ѡ��  ����
    Equipment Arms{9, 15};      // ����   ��Ӣ��,�ָ�
    Equipment Armor{8, 13};     // ����   ��Ӣ��,�ָ�
    Equipment Jewelr{11, 12};   // ����   ��Ӣ��,�ָ�
    long long exp{4515514};     // ����ֵ
    ATTRIBMAX HP{800, 1000};    // �ṹ�� ��������   HP ��ǰѪ�� ���Ѫ��
    ATTRIBMAX MP{200, 1000};    // �ṹ�� ��������   MP ��ǰ���� �������

    unsigned Money{1000};  // ���
    unsigned Diamond{500}; // ��ʯ
    unsigned char luck{6}; // ����ֵ
    unsigned vip_exp{20};  // �ۼ�����

    double X{124};
    double y{545};
    double Z{654};
};

int main()
{
    system("mode con cols=40 lines=20");
    system("color 8E");
    Role Lead; // �ṹ��-��ɫ ����
    cout << "�ȼ�:" << (int)Lead.LV << endl;
    cout << "����" << (int)Lead.Sects << endl;
    cout << "����:" << (int)Lead.Arms.LV << "��"
         << "ǿ��:+" << (int)Lead.Arms.EV << endl;
    cout << "����:" << (int)Lead.Armor.LV << "��"
         << "ǿ��:+" << (int)Lead.Armor.EV << endl;
    cout << "����:" << (int)Lead.Jewelr.LV << "��"
         << "ǿ��:+" << (int)Lead.Jewelr.EV << endl;
    cout << "����ֵ:" << Lead.exp << endl;
    cout << "����:[" << Lead.HP.value << "/" << Lead.HP.maxvalue << "]" << endl;
    cout << "����:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "����:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "����:[" << Lead.MP.value << "/" << Lead.MP.maxvalue << "]" << endl;
    cout << "X����:" << (int)Lead.X << "  Y����:" << Lead.y << "  Z����:" << Lead.Z << endl;
    cout << "���:" << Lead.Money << endl;
    cout << "��ʯ:" << Lead.Diamond << endl;
    cout << "����ֵ:" << (int)Lead.luck << endl;
    cout << "�ۼ�����:" << Lead.vip_exp << endl;
    return 0;
}
