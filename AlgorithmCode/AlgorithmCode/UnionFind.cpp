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
		Element<T> element = Element<T>(value);//������ֵ��װ��Ԫ��
		elementMap[value] = element;//��ֵ��Ԫ�ض�Ӧ
		fatherMap[element] = element;//ÿ��Ԫ�س�ʼ�������Լ�ָ���Լ�
		sizeMap[element] = 1;//ÿ��Ԫ�س�ʼ����ͷԪ��
	}
}
//��������ֵ�Ƿ���ͬһ��������
template<typename T>
bool UnionFind::UnionFindSet<T>::isSameSet(T a, T b)
{
	//���a��b��ע���Ԫ�أ��Ž����жϣ�����ֱ�ӷ���false
	if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
	{
		//������Ԫ�ص�ͷԪ������ͬ��ʱ�򣬲���֤��������Ԫ����ͬһ������
		return findHead(elementMap[a]).value == findHead(elementMap[b]).value;
	}
	return false;
}
//�ϲ���������
template<typename T>
void UnionFind::UnionFindSet<T>::Union(T a, T b)
{
	//���a��b��ע���Ԫ�أ����ܽ��кϲ�������ͺ���
	if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
	{
		Element<T> aF = findHead(elementMap[a]);//Ѱ��a��ͷԪ��
		Element<T> bF = findHead(elementMap[b]);//Ѱ��b��ͷԪ��
		if (aF.value != bF.value)//����ͷԪ�ز���Ȳźϲ�
		{
			Element big = sizeMap[aF] > sizeMap[bF] ? aF : bF;//���ؽϴ󼯺ϵ�ͷԪ��
			Element small = big.value == aF.value ? bF : aF;//���ؽ�С���ϵ�ͷԪ��
			fatherMap[small] = big;//С���Ϲ��ϴ󼯺�
			sizeMap[big] = sizeMap[big] + sizeMap[small];//�¼��ϵ�ͷԪ����big������big��sizeֵ
			sizeMap.erase(small);//ɾ��smallԪ�ص�ͷԪ������size
		}
	}
}

//���ϲ��Ҵ�Ԫ�ص�ͷԪ��
template<typename T>
UnionFind::Element<T> UnionFind::UnionFindSet<T>::findHead(Element<T> element)
{
	stack<Element<T>> path;//����һ��ջ
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