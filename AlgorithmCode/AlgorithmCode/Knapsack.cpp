#include "Knapsack.h"

using namespace std;

/*
两个相同长度的数组weight和value，分别代表第i位置的物品的重量和价值。
有一个背包bag，限制了bag大小，求在bag放满之前能获得的最大价值是多少
*/

int Knapsack::process(const vector<int>& weight, const vector<int>& value, int i, int alreadyWeight, int alreadyValue, int bag)
{
	//如果超重直接返回0
	if (alreadyWeight > bag)
	{
		return 0;
	}
	//超出范围返回0
	if (i == weight.size())
	{
		return alreadyValue;
	}
	//两种选择取最大
	return max(process(weight, value, i + 1, alreadyWeight, alreadyValue, bag),//不选这个物品的话，只i+1，其他不变
		process(weight, value, i + 1, alreadyWeight + weight[i], alreadyValue + value[i], bag));//选择这个物品，alreadyValue加上value[i]，同时alreadyWight + weight[i]
}
