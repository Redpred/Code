#include "ConvertToLetterString.h"

using namespace std;

/*
����һ�������ַ�������ת����������ĸ�ַ���
A��Ӧ1~Z��Ӧ26 ��������������һ������ɲ�ͬ��ĸ���ܽ�����ɶ�����
*/
int ConvertToLetterString::process(string str, int i)//i���ַ�λ��
{
	//��i�����ַ������ȣ�����1
	if (i == str.size())
	{
		return 1;
	}
	//������Ϊ[0~i-1]���Ѿ���������i��ʼ�����iλ���ַ�Ϊ0����ôi֮���λ��Ҳ���ܺ�i�����
	if (str[i] == '0')
	{
		return 0;
	}
	if (str[i] == '1')
	{
		//[0~9]��һ�ֿ��ܣ�Ҳ����ֻ��iλ�á�
		int res = process(str, i + 1);
		//����ܺ�i+1λ����ϣ���ô����[10~19]
		if ((i + 1) < str.size())
		{
			res += process(str, i + 2);
		}
		return res;
	}
	if (str[i] == '2')
	{
		//ͬ'1'
		int res = process(str, i + 1);
		//����Ҫ����i+1λ�õ�����[0~6]��Χ
		if ((i + 1) < str.size() && (str[i + 1] >= '0' && str[i + 1] <= '6'))
		{
			res += process(str, i + 2);
		}
		return res;
	}
	//ʣ�µľ���[3~9]��Χ�ģ�û��Ҫ��
	return process(str, i + 1);
}
