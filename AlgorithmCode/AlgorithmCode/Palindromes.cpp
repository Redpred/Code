#include "Palindromes.h"

/*
回文数串的链表题：
https://www.bilibili.com/video/BV1NU4y1M7rF?p=5&t=4671.6
*/

using namespace std;

Palindromes::Palindromes()
{
	//将listnums数组传递给链表
	for (int val : listnums)
	{
		Node* q = new Node(val);
		p->next = q;
		p = p->next;
	}
	head = head->next;
	p = head;//头节点应剔除

	S = head;
	F = S;

	//快慢指针,折半调转方向
	while (F->next != NULL)
	{
		F = F->next;
		S = S->next;
		if (F->next != NULL)
			F = F->next;
		else
			break;
	}
	//调转后半链表方向
	Node* phead = S;
	Node* pre = NULL;
	Node* temp = NULL;
	while (phead != NULL)
	{
		temp = pre;
		pre = phead;
		phead = phead->next;
		pre->next = temp;
	}

	//将链表的数折半传递给栈
	/*for (;S != NULL;S = S->next)
		stack.push(S->date);*/

		//输出
	for (Node* i = head; i != NULL; i = i->next)
		cout << i->date;

	//判断是不是回文数串
	if (isPalindromes())
		cout << " 是回文数串";
	else
		cout << " 不是回文数串";

	//回转后半链表方向
	phead = pre;
	pre = NULL;
	while (phead != NULL)
	{
		temp = pre;
		pre = phead;
		phead = phead->next;
		pre->next = temp;
	}
}
//析构清空
Palindromes::~Palindromes()
{
	p = head;
	for (Node* i = head->next; i != NULL; i = i->next)
	{
		p->date = NULL;
		p->next = NULL;
		p = i;
	}
	p->date = NULL;
}

bool Palindromes::isPalindromes()
{
	//使用栈的判断方式
	/*p = head;
	while (!stack.empty())
	{
		if (p->date != stack.top())
			return false;
		stack.pop();
		p = p->next;
	}*/
	return true;
	//调转链表的判断方式
	p = head;
	while (p != NULL && F != NULL)
	{
		if (p->date != F->date)
			return false;
		p = p->next;
		F = F->next;
	}
	return true;
}