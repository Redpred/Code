#include "heapSort.h"

using namespace std;

/*
������
ʱ�临�Ӷȣ�O(N*logN)
����ռ临�Ӷȣ�O(1)
*/
heapSort::heapSort(int arr[], int arrayLength)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arrayLength; i++)
		heapInsert(arr, i);//O(logN)����Ϊֻ�ǲ㼶��ıȽϣ����Բ���=������logN����
	//ͨ�����ϲ���ѽṹ������γɴ����
	int heapSize = arrayLength;
	swap(arr, 0, --heapSize);//��Ϊ����ѵ�0λ���Ƕѵ������������Խ����Ƶ��������ͬʱ���ѷ�Χ-1
	while (heapSize > 0)//O(N)
	{
		//��Ϊ֮ǰ�γɴ�����ҵ�����С����0λ�ã����Դ�ʱ��heapify�����µ�0λ����λ��
		heapify(arr, 0, heapSize);//O(logN)
		swap(arr, 0, --heapSize);//O(1) 
	}
	printArray(arr, arrayLength);
}
//������һ������ʱ����������븸�ڵ㲻�ϱȽϣ����������ƣ���󵽴������ڵĵط�
void heapSort::heapInsert(int arr[], int index)
{
	while (arr[index] > arr[(index - 1) / 2])//�����ǰ�±�������ĸ��׵�ʱ��
	{
		swap(arr, index, (index - 1) / 2);//��������
		index = (index - 1) / 2;//����ǰλ���滻��ԭ���ĸ�λ��
	}
}
void heapSort::swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
//����ǰλ�õĶѽṹ�нϴ������������λ��
void heapSort::heapify(int arr[], int index, int heapSize)
{
	int left = index * 2 + 1;//���ӵ��±�
	while (left < heapSize)//�·����к��ӵ�ʱ��
	{
		//���������У�˭��ֵ�󣬰��±��largest
		int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
		//���ͽϴ�ĺ���֮�䣬˭��ֵ�󣬰��±��largest
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