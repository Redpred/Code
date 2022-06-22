#pragma once
#include <iostream>

using namespace std;

class heapSort
{
public:
	heapSort(int arr[], int arrayLength);
	//当插入一个数的时候，让这个数与父节点不断比较，数大者上移，最后到达它该在的地方
	void heapInsert(int arr[], int index);
	void swap(int arr[], int i, int j);
	//将当前位置的堆结构中较大的数调整到该位置
	void heapify(int arr[], int index, int heapSize);
	void printArray(int arr[], int arrayLength);
};