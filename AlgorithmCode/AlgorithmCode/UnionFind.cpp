#include "UnionFind.h"

template<typename T>
inline UnionFind::Element<T>::Element(T _value)
{
	value = _value;
}

template<typename T>
inline UnionFind::UnionFindSet<T>::UnionFindSet(vector<T> list)
{
	for (T value : list)
	{
		Element<T> element = Element<T>(value);//将所有值包装成元素
		elementMap[value] = element;//将值与元素对应
		fatherMap[element] = element;//每个元素初始独立，自己指向自己
		sizeMap[element] = 1;//每个元素初始都是头元素
	}
}
//查找两个值是否在同一个集合中
template<typename T>
bool UnionFind::UnionFindSet<T>::isSameSet(T a, T b)
{
	//如果a和b都注册过元素，才进行判断，否则直接返回false
	if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
	{
		//当两个元素的头元素是相同的时候，才能证明这两个元素在同一个集合
		return findHead(elementMap[a]).value == findHead(elementMap[b]).value;
	}
	return false;
}
//合并两个集合
template<typename T>
void UnionFind::UnionFindSet<T>::Union(T a, T b)
{
	//如果a和b都注册过元素，才能进行合并，否则就忽略
	if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
	{
		Element<T> aF = findHead(elementMap[a]);//寻找a的头元素
		Element<T> bF = findHead(elementMap[b]);//寻找b的头元素
		if (aF.value != bF.value)//两个头元素不相等才合并
		{
			Element big = sizeMap[aF] > sizeMap[bF] ? aF : bF;//返回较大集合的头元素
			Element small = big.value == aF.value ? bF : aF;//返回较小集合的头元素
			fatherMap[small] = big;//小集合挂上大集合
			sizeMap[big] = sizeMap[big] + sizeMap[small];//新集合的头元素是big，更新big的size值
			sizeMap.erase(small);//删除small元素的头元素属性size
		}
	}
}

//向上查找此元素的头元素
template<typename T>
UnionFind::Element<T> UnionFind::UnionFindSet<T>::findHead(Element<T> element)
{
	stack<Element<T>> path;//声明一个栈
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