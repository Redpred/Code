#include "ReverseStackUsingRecursive.h"

using namespace std;

//逆序一个栈，要求使用递归

//逆序一个栈
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
//返回栈的栈底，其他元素向下压
int ReverseStackUsingRecursive::f(stack<int>& fStack)
{
	int result = fStack.top();//取栈顶
	fStack.pop();
	if (fStack.empty())
	{
		return result;//返回栈底元素
	}
	int last = f(fStack);//调用子函数，不断向栈底调用
	fStack.push(result);//压回元素
	return last;//将栈底元素不断向上返回
}
