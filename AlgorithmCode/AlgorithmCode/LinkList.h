#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

typedef struct node {
	int date;
	struct node* next;
}Node;

class LinkList
{
private:
	Node* head;
public:
	//构建
	LinkList();
	//析构，结束清空链表
	~LinkList();
	//清空链表，和析构一样
	void clearSqList();
	//判断是否一致
	bool isEmpty();
	//获取链表长度
	int Length();
	//获取指定位置的元素
	bool GetElem(int i, int* e);
	//查找元素e在链表什么位置
	int LocateElem(int e);
	//取上一个元素
	bool PriorElem(int cur_e, int* pre_e);
	//取下一个元素
	bool NextElem(int cur_e, int* next_e);
	//在指定位置插入元素e
	bool Insert(int i, int e);
	//删除指定位置的元素，并把删除的元素赋给*e
	bool Delete(int i, int* e);
	//反转链表
	Node* Reverse();
};