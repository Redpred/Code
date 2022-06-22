#include "listSort.h"

using namespace std;

/*
无序映射（Unordered maps）是用于存储键值和映射值组合成的元素的关联容器，并允许基于其键快速检索各个元素。
在unordered_map中，键值通常用于唯一的标识元素，而映射值是具有与该键关联的内容的对象。键的类型和映射的值可能会有所不同。
*/

/*
内部实现
unordered_map内部实现了一个哈希表也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录。
查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用。因此，其元素的排列顺序是无序的。
*/

/*
优点：因为内部实现了哈希表，因此其查找速度非常的快
缺点：哈希表的建立比较耗费时间
应用场景：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map
*/

/*
对于Key，如果是基础类型，是值传递，会将赋值的值拷贝到哈希表中的Key，内存占用是这个值的大小。
		如果是一个类或者其他的什么，是引用传递，内存占用一律是8字节的内存地址。
*/


//当想要对非基础类型排序时，需要自定义一个比较器来规定排序规则

listSort::listSort()
{
	unorderedMap ulist;
	ulist.insert({ 1,2 });//插入
	ulist[2] = 2;//插入
	auto it = ulist.find(1);//查找，如果没有这个Key，则返回表最后一个Key的下一个迭代器
	ulist.erase(2);//删除
	cout << it->first << "," << it->second << endl;
	cout << ulist.find(1)->second << endl;
	if (ulist.find(2) == ulist.end())
		cout << "没有找到Key为2的值" << endl;

	orderedMap olist;
}