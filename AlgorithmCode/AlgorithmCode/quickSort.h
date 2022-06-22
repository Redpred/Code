#pragma once
#include <cstddef>
#include <iostream>
#include "time.h"

using namespace std;

class quickSort
{
public:
	quickSort(int arr[], int arrayLength);
	//arr[L...R]�ź���
	quickSort(int arr[], int L, int R);
	//����һ������arr[L...R]�ĺ���
	//Ĭ����arr[R]�����֣�arr[R]->p  <p ==p >p
	//���ص���������߽磬�ұ߽磩,���Է���һ������Ϊ2������res,res[0] res[1]
	int* partition(int arr[], int L, int R);
	void swap(int arr[], int i, int j);
	void printArray(int arr[], int arrayLength);
};