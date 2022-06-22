#pragma once
#include <iostream>
#include <stack>

using namespace std;

typedef stack<int> STACKINT;
//����ڵ�
typedef struct Node
{
	int date;
	struct Node* next;
	Node(int val) :
		date(val), next(NULL) {}
}Node;


//��������
class Palindromes
{
public:
	STACKINT stack;

	//Node* head = (Node*) malloc (sizeof(Node));//��ʼ��
	Node* head = new Node(0);
	Node* p = head;//���߽ڵ�
	int listnums[9] = { 1,2,3,4,5,4,3,2,1 };//���������

	Node* S;
	Node* F;

	Palindromes();
	//�������
	~Palindromes();

	bool isPalindromes();
};