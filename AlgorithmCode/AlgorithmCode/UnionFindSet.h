#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

//将一个值包装成元素Element
template<typename T>
class Element
{
public:
	T value;
	Element(T _value)
	{
		value = _value;
	}
};

//并查集的创建
template<typename T>
class UnionFindSet
{
public:
	unordered_map<T, shared_ptr<Element<T>>> elementMap;//一个值代表元素
	unordered_map<shared_ptr<Element<T>>, shared_ptr<Element<T>>> fatherMap;//一个元素与它指向的父元素
	//一个集合的头元素才有集合的大小的值
	unordered_map<shared_ptr<Element<T>>, int> sizeMap;//sizeMap中存放每个集合的头元素与它的值
	//初始化
	UnionFindSet(vector<T> list)
	{
		
		for (T value : list)
		{
			shared_ptr<Element<T>> element = make_shared<Element<T>>(value);//将所有值包装成元素
			elementMap[value] = element;//将值与元素对应
			fatherMap[element] = element;//每个元素初始独立，自己指向自己
			sizeMap[element] = 1;//每个元素初始都是头元素
		}
	}
	//查找两个值是否在同一个集合中
	bool isSameSet(T a, T b)
	{
		//如果a和b都注册过元素，才进行判断，否则直接返回false
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			//当两个元素的头元素是相同的时候，才能证明这两个元素在同一个集合
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;
	}
	//合并两个集合
	void Union(T a, T b)
	{
		//如果a和b都注册过元素，才能进行合并，否则就忽略
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			shared_ptr<Element<T>> aF = findHead(elementMap[a]);//寻找a的头元素
			shared_ptr<Element<T>> bF = findHead(elementMap[b]);//寻找b的头元素
			if (aF != bF)//两个头元素不相等才合并
			{
				shared_ptr<Element<T>> big = sizeMap[aF] > sizeMap[bF] ? aF : bF;//返回较大集合的头元素
				shared_ptr<Element<T>> small = big == aF ? bF : aF;//返回较小集合的头元素
				fatherMap[small] = big;//小集合挂上大集合
				sizeMap[big] = sizeMap[big] + sizeMap[small];//新集合的头元素是big，更新big的size值
				sizeMap.erase(small);//删除small元素的头元素属性size
			}
		}
	}
private:
	//寻找一个元素的头元素
	shared_ptr<Element<T>> findHead(shared_ptr<Element<T>> element)
	{
		stack<shared_ptr<Element<T>>> path;//声明一个栈
		while (element != fatherMap[element])//不断向上找父元素
		{
			path.push(element);//入栈
			element = fatherMap[element];//更新element
		}
		while (!path.empty())//遍历栈
		{
			fatherMap[path.top()] = element;//将此集合的这一条路径的所有元素都指向头元素，就是扁平化集合
			path.pop();
		}
		return element;
	}
};