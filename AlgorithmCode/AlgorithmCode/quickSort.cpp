#include "quickSort.h"

using namespace std;

quickSort::quickSort(int arr[], int arrayLength)
{
	if (arr == NULL || arrayLength < 2)
		return;
	quickSort(arr, 0, arrayLength - 1);
	printArray(arr, arrayLength);
}
//arr[L...R]�ź���
quickSort::quickSort(int arr[], int L, int R)
{
	if (L < R)
	{
		srand(time(0));//ʹÿ���������ͬ
		double randomNumber = rand() / (RAND_MAX + 1.0);//����0~1֮�����С��
		//��Ϊ�������Ϊ���������ֿ��ŵ�ʱ�临�ӶȾ���O(N * logN)��������Ϊ�����ʼ���ݶ�����ʱ�临�Ӷȱ仯
		swap(arr, L + (int)(randomNumber * (R - L + 1)), R);
		int* p = partition(arr, L, R);
		quickSort(arr, L, p[0] - 1);//С����
		quickSort(arr, p[1] + 1, R);//������
	}
}
//����һ������arr[L...R]�ĺ���
//Ĭ����arr[R]�����֣�arr[R]->p  <p ==p >p
//���ص���������߽磬�ұ߽磩,���Է���һ������Ϊ2������res,res[0] res[1]
int* quickSort::partition(int arr[], int L, int R)
{
	int less = L - 1;//<���ұ߽�
	int more = R;//>����߽�
	while (L < more)//L��ʾ��ǰ����λ�� arr[R] -> ����ֵ
	{
		if (arr[L] < arr[R])//��ǰ�� < ����ֵ
			swap(arr, ++less, L++);
		else if (arr[L] > arr[R])//��ǰ�� > ����ֵ
			swap(arr, --more, L);
		else
			L++;
	}
	swap(arr, more, R);
	return new int[] {less + 1, more};
}
void quickSort::swap(int arr[], int i, int j)
{
	int tamp = arr[i];
	arr[i] = arr[j];
	arr[j] = tamp;
}
void quickSort::printArray(int arr[], int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}