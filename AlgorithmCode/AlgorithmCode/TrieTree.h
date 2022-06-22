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
	int pass;//�����������ַ����Ĵ���
	int end;//��������β���ַ���������
	TrieNode* nexts[26];//��������һ����
	//TrieNode();
};

class TrieTree
{
private:
	TrieNode* root;//���ڵ�
public:
	TrieTree();
	void insert(string word);
	void deleteTrie(string word);
	int search(string word);
	int prefixNumber(string pre);
};
