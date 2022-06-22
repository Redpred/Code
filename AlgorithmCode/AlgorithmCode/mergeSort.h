#pragma once
#include <iostream>

using namespace std;

class mergeSort
{
public:
	int tamp[1000];
	mergeSort(int arr[], int arrayLength);
	mergeSort(int arr[], int L, int R);
	void merge(int arr[], int L, int mid, int R);
	void process(int arr[], int L, int R);
	void printArray(int arr[], int arrayLength);
};