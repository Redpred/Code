#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

class UnionFind
{
	//��һ��ֵ��װ��Ԫ��Element
	template<typename T>
	class Element
	{
	public:
		T value;
		Element(T _value);
	};

	//���鼯�Ĵ���
	template<typename T>
	class UnionFindSet
	{
	public:
		unordered_map<T, Element<T>> elementMap;//һ��ֵ����Ԫ��
		unordered_map<Element<T>, Element<T>> fatherMap;//һ��Ԫ������ָ��ĸ�Ԫ��
		//һ�����ϵ�ͷԪ�ز��м��ϵĴ�С��ֵ
		unordered_map<Element<T>, int> sizeMap;//sizeMap�д��ÿ�����ϵ�ͷԪ��������ֵ
		//��ʼ��
		UnionFindSet(vector<T> list);
		//��������ֵ�Ƿ���ͬһ��������
		bool isSameSet(T a, T b);
		//�ϲ���������
		void Union(T a, T b);
	private:
		//Ѱ��һ��Ԫ�ص�ͷԪ��
		Element<T> findHead(Element<T> element);
	};
};