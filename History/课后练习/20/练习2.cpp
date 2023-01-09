#include <iostream>
#include <windows.h>
using namespace std;

class Cube
{
  private:     ////   ˽��
    int m_l{}; ////   ��
    int m_w{}; ////   ��
    int m_h{}; ////   ��

  public: //// ����
    ////д�� ��
    void setl(int l)
    {m_l = l;}
    ////д�� ��
    void setw(int w)
    {m_w = w;}
    ////д�� ��
    void seth(int h)
    {m_h = h;}

    ////��ȡ���������
    int calculates()
    {return 2 * m_h * m_w + 2 * m_w * m_h + 2 * m_l * m_h;}
    ////��ȡ���������
    int calculatev()
    {return m_l * m_w * m_h;}

    bool Compares(Cube& c)
    {
        if (m_l == c.m_l && m_h == c.m_h && m_w == c.m_w)
            return true;
        return false;
    }
};

bool Compare(Cube& c1, Cube& c2)
{
    if (c1.calculates() == c2.calculates())
        return true;
    return false;
}

int main()
{
    Cube c1{};
    Cube c2{};
    c1.setl(10);
    c1.setw(10);
    c1.seth(10);
    c2.setl(10);
    c2.setw(10);
    c2.seth(11);
    cout << "C1�����Ϊ:" << c1.calculates() << endl;
    cout << "C1�����Ϊ:" << c1.calculatev() << endl;
    cout << "C1�����Ϊ:" << c2.calculates() << endl;
    cout << "C1�����Ϊ:" << c2.calculatev() << endl;

    bool ret = Compare(c1, c2);
    if (ret)
        cout << "c1==c2" << endl;
    else
        cout << "c1!=c2" << endl;

    ret = c1.Compares(c2);
    if (ret)
        cout << "c1==c2" << endl;
    else
        cout << "c1!=c2" << endl;
}
