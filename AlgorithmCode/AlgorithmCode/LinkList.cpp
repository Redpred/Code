#include "LinkList.h"

using namespace std;

//构建
LinkList::LinkList()
{
	head = NULL;
}
//析构，结束清空链表
LinkList::~LinkList()
{
	Node* p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}
//清空链表，和析构一样
void LinkList::clearSqList()
{
	Node* p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}
//判断是否一致
bool LinkList::isEmpty() { return head == NULL; }
//获取链表长度
int LinkList::Length()
{
	Node* p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
//获取指定位置的元素
bool LinkList::GetElem(int i, int* e)
{
	Node* p = head;
	int j = 0;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	*e = p->date;
	return true;
}
//查找元素e在链表什么位置
int LinkList::LocateElem(int e)
{
	int i = 0;
	Node* p = head;
	while (p != NULL)
	{
		if (p->date == e)
			return i;
		else
			p = p->next;
		i++;
	}
	cout << "表中不存在指定元素" << endl;
}
//取上一个元素
bool LinkList::PriorElem(int cur_e, int* pre_e)
{
	Node* p = head;
	if (p->date == cur_e)
		return false; //是头节点，不存在上一个元素
	while (p->next != NULL)
	{
		if (p->next->date == cur_e)
		{
			*pre_e = p->date;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}
//取下一个元素
bool LinkList::NextElem(int cur_e, int* next_e)
{
	Node* p = head;
	if (head == NULL || head->next == NULL)
		return false;
	while (p->next != NULL)
	{
		if (p->date == cur_e)
		{
			*next_e = p->next->date;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}
//在指定位置插入元素e
bool LinkList::Insert(int i, int e)
{
	Node* p = head, * s;
	int j = 0;
	if (i == 0)
	{
		s = (Node*)new Node[1];
		s->date = e;
		s->next = p;
		head = s;
		return true;
	}
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	s = (Node*)new Node[1];
	s->date = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//删除指定位置的元素，并把删除的元素赋给*e
bool LinkList::Delete(int i, int* e)
{
	Node* p = head, * s;
	if (p == NULL)
		return false;
	int j = 0;
	if (i == 0)
	{
		head = head->next;
		*e = p->date;
		delete p;
		p = NULL;
		return true;
	}
	while (p && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (i == 0)
	{
		head = head->next;
		*e = p->date;
		delete p;
		p = NULL;
		return true;
	}
	while (p && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = p->next;
	p->next = p->next->next;
	*e = s->date;
	delete s;
	s = NULL;
	return true;
}
//反转链表
Node* LinkList::Reverse()
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* p = head, * q = head->next, * r;
	head->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}