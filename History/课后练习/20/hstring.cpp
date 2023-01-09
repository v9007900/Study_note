#include <iostream>
using namespace std;

class hstring
{
  private:
    char* c_str;

  public:
    hstring()
    {
        c_str = new char[1]{0};
    }

    hstring(const char* str)
    {
        c_str = (char*)str;
    }

    char* show() const
    {
        return c_str;
    }

    ~hstring()
    {
        delete[] c_str;
    }
};

int main()
{
    hstring str("你好！");
    cout << str.show();
}
