#include "hanoi.h"

using namespace std;

//汉诺塔问题
hanoi::hanoi(int n)
{
	times = 0;//记录移动次数
	if (n > 0)
		func(n, "左", "右", "中");
	cout << "一共有 " << times << " 个步骤" << endl;
}
void hanoi::func(int n, string from, string to, string other)
{
	//base case
	if (n == 1)//以最小块为结尾
	{
		cout << "第 1 从 " + from + " 到 " + to << endl;
		times++;
	}
	//以抽象的思维方式思考
	//将塔块分为最底下一块和它上面的所有块
	else
	{
		func(n - 1, from, other, to);//先将上面的移动到“临时”上
		cout << "第 " << n << " 从 " + from + " 到 " + to << endl;//打印一块移动到“目的”上
		times++;
		func(n - 1, other, to, from);//将“临时”的移动回“原来”的
	}
}