#include "Knapsack.h"

using namespace std;

/*
������ͬ���ȵ�����weight��value���ֱ�����iλ�õ���Ʒ�������ͼ�ֵ��
��һ������bag��������bag��С������bag����֮ǰ�ܻ�õ�����ֵ�Ƕ���
*/

int Knapsack::process(const vector<int>& weight, const vector<int>& value, int i, int alreadyWeight, int alreadyValue, int bag)
{
	//�������ֱ�ӷ���0
	if (alreadyWeight > bag)
	{
		return 0;
	}
	//������Χ����0
	if (i == weight.size())
	{
		return alreadyValue;
	}
	//����ѡ��ȡ���
	return max(process(weight, value, i + 1, alreadyWeight, alreadyValue, bag),//��ѡ�����Ʒ�Ļ���ֻi+1����������
		process(weight, value, i + 1, alreadyWeight + weight[i], alreadyValue + value[i], bag));//ѡ�������Ʒ��alreadyValue����value[i]��ͬʱalreadyWight + weight[i]
}
