#include "KMP.h"

int KMP::getIndexOf(const string& s, const string& m)
{
	//���ж�Խ������
	if (s.empty() || m.empty() || m.size() < 1 || s.size() < m.size())
	{
		return -1;
	}
	int i1 = 0;//�ַ���s���±�ָ��
	int i2 = 0;//�ַ���m���±�ָ��
	vector<int> next = getNextArray(m);

	while (i1 < s.size() && i2 < m.size())//ֱ����һ��ָ��Խ��
	{
		if (s[i1] == m[i2])//��������ַ�ƥ������ָ
		{
			i1++;
			i2++;
		}
		else if (next[i2] == -1)//���m�ַ����������ֱ������m[0]������
		{
			i1++;//s�ַ���Ӧ������ָ��
		}
		else //����ƥ���ʱ��m�ַ��������next[i2]����
		{
			i2 = next[i2];//Ҳ����i2ָ��ָ��next[i2]
		}
	}
	//i1Խ���˾ͷ���-1��i2Խ����˵���ҵ���ƥ���λ�ã�����i1 - i2
	return i2 == m.size() ? i1 - i2 : -1;
}
/*
�����ǻ�á��������ַ�������һ������ͬǰ׺��׺�������������
��ν����ͬǰ׺��׺���������ָ��
����ms�ĵ�i�ַ������ܵ�֪i�ַ�ǰ����n���ַ�������[0,n-1] == [i-n,i-1]
���磺
�ַ���ms = "abbxcabbm";
��ô�����ַ�m��˵��m��ӦֵӦ����3����Ϊ��mǰ����[0,2]��abb��[5,7]��abb��ͬ��������ͬ��������
��ô�����getNextArray����ms���ص�����Ӧ����{-1,0,0,0,0,0,0,0,3}
�����ַ���{abaxabam}����{-1,0,0,1,0,1,2,3}
*/
vector<int> KMP::getNextArray(const string& ms)
{
	if (ms.size() == 1)//�߽�����
	{
		return vector<int>{ -1 };
	}
	vector<int> next(ms.size());//��ʼ��next
	next[0] = -1;//Ĭ�ϳ�ʼ��
	next[1] = 0;
	int i = 2;//next��λ�� ��ʼΪ2
	int cn = 0;//cn = next[i-1]
	while (i < next.size())//����next
	{
		//���ַ���ms��ms[i - 1] == ms[cn]ʱ��˵��next[i]������cn+1�������÷�֤�ķ�ʽ֤��
		if (ms[i - 1] == ms[cn])
		{
			next[i++] = ++cn;//һ�н��������ֲ���������next[i]=cn+1;i++;cn++;
		}
		//���ms[i - 1] != ms[cn]ʱ����cn = next[cn]���ٷ�����һ��if
		else if (cn > 0)
		{
			cn = next[cn];
		}
		else//ֱ��cn = -1��Ҳ����next[i]û�з�����������
		{
			next[i++] = 0;//next[i] = 0����i++;
		}
	}
	return next;
}