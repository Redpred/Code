#include "Palindromes.h"

/*
���������������⣺
https://www.bilibili.com/video/BV1NU4y1M7rF?p=5&t=4671.6
*/

using namespace std;

Palindromes::Palindromes()
{
	//��listnums���鴫�ݸ�����
	for (int val : listnums)
	{
		Node* q = new Node(val);
		p->next = q;
		p = p->next;
	}
	head = head->next;
	p = head;//ͷ�ڵ�Ӧ�޳�

	S = head;
	F = S;

	//����ָ��,�۰��ת����
	while (F->next != NULL)
	{
		F = F->next;
		S = S->next;
		if (F->next != NULL)
			F = F->next;
		else
			break;
	}
	//��ת���������
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

	//����������۰봫�ݸ�ջ
	/*for (;S != NULL;S = S->next)
		stack.push(S->date);*/

		//���
	for (Node* i = head; i != NULL; i = i->next)
		cout << i->date;

	//�ж��ǲ��ǻ�������
	if (isPalindromes())
		cout << " �ǻ�������";
	else
		cout << " ���ǻ�������";

	//��ת���������
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
//�������
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
	//ʹ��ջ���жϷ�ʽ
	/*p = head;
	while (!stack.empty())
	{
		if (p->date != stack.top())
			return false;
		stack.pop();
		p = p->next;
	}*/
	return true;
	//��ת������жϷ�ʽ
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