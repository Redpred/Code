#include <iostream>
#include <time.h>
#include <stack>
#include <vector>
#include <string>
#include "manacher.h"

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

	manacher("abbascabbaxabbacsabba");

	system("pause");
	return 0;
}
