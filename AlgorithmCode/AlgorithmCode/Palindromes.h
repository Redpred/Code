#pragma once
#include <iostream>
#include <stack>

using namespace std;

typedef stack<int> STACKINT;
//链表节点
typedef struct Node
{
	int date;
	struct Node* next;
	Node(int val) :
		date(val), next(NULL) {}
}Node;


//回文数串
class Palindromes
{
public:
	STACKINT stack;

	//Node* head = (Node*) malloc (sizeof(Node));//初始化
	Node* head = new Node(0);
	Node* p = head;//工具节点
	int listnums[9] = { 1,2,3,4,5,4,3,2,1 };//输入的数串

	Node* S;
	Node* F;

	Palindromes();
	//析构清空
	~Palindromes();

	bool isPalindromes();
};