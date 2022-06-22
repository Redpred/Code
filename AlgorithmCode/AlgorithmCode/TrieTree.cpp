#include "TrieTree.h"

using namespace std;

//TrieNode::TrieNode()
//{
//	pass = 0;
//	end = 0;
//	memset(nexts, NULL, sizeof(TrieNode*) * 26);
//}

TrieTree::TrieTree()
{
	root = new TrieNode();
}
//插入
void TrieTree::insert(string word)
{
	if (word.empty())
		return;

	TrieNode* node = root;
	node->pass++;
	int index = 0;

	for (int i = 0; i < word.size(); i++)
	{
		index = word[i] - 'a';

		if (node->nexts[index] == NULL)
			node->nexts[index] = new TrieNode();
		node = node->nexts[index];
		node->pass++;
	}
	node->end++;
}
//在树中删除word痕迹
void TrieTree::deleteTrie(string word)
{
	if (search(word) != 0)
	{
		TrieNode* node = root;
		TrieNode* tmp;
		node->pass--;
		int index = 0;
		int indextmp = 0;

		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			tmp = node->nexts[index];
			if (--node->nexts[index]->pass == 0)
				delete node->nexts[index];
			node = tmp;
		}
		node->end--;
	}
}
//以word结尾的字符串有几个
int TrieTree::search(string word)
{
	if (word.empty())
		return 0;

	TrieNode* node = root;
	int index = 0;

	for (int i = 0; i < word.size(); i++)
	{
		index = word[i] - 'a';
		if (node->nexts[index] == NULL)
			return 0;
		node = node->nexts[index];
	}
	return node->end;
}
//以pre为前缀的字符串在树中有几个
int TrieTree::prefixNumber(string pre)
{
	if (pre.empty())
		return 0;

	TrieNode* node = root;
	int index = 0;

	for (int i = 0; i < pre.size(); i++)
	{
		index = pre[i] - 'a';
		if (node->nexts[index] == NULL)
			return 0;
		node = node->nexts[index];
	}
	return node->pass;
}