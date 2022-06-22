#include "heapSort.h"

using namespace std;

/*
堆排序：
时间复杂度：O(N*logN)
额外空间复杂度：O(1)
*/
heapSort::heapSort(int arr[], int arrayLength)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arrayLength; i++)
		heapInsert(arr, i);//O(logN)，因为只是层级间的比较，所以层数=总数的logN级别
	//通过不断插入堆结构，最后形成大根堆
	int heapSize = arrayLength;
	swap(arr, 0, --heapSize);//因为大根堆的0位置是堆的最大的数，所以将它移到数据最后，同时将堆范围-1
	while (heapSize > 0)//O(N)
	{
		//因为之前形成大根堆且调整最小数到0位置，所以此时用heapify调整新的0位置数位置
		heapify(arr, 0, heapSize);//O(logN)
		swap(arr, 0, --heapSize);//O(1) 
	}
	printArray(arr, arrayLength);
}
//当插入一个数的时候，让这个数与父节点不断比较，数大者上移，最后到达它该在的地方
void heapSort::heapInsert(int arr[], int index)
{
	while (arr[index] > arr[(index - 1) / 2])//如果当前下标大于它的父亲的时候
	{
		swap(arr, index, (index - 1) / 2);//交换两者
		index = (index - 1) / 2;//将当前位置替换成原来的父位置
	}
}
void heapSort::swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
//将当前位置的堆结构中较大的数调整到该位置
void heapSort::heapify(int arr[], int index, int heapSize)
{
	int left = index * 2 + 1;//左孩子的下标
	while (left < heapSize)//下方还有孩子的时候
	{
		//两个孩子中，谁的值大，把下标给largest
		int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
		//父和较大的孩子之间，谁的值大，把下标给largest
		largest = arr[largest] > arr[index] ? largest : index;
		if (largest == index)
			break;
		swap(arr, largest, index);
		index = largest;
		left = index * 2 + 1;

	}
}
void heapSort::printArray(int arr[], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}