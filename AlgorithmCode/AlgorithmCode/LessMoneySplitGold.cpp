#include "LessMoneySplitGold.h"

using namespace std;
/*
切金条问题：
切割一块金条，一条长度为20的金条不管切成多长的两半，都要花费20元
一群人想要整分整块金条，怎么分最省钱？
比如给定数组{10,20,30}，代表三个分长度60的金条。
*/
/*
思路是反向建立大根堆
用优先队列也就是小根堆，将数组所有数据录入
取出最小的两个数，做结合成大根堆
将结合的大根堆的堆顶数送入队列
再取出最小的两个数，再结合
重复
最后堆顶的数就是结果
*/
int lessMoney(int arr[], int arrLength)
{
	priority_queue<int> pQ;
	for (int i = 0; i < arrLength; i++)
		pQ.push(arr[i]);
	int sum = 0;
	int cur = 0;
	while (!pQ.empty())
	{
		int tmp = pQ.top();
		pQ.pop();
		cur = pQ.top() + tmp;
		pQ.pop();
		sum += cur;
		pQ.push(cur);
	}
	return sum;
}