#include <iostream>
#include <time.h>
#include <stack>
#include <vector>
#include "hanoi.h"

using namespace std;

int main()
{
	// srand(time(0));
	// int arr[10];
	// double a = 0;
	// double b = 100.0;
	// for (int i = 0; i < 10; i++)
	//{
	//	double randomNumber = b * rand() / (RAND_MAX + 1.0 + a);//��ȡһ���������
	//	arr[i] = (int)randomNumber;
	// }

	hanoi(3);

	system("pause");
	return 0;
}
