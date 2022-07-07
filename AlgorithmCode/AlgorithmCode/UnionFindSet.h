#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

//��һ��ֵ��װ��Ԫ��Element
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

//���鼯�Ĵ���
template<typename T>
class UnionFindSet
{
public:
	unordered_map<T, shared_ptr<Element<T>>> elementMap;//һ��ֵ����Ԫ��
	unordered_map<shared_ptr<Element<T>>, shared_ptr<Element<T>>> fatherMap;//һ��Ԫ������ָ��ĸ�Ԫ��
	//һ�����ϵ�ͷԪ�ز��м��ϵĴ�С��ֵ
	unordered_map<shared_ptr<Element<T>>, int> sizeMap;//sizeMap�д��ÿ�����ϵ�ͷԪ��������ֵ
	//��ʼ��
	UnionFindSet(vector<T> list)
	{
		
		for (T value : list)
		{
			shared_ptr<Element<T>> element = make_shared<Element<T>>(value);//������ֵ��װ��Ԫ��
			elementMap[value] = element;//��ֵ��Ԫ�ض�Ӧ
			fatherMap[element] = element;//ÿ��Ԫ�س�ʼ�������Լ�ָ���Լ�
			sizeMap[element] = 1;//ÿ��Ԫ�س�ʼ����ͷԪ��
		}
	}
	//��������ֵ�Ƿ���ͬһ��������
	bool isSameSet(T a, T b)
	{
		//���a��b��ע���Ԫ�أ��Ž����жϣ�����ֱ�ӷ���false
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			//������Ԫ�ص�ͷԪ������ͬ��ʱ�򣬲���֤��������Ԫ����ͬһ������
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;
	}
	//�ϲ���������
	void Union(T a, T b)
	{
		//���a��b��ע���Ԫ�أ����ܽ��кϲ�������ͺ���
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			shared_ptr<Element<T>> aF = findHead(elementMap[a]);//Ѱ��a��ͷԪ��
			shared_ptr<Element<T>> bF = findHead(elementMap[b]);//Ѱ��b��ͷԪ��
			if (aF != bF)//����ͷԪ�ز���Ȳźϲ�
			{
				shared_ptr<Element<T>> big = sizeMap[aF] > sizeMap[bF] ? aF : bF;//���ؽϴ󼯺ϵ�ͷԪ��
				shared_ptr<Element<T>> small = big == aF ? bF : aF;//���ؽ�С���ϵ�ͷԪ��
				fatherMap[small] = big;//С���Ϲ��ϴ󼯺�
				sizeMap[big] = sizeMap[big] + sizeMap[small];//�¼��ϵ�ͷԪ����big������big��sizeֵ
				sizeMap.erase(small);//ɾ��smallԪ�ص�ͷԪ������size
			}
		}
	}
private:
	//Ѱ��һ��Ԫ�ص�ͷԪ��
	shared_ptr<Element<T>> findHead(shared_ptr<Element<T>> element)
	{
		stack<shared_ptr<Element<T>>> path;//����һ��ջ
		while (element != fatherMap[element])//���������Ҹ�Ԫ��
		{
			path.push(element);//��ջ
			element = fatherMap[element];//����element
		}
		while (!path.empty())//����ջ
		{
			fatherMap[path.top()] = element;//���˼��ϵ���һ��·��������Ԫ�ض�ָ��ͷԪ�أ����Ǳ�ƽ������
			path.pop();
		}
		return element;
	}
};