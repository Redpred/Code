#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

class UnionFind
{
	//将一个值包装成元素Element
	template<typename T>
	class Element
	{
	public:
		T value;
		Element(T _value);
	};

	//并查集的创建
	template<typename T>
	class UnionFindSet
	{
	public:
		unordered_map<T, Element<T>> elementMap;//一个值代表元素
		unordered_map<Element<T>, Element<T>> fatherMap;//一个元素与它指向的父元素
		//一个集合的头元素才有集合的大小的值
		unordered_map<Element<T>, int> sizeMap;//sizeMap中存放每个集合的头元素与它的值
		//初始化
		UnionFindSet(vector<T> list);
		//查找两个值是否在同一个集合中
		bool isSameSet(T a, T b);
		//合并两个集合
		void Union(T a, T b);
	private:
		//寻找一个元素的头元素
		Element<T> findHead(Element<T> element);
	};
};