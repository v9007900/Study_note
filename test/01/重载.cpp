#include <iostream>
#include <ostream>
#include <windows.h>
#include <xmemory>
using namespace std;

class Role {
private: // 私有

    int *m_a;
    int *m_b;

public: // 共有

    friend ostream &operator<<(ostream &cout, Role &p); // 友元

    Role(int &ma, int &mb)
    {
        m_a = new int(ma);
        m_b = new int(mb);
        cout << m_a << "-Role-" << *m_a << endl;
        cout << m_b << "-Role-" << *m_b << endl;
    }
    ~Role()
    {
        if (m_a != NULL) {
            delete m_a;
            m_a = NULL;
        }

        if (m_b != NULL) {
            delete m_b;
            m_b = NULL;
        }
    }

    void Read()
    {
        cout << m_a << "-void-" << *m_a << endl;
        cout << m_b << "-void-" << *m_b << endl;
    }
};

void Add(int &c, int &d) { Role p1(c, d); }
int  main()
{
    int a {10}, b {15};
    // Add(a, b);
    int c, d;

    Role p2(a, b);

    p2.Read();
}
