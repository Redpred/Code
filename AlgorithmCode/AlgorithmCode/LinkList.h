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
	//����
	LinkList();
	//�����������������
	~LinkList();
	//�������������һ��
	void clearSqList();
	//�ж��Ƿ�һ��
	bool isEmpty();
	//��ȡ������
	int Length();
	//��ȡָ��λ�õ�Ԫ��
	bool GetElem(int i, int* e);
	//����Ԫ��e������ʲôλ��
	int LocateElem(int e);
	//ȡ��һ��Ԫ��
	bool PriorElem(int cur_e, int* pre_e);
	//ȡ��һ��Ԫ��
	bool NextElem(int cur_e, int* next_e);
	//��ָ��λ�ò���Ԫ��e
	bool Insert(int i, int e);
	//ɾ��ָ��λ�õ�Ԫ�أ�����ɾ����Ԫ�ظ���*e
	bool Delete(int i, int* e);
	//��ת����
	Node* Reverse();
};