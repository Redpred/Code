#include "winerPoker.h"
#include <iostream>

using namespace std;

/*
给定一个整型数组arr，代表不同数值的牌排列一行，玩家A和玩家B依次拿走一张牌，
规定玩家A先拿玩家B后拿，每次只能拿走最左边或者最右边的牌，如果两人都绝顶聪明，
每人都能计算出拿到哪张牌的后果能让另一人得分少，返回胜者的分数。

比如：
arr = {1,2,100,4};
开始时，玩家A能拿走1或4。
但A不会拿走4，因为B接下来会拿走100。
那么A会拿走1，剩下{2，100，4}，那么不论B拿走2还是4，A都能拿下100，最后以101获胜。
*/

winerPoker::winerPoker(int arr[], int length)
{
	if (length == 0)
	{
		cout << 0 << endl;
	}
	//胜者条件，在先手和后手中选择最大的
	cout << max(F(arr, 0, length - 1), S(arr, 0, length - 1)) << endl;
}
//先手者
int winerPoker::F(int arr[], int i, int j)
{
	if (i == j)
	{
		return arr[i];//作为先手，当到达最后一张牌时，能直接拿走它
	}
	//作为先手，选择两种结果的最大
	return max(arr[i] + S(arr, i + 1, j)  //选择左边，后手选择（i+1，j）的结果
		, arr[j] + S(arr, i, j - 1));//选择右边，后手选择（i，j-1）的结果
}
//后手者
int winerPoker::S(int arr[], int i, int j)
{
	if (i == j)
	{
		return 0;//作为后手者，到达最后一张牌会被先手拿走，最后返回0
	}
	//作为后手，选择先手会更小的结果
	return min(F(arr, i + 1, j)  //先手选择（i+1，j）的结果
		, F(arr, i, j - 1));//先手选择（i，j-1）的结果
}