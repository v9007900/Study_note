#include <iostream>
#include <windows.h>
using namespace std;

namespace ttt//todo 命名空间的扩展
{
    int addx;
}
namespace ttt //!! 命名空间的别名
{
    namespace stde
    {
        int stdee{100};
    }
    int xdda;
} // namespace ttt

namespace //?? 未命名的命名空间
{
    void Thack()
    {
        cout << "Thack!";
    }
} // namespace

namespace add = ttt::stde; //!! 命名空间的别名

int main()
{
    cout << add::stdee << endl; //!! 命名空间的别名
    Thack();                    ////当有重复名时，只能调用当前文件内的

    cout << ttt::addx << endl; // todo 命名空间的扩展
    cout << ttt::xdda << endl; // todo 命名空间的扩展
} // namespace ass=int main()

