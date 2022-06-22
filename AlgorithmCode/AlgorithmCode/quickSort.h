#pragma once
#include <cstddef>
#include <iostream>
#include "time.h"

using namespace std;

class quickSort
{
public:
	quickSort(int arr[], int arrayLength);
	//arr[L...R]排好序
	quickSort(int arr[], int L, int R);
	//这是一个处理arr[L...R]的函数
	//默认以arr[R]做划分，arr[R]->p  <p ==p >p
	//返回等于区域（左边界，右边界）,所以返回一个长度为2的数组res,res[0] res[1]
	int* partition(int arr[], int L, int R);
	void swap(int arr[], int i, int j);
	void printArray(int arr[], int arrayLength);
};