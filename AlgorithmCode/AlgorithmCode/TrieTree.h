#ifndef D_TRIETREE_H_
#define D_TRIETREE_H_
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <string>

#endif // !D_TRIETREE_H_

using namespace std;

class Trie;

class TrieNode
{
public:
	int pass;//经过这个点的字符串的次数
	int end;//在这个点结尾的字符串的数量
	TrieNode* nexts[26];//这个点的下一个点
	//TrieNode();
};

class TrieTree
{
private:
	TrieNode* root;//根节点
public:
	TrieTree();
	void insert(string word);
	void deleteTrie(string word);
	int search(string word);
	int prefixNumber(string pre);
};
