#include "hanoi.h"

using namespace std;

//��ŵ������
hanoi::hanoi(int n)
{
	times = 0;//��¼�ƶ�����
	if (n > 0)
		func(n, "��", "��", "��");
	cout << "һ���� " << times << " ������" << endl;
}
void hanoi::func(int n, string from, string to, string other)
{
	//base case
	if (n == 1)//����С��Ϊ��β
	{
		cout << "�� 1 �� " + from + " �� " + to << endl;
		times++;
	}
	//�Գ����˼ά��ʽ˼��
	//�������Ϊ�����һ�������������п�
	else
	{
		func(n - 1, from, other, to);//�Ƚ�������ƶ�������ʱ����
		cout << "�� " << n << " �� " + from + " �� " + to << endl;//��ӡһ���ƶ�����Ŀ�ġ���
		times++;
		func(n - 1, other, to, from);//������ʱ�����ƶ��ء�ԭ������
	}
}