#include "ReverseStackUsingRecursive.h"

using namespace std;

//����һ��ջ��Ҫ��ʹ�õݹ�

//����һ��ջ
void ReverseStackUsingRecursive::Reverse(stack<int>& reverseStack)
{
	if (reverseStack.empty())
	{
		return;
	}
	int result = f(reverseStack);
	Reverse(reverseStack);
	reverseStack.push(result);
}
//����ջ��ջ�ף�����Ԫ������ѹ
int ReverseStackUsingRecursive::f(stack<int>& fStack)
{
	int result = fStack.top();//ȡջ��
	fStack.pop();
	if (fStack.empty())
	{
		return result;//����ջ��Ԫ��
	}
	int last = f(fStack);//�����Ӻ�����������ջ�׵���
	fStack.push(result);//ѹ��Ԫ��
	return last;//��ջ��Ԫ�ز������Ϸ���
}
