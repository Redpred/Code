#include "quickSort.h"

using namespace std;

quickSort::quickSort(int arr[], int arrayLength)
{
	if (arr == NULL || arrayLength < 2)
		return;
	quickSort(arr, 0, arrayLength - 1);
	printArray(arr, arrayLength);
}
//arr[L...R]排好序
quickSort::quickSort(int arr[], int L, int R)
{
	if (L < R)
	{
		srand(time(0));//使每次随机数不同
		double randomNumber = rand() / (RAND_MAX + 1.0);//返回0~1之间随机小数
		//因为有随机行为，所以这种快排的时间复杂度就是O(N * logN)，不会因为特殊初始数据而导致时间复杂度变化
		swap(arr, L + (int)(randomNumber * (R - L + 1)), R);
		int* p = partition(arr, L, R);
		quickSort(arr, L, p[0] - 1);//小于区
		quickSort(arr, p[1] + 1, R);//大于区
	}
}
//这是一个处理arr[L...R]的函数
//默认以arr[R]做划分，arr[R]->p  <p ==p >p
//返回等于区域（左边界，右边界）,所以返回一个长度为2的数组res,res[0] res[1]
int* quickSort::partition(int arr[], int L, int R)
{
	int less = L - 1;//<区右边界
	int more = R;//>区左边界
	while (L < more)//L表示当前数的位置 arr[R] -> 划分值
	{
		if (arr[L] < arr[R])//当前数 < 划分值
			swap(arr, ++less, L++);
		else if (arr[L] > arr[R])//当前数 > 划分值
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