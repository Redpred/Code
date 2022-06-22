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
	int left = L;//��߲�������ָ��
	int right = mid + 1;//�ұ߲���ָ��
	int k = L;//��tamp������в�����ָ��

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

	//�鿴��������Ƿ�Ϊ��
	while (left < mid + 1)
	{
		tamp[k++] = arr[left++];
	}

	//�鿴�ұ������Ƿ�Ϊ��
	while (right < R + 1)
	{
		tamp[k++] = arr[right++];
	}

	//�ƶ���ԭ����
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