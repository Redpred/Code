#include "binaryTree.h"

using namespace std;

/*
https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=3237.1
二叉树：
遍历：
遍历一遍二叉树，先左后右。记录每次结果。
比如二叉树：1
		2		3
	4	  5  6		7
遍历结果为：124442555213666377731
每个节点都遍历了三次，那么：
先序遍历（头左右）：输出遍历结果的第一次遍历：1245367
中序遍历（左头右）：输出遍历结果的第二次遍历：4251637
后序遍历（左右头）：输出遍历结果的第三次遍历：4526731
*/

binaryTree::binaryTree(int nums[], int arrayLength)
{
	root = new BTNode(nums[0]);
	for (int i = 1; i < arrayLength; i++)
	{
		temp = new BTNode(nums[i]);
		r = root;
		while (r)
		{
			p = r;
			if (r->data < temp->data)
				r = r->right;
			else
				r = r->left;
		}
		if (p->data < temp->data)
			p->right = temp;
		else
			p->left = temp;
	}
}
binaryTree::binaryTree()
{
	p = NULL;
	r = NULL;
	temp = NULL;
	root = new BTNode(1);
	root->left = new BTNode(2);
	root->right = new BTNode(3);
	root->left->left = new BTNode(4);
	root->left->right = new BTNode(5);
	root->right->left = new BTNode(6);
	root->right->right = new BTNode(7);
}
BTNode* binaryTree::getRoot()
{
	return root;
}
void binaryTree::Forder(BTNode* root)
{
	if (root)
	{
		cout << root->data << " ";
		Forder(root->left);
		Forder(root->right);
	}
}
/*
非递归行为先序遍历：
利用栈，申请一个栈结构，先入栈头节点，然后进行如下操作：
1.出栈一个节点car
2.输出car
3.先入栈car右节点，再入栈car左节点
4.返回1
最后输出
*/
void binaryTree::ForderUnRecur(BTNode* root)
{
	if (root)
	{
		stack<BTNode*> stack;
		stack.push(root);
		while (!stack.empty())
		{
			root = stack.top();
			stack.pop();
			cout << root->data << " ";
			if (root->right != NULL)
				stack.push(root->right);
			if (root->left != NULL)
				stack.push(root->left);
		}
	}
}
void binaryTree::Iorder(BTNode* root)
{
	if (root)
	{
		Iorder(root->left);
		cout << root->data << " ";
		Iorder(root->right);
	}
}
/*
非递归行为中序遍历：
申请一个栈，先入栈头节点，然后：
1.不断入栈栈内第一个元素的左节点，直到为空。
2.出栈节点car并输出
3.如果节点car右节点不为空，入栈car右节点，否则跳过
4.返回1
最后输出。
*/
void binaryTree::IorderUnRecur(BTNode* root)
{
	if (root)
	{
		stack<BTNode*> stack;
		while (!stack.empty() || root != NULL)
		{
			if (root != NULL)
			{
				stack.push(root);
				root = root->left;
			}
			else
			{
				root = stack.top();
				cout << root->data << " ";
				stack.pop();
				root = root->right;
			}
		}
	}
}
void binaryTree::Porder(BTNode* root)
{
	if (root)
	{
		Porder(root->left);
		Porder(root->right);
		cout << root->data << " ";
	}
}
/*
非递归行为后序遍历：
申请两个栈，一个操作栈，一个收集栈，先将头节点入栈操作栈，然后：
1.操作栈出栈一个节点car
2.操作栈先入栈car左节点，后入栈car右节点
3.car入栈收集栈
4.返回1
最后出栈输出收集栈。
*/
void binaryTree::PorderUnRecur(BTNode* root)
{
	if (root)
	{
		stack<BTNode*> stack1;
		stack<BTNode*> stack2;
		stack1.push(root);
		while (!stack1.empty())
		{
			root = stack1.top();
			stack1.pop();
			stack2.push(root);
			if (root->left != NULL)
				stack1.push(root->left);
			if (root->right != NULL)
				stack1.push(root->right);
		}
		while (!stack2.empty())
		{
			cout << stack2.top()->data << " ";
			stack2.pop();
		}
	}
}
//不用哈希表的方法：
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=7777.2
//使用哈希表的方法：
int binaryTree::DepthOrder(BTNode* root)
{
	if (root == NULL)
		return 0;
	BTNode* cur;
	queue<BTNode*> queue;
	queue.push(root);
	unordered_map<BTNode*, int> levelMap;//记录节点所在层数
	levelMap.insert({ root,1 });

	int curLevel = 1;//统计的层数
	int curLevelNodes = 0;//当前层节点数
	int max = 1;//所有层中，哪层节点数最多的节点数

	while (!queue.empty())
	{
		cur = queue.front();
		queue.pop();//弹出一个节点
		int curNodeLevel = levelMap.find(cur)->second;//取出一个节点时得到它的层数
		if (curNodeLevel == curLevel)//当前节点层 等于 统计层数 时
			curLevelNodes++;
		else//当已经来到下一层时，两层数不一样
		{
			if (max < curLevelNodes)
				max = curLevelNodes;//取目前统计最大节点数的层数的节点数
			curLevel++;//统计的层数+1
			curLevelNodes = 1;//当前层的节点数归1
		}
		if (cur->left != NULL)
		{
			levelMap.insert({ cur->left,curNodeLevel + 1 });//记录
			queue.push(cur->left);
		}
		if (cur->right != NULL)
		{
			levelMap.insert({ cur->right,curNodeLevel + 1 });//记录
			queue.push(cur->right);
		}
	}
	return max > curLevelNodes ? max : curLevelNodes;//再判断最后一层
}
//判断是否是二叉搜索树：对每个节点node，左子树节点都小于node，右子树节点都大于node，且没有重复节点。
bool binaryTree::checkBST(BTNode* root)
{
	if (root == NULL)
		return true;
	bool isLeftBst = checkBST(root->left);
	if (!isLeftBst)
		return false;
	if (root->data <= preValue)
		return false;
	else
		preValue = root->data;
	return checkBST(root->right);
}
//递归方式：
bool binaryTree::checkBST2(BTNode* root)
{
	list<BTNode*> inOrderList;
	process2(root, inOrderList);
	int min = INT_MIN;
	while (inOrderList.front() != NULL)
	{
		if (inOrderList.front()->data < min)
			return false;
		min = inOrderList.front()->data;
		inOrderList.pop_front();
	}
	return true;
}
void binaryTree::process2(BTNode* root, list<BTNode*> inOrderList)
{
	if (root == NULL)
		return;
	process2(root->left, inOrderList);
	inOrderList.push_back(root);
	process2(root->right, inOrderList);
}

//判断是否是完全二叉树：
bool binaryTree::isCBT(BTNode* root)
{
	if (root == NULL)
		return true;
	queue<BTNode*> queue;
	bool leaf = false;//是否遇到过左右节点不双全的节点
	BTNode* l = NULL;
	BTNode* r = NULL;
	queue.push(root);
	while (!queue.empty())
	{
		root = queue.front();
		queue.pop();
		l = root->left;
		r = root->right;
		//最多应该存在一次leaf节点，所以判断：
		//条件一：此节点有右节点     条件二：leaf为真但却有子节点
		if ((l == NULL && r != NULL) || (leaf && (l != NULL || r != NULL)))
			return false;
		if (l != NULL)
			queue.push(l);
		if (r != NULL)
			queue.push(r);
		if (l == NULL || r == NULL)
			leaf = true;
	}
	return true;
}

//判断是否是满二叉树
//套路递归方式：
bool binaryTree::isFT(BTNode* root)
{
	if (root == NULL)
		return true;
	Info data = FT(root);
	return data.nodes == ((1 << data.height) - 1);//满二叉树满足：总节点数=树高度/2-1
}
//无脑套路递归
Info binaryTree::FT(BTNode* root)
{
	if (root == NULL)
		return Info(0, 0);

	Info leftData = FT(root->left);//返回左子树信息
	Info rightData = FT(root->right);//返回右子树信息

	int nodes = leftData.nodes + rightData.nodes + 1;//左子树左右节点数 + 右子树左右节点树 + 本节点数
	int height = fmax(leftData.height, rightData.height) + 1;//左右子树最高子树的高度 + 本层高度

	return Info(nodes, height);//返回此根节点的树信息
}
//返回两个节点o1和o2的最低公共祖先（LCA）
//第一种方式是，用两个哈希表<BTNode* node,BTNode* father> <BTNode*>,第一个遍历所有节点记录其父节点，第二个是收入o1的所有父节点，然后依次对比o2的每个父节点。
//第二种，有种抽象的方法：条件一：o1、o2互为LCA 返回o1或o2，条件二：确实有某个LCA
BTNode* binaryTree::lowestAncestor(BTNode* root, BTNode* o1, BTNode* o2)
{
	if (root == NULL || root == o1 || root == o2)//条件一判断
		return root;
	BTNode* left = lowestAncestor(root->left, o1, o2);
	BTNode* right = lowestAncestor(root->right, o1, o2);
	if (left != NULL && right != NULL)//由下方判断，将o1和o2从左右子树都返回上来，此节点符合条件二。
		return root;
	return left != NULL ? left : right;//当左右节点为空或者不是o1、o2时都返回空，遇到o1、o2时返回o1、o2。此判断能不断向上返回o1或o2 如果有的话。
}

//返回后继节点（一个节点的下一个以中序遍历排序的节点）
BSTNode<int>* binaryTree::getSuccessorNode(BSTNode<int>* root)
{
	if (root == NULL)
		return root;
	if (root->right != NULL)//如果有右子树，右子树最左节点就是后继节点
		return	getLeftMost(root->right);
	else//无右子树
	{
		BSTNode<int>* parent = root->parent;
		while (root->parent != NULL && parent->left != root)//当现在的节点为父节点的右节点
		{
			root = parent;//更新
			parent = root->parent;
		}
	}
	return root->parent;//当不断向上判断，直到roo为parent的左节点 或者 parent为空没有后继节点
}
//返回最左节点
BSTNode<int>* binaryTree::getLeftMost(BSTNode<int>* root)
{
	if (root == NULL)
		return root;
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}