#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

typedef struct BTNode
{
	int data;
	struct BTNode* left;
	struct BTNode* right;
	BTNode(int val) :
		data(val), left(NULL), right(NULL) {}
}BTNode;

//�ݹ�ͳһ��Ϣ��
typedef struct Info
{
	int nodes;
	int height;
	Info(int _nodes, int _height) :
		nodes(_nodes), height(_height) {}
}Info;

//�����������ṹ��Binary search tree��
template<class T>
class  BSTNode
{
public:
	T data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	BSTNode(T val) :
		data(val), left(NULL), right(NULL), parent(NULL) {}
};

class binaryTree
{
private:
	BTNode* root, * p, * r, * temp;
public:
	binaryTree(int nums[], int arrayLength);
	binaryTree();
	BTNode* getRoot();
	void Forder(BTNode* root);
	/*
	�ǵݹ���Ϊ���������
	����ջ������һ��ջ�ṹ������ջͷ�ڵ㣬Ȼ��������²�����
	1.��ջһ���ڵ�car
	2.���car
	3.����ջcar�ҽڵ㣬����ջcar��ڵ�
	4.����1
	������
	*/
	void ForderUnRecur(BTNode* root);
	void Iorder(BTNode* root);
	/*
	�ǵݹ���Ϊ���������
	����һ��ջ������ջͷ�ڵ㣬Ȼ��
	1.������ջջ�ڵ�һ��Ԫ�ص���ڵ㣬ֱ��Ϊ�ա�
	2.��ջ�ڵ�car�����
	3.����ڵ�car�ҽڵ㲻Ϊ�գ���ջcar�ҽڵ㣬��������
	4.����1
	��������
	*/
	void IorderUnRecur(BTNode* root);
	void Porder(BTNode* root);
	/*
	�ǵݹ���Ϊ���������
	��������ջ��һ������ջ��һ���ռ�ջ���Ƚ�ͷ�ڵ���ջ����ջ��Ȼ��
	1.����ջ��ջһ���ڵ�car
	2.����ջ����ջcar��ڵ㣬����ջcar�ҽڵ�
	3.car��ջ�ռ�ջ
	4.����1
	����ջ����ռ�ջ��
	*/
	void PorderUnRecur(BTNode* root);
	//���ù�ϣ��ķ�����
	//https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=7777.2
	//ʹ�ù�ϣ��ķ�����
	int DepthOrder(BTNode* root);
	//�ж��Ƿ��Ƕ�������������ÿ���ڵ�node���������ڵ㶼С��node���������ڵ㶼����node����û���ظ��ڵ㡣
	int preValue = INT_MIN;
	bool checkBST(BTNode* root);
	//�ݹ鷽ʽ��
	bool checkBST2(BTNode* root);
	void process2(BTNode* root, list<BTNode*> inOrderList);

	//�ж��Ƿ�����ȫ��������
	bool isCBT(BTNode* root);

	//�ж��Ƿ�����������
	//��·�ݹ鷽ʽ��
	bool isFT(BTNode* root);

	//������·�ݹ�
	Info FT(BTNode* root);
	//���������ڵ�o1��o2����͹������ȣ�LCA��
	//��һ�ַ�ʽ�ǣ���������ϣ��<BTNode* node,BTNode* father> <BTNode*>,��һ���������нڵ��¼�丸�ڵ㣬�ڶ���������o1�����и��ڵ㣬Ȼ�����ζԱ�o2��ÿ�����ڵ㡣
	//�ڶ��֣����ֳ���ķ���������һ��o1��o2��ΪLCA ����o1��o2����������ȷʵ��ĳ��LCA
	BTNode* lowestAncestor(BTNode* root, BTNode* o1, BTNode* o2);

	//���غ�̽ڵ㣨һ���ڵ����һ���������������Ľڵ㣩
	BSTNode<int>* getSuccessorNode(BSTNode<int>* root);
	//��������ڵ�
	BSTNode<int>* getLeftMost(BSTNode<int>* root);
};