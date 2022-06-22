#include "LessMoneySplitGold.h"

using namespace std;
/*
�н������⣺
�и�һ�������һ������Ϊ20�Ľ��������гɶ೤�����룬��Ҫ����20Ԫ
һȺ����Ҫ���������������ô����ʡǮ��
�����������{10,20,30}�����������ֳ���60�Ľ�����
*/
/*
˼·�Ƿ����������
�����ȶ���Ҳ����С���ѣ���������������¼��
ȡ����С��������������ϳɴ����
����ϵĴ���ѵĶѶ����������
��ȡ����С�����������ٽ��
�ظ�
���Ѷ��������ǽ��
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