#include <iostream>
#include <windows.h>
using namespace std;

class Cube
{
  private:     ////   私域
    int m_l{}; ////   长
    int m_w{}; ////   宽
    int m_h{}; ////   高

  public: //// 公开
    ////写入 长
    void setl(int l)
    {m_l = l;}
    ////写入 宽
    void setw(int w)
    {m_w = w;}
    ////写入 高
    void seth(int h)
    {m_h = h;}

    ////获取立方体面积
    int calculates()
    {return 2 * m_h * m_w + 2 * m_w * m_h + 2 * m_l * m_h;}
    ////获取立方体体积
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
    cout << "C1的面积为:" << c1.calculates() << endl;
    cout << "C1的体积为:" << c1.calculatev() << endl;
    cout << "C1的面积为:" << c2.calculates() << endl;
    cout << "C1的体积为:" << c2.calculatev() << endl;

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
