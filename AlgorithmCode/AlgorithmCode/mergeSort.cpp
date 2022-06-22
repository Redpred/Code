#include "mergeSort.h"

using namespace std;

mergeSort::mergeSort(int arr[], int arrayLength)
{
	mergeSort(arr, 0, arrayLength - 1);
}
mergeSort::mergeSort(int arr[], int L, int R)
{
	process(arr, L, R);
	printArray(arr, R - L + 1);
}
void mergeSort::merge(int arr[], int L, int mid, int R)
{
	int left = L;//左边部分数组指针
	int right = mid + 1;//右边部分指针
	int k = L;//对tamp数组进行操作的指针

	while (left < mid + 1 && right < R + 1)
	{
		if (arr[left] > arr[right])
			tamp[k++] = arr[right++];
		else
		{
			tamp[k] = arr[left];
			k++;
			left++;
		}
	}

	//查看左边序列是否为空
	while (left < mid + 1)
	{
		tamp[k++] = arr[left++];
	}

	//查看右边序列是否为空
	while (right < R + 1)
	{
		tamp[k++] = arr[right++];
	}

	//移动回原数组
	for (int i = L; i <= R; i++)
	{
		arr[i] = tamp[i];
	}
}

void mergeSort::process(int arr[], int L, int R)
{
	if (L >= R)
		return;

	int mid = L + ((R - L) >> 1);

	process(arr, L, mid);
	process(arr, mid + 1, R);

	merge(arr, L, mid, R);
}

void mergeSort::printArray(int arr[], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}