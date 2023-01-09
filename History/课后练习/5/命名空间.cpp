#include <iostream>
#include <windows.h>

// using namespace std;

namespace People // 名称空间 人
{
	int HP(500);  //血量 500
	int MP(800);  //蓝条 800
	int PS(600);  //体力 600
	int ATK(100); //攻击 100

	namespace Equipment //子级 名称空间 武器
	{
		int TheSword(100); //剑
		int Axe(200);	   //斧
	}
}

int bloodVolume;

int main()
{
	system("mode con cols=60 lines=20");
	system("color 8E");
	using namespace People; //使用仓库类的所有命令  不包括子级
	using std::cin;			//指定使用仓库类的cin
	using std::cout;		//指定使用仓库类的cout
	int STK = ATK + Equipment ::TheSword;
	cout << "攻击力:" << STK << char(10);
	cout << "HP:" << HP << char(10) << "MP:" << MP << char(10) << "PS:" << PS;
	return 0;
}
