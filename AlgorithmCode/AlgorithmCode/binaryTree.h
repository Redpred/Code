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

//递归统一信息体
typedef struct Info
{
	int nodes;
	int height;
	Info(int _nodes, int _height) :
		nodes(_nodes), height(_height) {}
}Info;

//二叉搜索树结构（Binary search tree）
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
	非递归行为先序遍历：
	利用栈，申请一个栈结构，先入栈头节点，然后进行如下操作：
	1.出栈一个节点car
	2.输出car
	3.先入栈car右节点，再入栈car左节点
	4.返回1
	最后输出
	*/
	void ForderUnRecur(BTNode* root);
	void Iorder(BTNode* root);
	/*
	非递归行为中序遍历：
	申请一个栈，先入栈头节点，然后：
	1.不断入栈栈内第一个元素的左节点，直到为空。
	2.出栈节点car并输出
	3.如果节点car右节点不为空，入栈car右节点，否则跳过
	4.返回1
	最后输出。
	*/
	void IorderUnRecur(BTNode* root);
	void Porder(BTNode* root);
	/*
	非递归行为后序遍历：
	申请两个栈，一个操作栈，一个收集栈，先将头节点入栈操作栈，然后：
	1.操作栈出栈一个节点car
	2.操作栈先入栈car左节点，后入栈car右节点
	3.car入栈收集栈
	4.返回1
	最后出栈输出收集栈。
	*/
	void PorderUnRecur(BTNode* root);
	//不用哈希表的方法：
	//https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=7777.2
	//使用哈希表的方法：
	int DepthOrder(BTNode* root);
	//判断是否是二叉搜索树：对每个节点node，左子树节点都小于node，右子树节点都大于node，且没有重复节点。
	int preValue = INT_MIN;
	bool checkBST(BTNode* root);
	//递归方式：
	bool checkBST2(BTNode* root);
	void process2(BTNode* root, list<BTNode*> inOrderList);

	//判断是否是完全二叉树：
	bool isCBT(BTNode* root);

	//判断是否是满二叉树
	//套路递归方式：
	bool isFT(BTNode* root);

	//无脑套路递归
	Info FT(BTNode* root);
	//返回两个节点o1和o2的最低公共祖先（LCA）
	//第一种方式是，用两个哈希表<BTNode* node,BTNode* father> <BTNode*>,第一个遍历所有节点记录其父节点，第二个是收入o1的所有父节点，然后依次对比o2的每个父节点。
	//第二种，有种抽象的方法：条件一：o1、o2互为LCA 返回o1或o2，条件二：确实有某个LCA
	BTNode* lowestAncestor(BTNode* root, BTNode* o1, BTNode* o2);

	//返回后继节点（一个节点的下一个以中序遍历排序的节点）
	BSTNode<int>* getSuccessorNode(BSTNode<int>* root);
	//返回最左节点
	BSTNode<int>* getLeftMost(BSTNode<int>* root);
};