#include "NQueens.h"

NQueens::NQueens(int n)
{
	cout << nums1(n) << endl;
	cout << nums2(n) << endl;
}
int NQueens::nums1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	vector<int> record;//�Ѿ���¼�Ļʺ�λ��
	return process1(0, record, n);
}
//�Ľ���������λ���㣬���Բ��ܳ���32�ʺ�
int NQueens::nums2(int n)
{
	if (n < 1 || n>32)
	{
		return 0;
	}
	int limit = (n == 32) ? -1 : (1 << n) - 1;//����limit�ĺ�����Ƕ����ƴ�����������ǰn����1������ȫ��0
	/*����������N�ʺ����̾ͱ��limit * limit�����̣����� 5�ʺ�����̾ͱ�ɣ�
	17��0|1  1  1  1  1
	17��0|1  1  1  1  1
	17��0|1  1  1  1  1
	17��0|1  1  1  1  1
	17��0|1  1  1  1  1
	*/
	return process2(limit, 0, 0, 0);
}
//i ��ǰ����
int NQueens::process1(int i, vector<int>& record, int n)
{
	//base case
	if (i == n)
	{
		return 1;
	}
	int res = 0;//���صĽ��
	record.push_back(0);//����
	for (int j = 0; j < n; j++)
	{
		//��ǰ��i�еĻʺ��������j�л᲻���[0,i-1]�еĻʺ��й��й�б��
		//��� true ����Ϊ��Ч
		//��� false����Ϊ��Ч
		if (isValid(record, i, j))
		{
			record[i] = j;
			res += process1(i + 1, record, n);
		}
	}
	return res;
}
//�����������������ƣ�����Ҫ�󣺶��������У�1��λ�ò��ܷŻʺ�0��λ�ÿ��ԷŻʺ�
//colLim���е����ơ�leftDiaLim:��б�ߵ����ơ�rightDiaLim����б�ߵ�����
//���������⣬�����������ں��治�ϵݹ����ǲ������ӵģ����ǵ�����һ��λ�õ�����
//�����ڵ�һ��colLim=1���ڶ���colLim=4+1 �����Ƶ�101 �����˵�һ�е�1
int NQueens::process2(int limit, int colLim, int leftDiaLim, int rightDiaLim)
{
	//���Ե�colLim���������̵�n�е�limit��n��λ�þͽ�����
	if (colLim == limit)
	{
		return 1;
	}
	int mostRightOne = 0;//ָ���������ұߵ���
	//pos������ ȡ��ǰ�е������ܷŻʺ��λ��
	//colLim | leftDiaLim | rightDiaLim ���������Ƶ�λ�����
	//��ô��ȡ��֮�� '������'limit ����ɸѡ��ʣ���ܷŻʺ��λ����
	int pos = limit & (~(colLim | leftDiaLim | rightDiaLim));
	int res = 0;//���صĽ��
	while (pos != 0)
	{
		mostRightOne = pos & (~pos + 1);//ȡ���������ұߵ���
		pos = pos - mostRightOne;//ȡ�������pos
		res += process2(limit, colLim | mostRightOne, //���������� ���
			(leftDiaLim | mostRightOne) << 1, //���������� ��ΪҪб�� ����������һλ
			(rightDiaLim | mostRightOne) >> 1);//���������� ������һλ
		//���������ǣ����������� ���൱��ѡ�������λ�ã�Ҳ����mostRightOneλ��
	}
	return res;
}

bool NQueens::isValid(const vector<int>& record, int i, int j)
{
	//ֻ����[0,i-1]�Ļʺ�
	//�����i������Ҫ�ŵĻʺ������,j��������ʺ�Ҫ�ŵ�����
	for (int k = 0; k < i; k++)
	{
		//  ���е����      ��         �� �о���   ==  �о��� �� Ҳ����������45��н�
		if (j == record[k] || abs(j - record[k]) == abs(i - k))
		{
			return false;
		}
	}
	return true;
}