#include "binaryTree.h"

using namespace std;

/*
https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=3237.1
��������
������
����һ���������������ҡ���¼ÿ�ν����
�����������1
		2		3
	4	  5  6		7
�������Ϊ��124442555213666377731
ÿ���ڵ㶼���������Σ���ô��
���������ͷ���ң��������������ĵ�һ�α�����1245367
�����������ͷ�ң��������������ĵڶ��α�����4251637
�������������ͷ���������������ĵ����α�����4526731
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
�ǵݹ���Ϊ���������
����ջ������һ��ջ�ṹ������ջͷ�ڵ㣬Ȼ��������²�����
1.��ջһ���ڵ�car
2.���car
3.����ջcar�ҽڵ㣬����ջcar��ڵ�
4.����1
������
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
�ǵݹ���Ϊ���������
����һ��ջ������ջͷ�ڵ㣬Ȼ��
1.������ջջ�ڵ�һ��Ԫ�ص���ڵ㣬ֱ��Ϊ�ա�
2.��ջ�ڵ�car�����
3.����ڵ�car�ҽڵ㲻Ϊ�գ���ջcar�ҽڵ㣬��������
4.����1
��������
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
�ǵݹ���Ϊ���������
��������ջ��һ������ջ��һ���ռ�ջ���Ƚ�ͷ�ڵ���ջ����ջ��Ȼ��
1.����ջ��ջһ���ڵ�car
2.����ջ����ջcar��ڵ㣬����ջcar�ҽڵ�
3.car��ջ�ռ�ջ
4.����1
����ջ����ռ�ջ��
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
//���ù�ϣ��ķ�����
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=6&t=7777.2
//ʹ�ù�ϣ��ķ�����
int binaryTree::DepthOrder(BTNode* root)
{
	if (root == NULL)
		return 0;
	BTNode* cur;
	queue<BTNode*> queue;
	queue.push(root);
	unordered_map<BTNode*, int> levelMap;//��¼�ڵ����ڲ���
	levelMap.insert({ root,1 });

	int curLevel = 1;//ͳ�ƵĲ���
	int curLevelNodes = 0;//��ǰ��ڵ���
	int max = 1;//���в��У��Ĳ�ڵ������Ľڵ���

	while (!queue.empty())
	{
		cur = queue.front();
		queue.pop();//����һ���ڵ�
		int curNodeLevel = levelMap.find(cur)->second;//ȡ��һ���ڵ�ʱ�õ����Ĳ���
		if (curNodeLevel == curLevel)//��ǰ�ڵ�� ���� ͳ�Ʋ��� ʱ
			curLevelNodes++;
		else//���Ѿ�������һ��ʱ����������һ��
		{
			if (max < curLevelNodes)
				max = curLevelNodes;//ȡĿǰͳ�����ڵ����Ĳ����Ľڵ���
			curLevel++;//ͳ�ƵĲ���+1
			curLevelNodes = 1;//��ǰ��Ľڵ�����1
		}
		if (cur->left != NULL)
		{
			levelMap.insert({ cur->left,curNodeLevel + 1 });//��¼
			queue.push(cur->left);
		}
		if (cur->right != NULL)
		{
			levelMap.insert({ cur->right,curNodeLevel + 1 });//��¼
			queue.push(cur->right);
		}
	}
	return max > curLevelNodes ? max : curLevelNodes;//���ж����һ��
}
//�ж��Ƿ��Ƕ�������������ÿ���ڵ�node���������ڵ㶼С��node���������ڵ㶼����node����û���ظ��ڵ㡣
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
//�ݹ鷽ʽ��
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

//�ж��Ƿ�����ȫ��������
bool binaryTree::isCBT(BTNode* root)
{
	if (root == NULL)
		return true;
	queue<BTNode*> queue;
	bool leaf = false;//�Ƿ����������ҽڵ㲻˫ȫ�Ľڵ�
	BTNode* l = NULL;
	BTNode* r = NULL;
	queue.push(root);
	while (!queue.empty())
	{
		root = queue.front();
		queue.pop();
		l = root->left;
		r = root->right;
		//���Ӧ�ô���һ��leaf�ڵ㣬�����жϣ�
		//����һ���˽ڵ����ҽڵ�     ��������leafΪ�浫ȴ���ӽڵ�
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

//�ж��Ƿ�����������
//��·�ݹ鷽ʽ��
bool binaryTree::isFT(BTNode* root)
{
	if (root == NULL)
		return true;
	Info data = FT(root);
	return data.nodes == ((1 << data.height) - 1);//�����������㣺�ܽڵ���=���߶�/2-1
}
//������·�ݹ�
Info binaryTree::FT(BTNode* root)
{
	if (root == NULL)
		return Info(0, 0);

	Info leftData = FT(root->left);//������������Ϣ
	Info rightData = FT(root->right);//������������Ϣ

	int nodes = leftData.nodes + rightData.nodes + 1;//���������ҽڵ��� + ���������ҽڵ��� + ���ڵ���
	int height = fmax(leftData.height, rightData.height) + 1;//����������������ĸ߶� + ����߶�

	return Info(nodes, height);//���ش˸��ڵ������Ϣ
}
//���������ڵ�o1��o2����͹������ȣ�LCA��
//��һ�ַ�ʽ�ǣ���������ϣ��<BTNode* node,BTNode* father> <BTNode*>,��һ���������нڵ��¼�丸�ڵ㣬�ڶ���������o1�����и��ڵ㣬Ȼ�����ζԱ�o2��ÿ�����ڵ㡣
//�ڶ��֣����ֳ���ķ���������һ��o1��o2��ΪLCA ����o1��o2����������ȷʵ��ĳ��LCA
BTNode* binaryTree::lowestAncestor(BTNode* root, BTNode* o1, BTNode* o2)
{
	if (root == NULL || root == o1 || root == o2)//����һ�ж�
		return root;
	BTNode* left = lowestAncestor(root->left, o1, o2);
	BTNode* right = lowestAncestor(root->right, o1, o2);
	if (left != NULL && right != NULL)//���·��жϣ���o1��o2�����������������������˽ڵ������������
		return root;
	return left != NULL ? left : right;//�����ҽڵ�Ϊ�ջ��߲���o1��o2ʱ�����ؿգ�����o1��o2ʱ����o1��o2�����ж��ܲ������Ϸ���o1��o2 ����еĻ���
}

//���غ�̽ڵ㣨һ���ڵ����һ���������������Ľڵ㣩
BSTNode<int>* binaryTree::getSuccessorNode(BSTNode<int>* root)
{
	if (root == NULL)
		return root;
	if (root->right != NULL)//�����������������������ڵ���Ǻ�̽ڵ�
		return	getLeftMost(root->right);
	else//��������
	{
		BSTNode<int>* parent = root->parent;
		while (root->parent != NULL && parent->left != root)//�����ڵĽڵ�Ϊ���ڵ���ҽڵ�
		{
			root = parent;//����
			parent = root->parent;
		}
	}
	return root->parent;//�����������жϣ�ֱ��rooΪparent����ڵ� ���� parentΪ��û�к�̽ڵ�
}
//��������ڵ�
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