#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setfill('0');
    for (int x = 0; x < 10; x++)
    {
        if (x == 0)
            continue; //��ǰ�غϲ�ִ��
        if (x > 5)
            break;
        for (int y = 0; y < 10; y++)
        {
            if (y == 0)
                continue; //��ǰ�غϲ�ִ��
            cout << setw(2) << y * x << " ";
            _sleep(5); //�ӳ�
        }
        cout << endl;
    }
}