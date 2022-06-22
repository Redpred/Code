#include "printAllSubsquence.h"

using namespace std;

//��ӡ���������� ���ַ���Ϊ��
//���ַ�ʽ���ڶ��ֱȽ�ʡ�ռ� 
printAllSubsquence::printAllSubsquence(string str)
{
	int times = 0;
	vector<string> res = function(str);
	for (const auto& item : res)
	{
		cout << item << endl;
		times++;
	}
	cout << times << endl;
}
//һ���ַ���������ÿһ�����ַ������������ַ���
//str���ַ�����n���ַ�λ�ã���ʼ��0��res��һ�����ַ���������
void printAllSubsquence::process(string str, int n, vector<char> res)
{
	//base case ����
	//��n�ﵽstr���ȣ�˵��������һ���ַ����������һ�����ַ�����
	if (n == str.size())
	{
		for (const auto& item : res)
		{
			cout << item;
		}
		cout << endl;
		return;
	}
	//ѡ��Ӧ�ñ������ַ�����resKeep��
	vector<char> resKeep = res;
	resKeep.push_back(str[n]);
	process(str, n + 1, resKeep);//��resKeep������һ�ε�res
	//�޳���Ӧ�ñ������ַ��������ַ�����resNoInclude
	vector<char> resNoInclude = res;
	resNoInclude.push_back(' ');
	process(str, n + 1, resNoInclude);//��resNoInclude������һ�ε�res
}
//��һ�ֵ��Ż�����ʡ�˿ռ�
void printAllSubsquence::process(string str, int n)
{
	//base case ����
	if (n == str.size())
	{
		cout << str << endl;//���������ַ����������Ѿ��޳�����Ҫ����
		return;
	}
	//������Ҫ���ַ���
	process(str, n + 1);
	//�޳�����Ҫ���ַ��ٷ���
	char tmp = str[n];//������Ҫһ��λ�õ��ַ�ʱ������tmp�ٽ�ԭλ�ñ�Ϊ��
	str[n] = 0;
	process(str, n + 1);
	//��ԭ
	str[n] = tmp;//��tmp�Ż�ԭλ��
}
//����һ���ַ����ĸ�������ʽ��ͬʱ�޳��ظ���
//�ַ���strʹ��ͬһ���ڴ�ռ䣬n�����ַ�λ�ã�res�������ַ�����������Ҳ��֤ͬһ��
void printAllSubsquence::process(string* str, int n, vector<string>* res)
{
	//base case
	if (n == (*str).size())
	{
		(*res).push_back((*str));//��Ϊ������ԭ��ʼ�մ���str����
		return;
	}
	//�ӵ�0λ�ÿ�ʼ��n������������λ���Ǵ�n��ʼ��������������������
	for (int j = n; j < (*str).size(); j++)
	{
		swap(str, n, j);
		process(str, n + 1, res);
		swap(str, n, j);
	}
}
//���ص���һ���ַ�������������ÿһԪ�ض���һ���ַ�������
//ע��ʼ�ձ�������resΪͬһ�������������n��������ÿ���������һ������󷵻ؿ�������
//�ַ���Ҳ��Ҫʼ��ʹ��ͬһ�ڴ�ռ䣬������process�ķ�ʽ�����ġ�
vector<string> printAllSubsquence::function(string str)
{
	vector<string> res;
	if (str.size() == 0)
	{
		return res;
	}
	process(&str, 0, &res);//ʹ������
	return res;
}
//�����ַ����е������ַ�
void printAllSubsquence::swap(string* str, int i, int j)
{
	char tmp = (*str)[i];
	(*str)[i] = (*str)[j];
	(*str)[j] = tmp;
}

