#include "manacher.h"

/*
����manacher�㷨��Ҫ����һ�����İ뾶����pArr��
i : ��ǰ���е��±�
C : ��ǰ��������Ĵ������ĵ�λ��
R : ��ǰ�����Ĵ����ұ߽�
i': i���������ĵ�C��λ��
�ܷ���ٻ��Ĵ����ж��������ĸ���
1�� i > R
2�� i < R && i���ұ߽� <  R
3�� i < R && i���ұ߽� == R
4�� i < R && i���ұ߽� >  R
ִ�з�ʽ��
1��ֱ���������������¼pArr[i] ����C��R
2����¼pArr[i] = pArr[2 * C - i]
3����¼pArr[i] = R - i
4��
*/

manacher::manacher(string s)
{
	if (s.size() == 0)//�߽��ж�
	{
		return;
	}
	string str = manacherString(s);//�޸�ԭ�ַ���
	vector<int> pArr(str.size());//���İ뾶����
	int C = -1;//����
	int R = -1;//��Ч�ұ߽����һ���±�
	int Max = INT_MIN;//�����������ֵ
	for (int i = 0; i != str.size(); i++)
	{
		//������һ�������ٲ�����֤������
		pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;//��i����R��ʱ���������pArr[i] = 1��ʣ�µ�3�������ȡpArr[2 * C - i]��R - i������С

		//���ѭ���ǽ�һ��ǰ��д����4���ж���������
		//���������2��3  ��ô�Ͳ������������ͻ�break
		//���������1��4  ��ô�ͻ�ɹ�������
		//���岻��Ӱ��ʱ�临�Ӷ� �����ܼ��ж�����
		while (i + pArr[i] < str.size() && i - pArr[i] > -1)//�߽��ж�
		{
			if (str[i + pArr[i]] == str[i - pArr[i]])
			{
				pArr[i]++;
			}
			else
			{
				break;
			}
		}
		//����C��R
		if (i + pArr[i] > R)
		{
			R = i + pArr[i];
			C = i;
		}
		Max = max(Max, pArr[i]);//����Max
	}
	cout << Max - 1 << endl;//���ص������Ĵ��ĳ���
}

//��һ���ַ�����ÿһ���ַ��м��һ��#  ���罫123 ��Ϊ #1#2#3#
string manacher::manacherString(string str)
{
	string res = str + str + ' ';
	int index = 0;
	for (int i = 0; i != str.size() * 2 + 1; i++)
	{
		res[i] = (i & 1) == 0 ? '#' : str[index++];
	}
	return res;
}
