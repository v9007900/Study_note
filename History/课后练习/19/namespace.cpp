#include <iostream>
#include <windows.h>
using namespace std;

namespace ttt//todo �����ռ����չ
{
    int addx;
}
namespace ttt //!! �����ռ�ı���
{
    namespace stde
    {
        int stdee{100};
    }
    int xdda;
} // namespace ttt

namespace //?? δ�����������ռ�
{
    void Thack()
    {
        cout << "Thack!";
    }
} // namespace

namespace add = ttt::stde; //!! �����ռ�ı���

int main()
{
    cout << add::stdee << endl; //!! �����ռ�ı���
    Thack();                    ////�����ظ���ʱ��ֻ�ܵ��õ�ǰ�ļ��ڵ�

    cout << ttt::addx << endl; // todo �����ռ����չ
    cout << ttt::xdda << endl; // todo �����ռ����չ
} // namespace ass=int main()

