#pragma once
#include <iostream>

using namespace std;

class heapSort
{
public:
	heapSort(int arr[], int arrayLength);
	//������һ������ʱ����������븸�ڵ㲻�ϱȽϣ����������ƣ���󵽴������ڵĵط�
	void heapInsert(int arr[], int index);
	void swap(int arr[], int i, int j);
	//����ǰλ�õĶѽṹ�нϴ������������λ��
	void heapify(int arr[], int index, int heapSize);
	void printArray(int arr[], int arrayLength);
};