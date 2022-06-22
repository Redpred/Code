#include<iostream>

using namespace std;

/*
时间复杂度：
	根据算法，写出算法的常数操作数量的表达式，然后：
	在常数操作数量级的表达式中，不要低阶项，且忽略高阶项的系数，所剩下的东西。
*/

/*
异或运算：
	交换另类技巧:
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
	异或：二进制逻辑，两数运算，每一位相同为0不同为1
	例如：
	 101100
	^001001
	=100101
	或者可以称为：无进位相加，每一位相加但不进位。
	性质：
	1. 0^N=N N^N=0
	2. 满足交换律和结合律
	注意：
	交换用异或，两个数在数值上相等没有问题，但是需要两个数内存地址不同。
*/

/*
	面试题：在一个数组中 int arr[];
	1)有一种数出现了奇数次，其他数出现偶数次。
	2)有两种数出现了奇数次，其他数出现偶数次。
	要求：
	时间复杂度：O(N)
	空间复杂度：O(1)
*/

void test01()
{
	int arr[9] = { 1,1,3,7,6,3,6,5,5 };

	int eor = 0;
	for (int cur : arr)
	{
		eor ^= cur;
	}
	cout << "eor = " << eor << endl;
}

void test02()
{
	int arr[10] = { 1,1,3,7,6,3,6,5,5,9 };

	int eor1 = 0;
	for (int cur : arr)
	{
		eor1 ^= cur;
	}
	//eor1 = a ^ b;
	//eor1 != 0
	//eor1必然有一个位置上是1
	int rightOne = eor1 & (~eor1 + 1);//提取eor最右侧的1

	int eor2 = 0;
	for (int cur : arr)
	{
		if ((cur & rightOne) == 0)
		{
			eor2 ^= cur;
		}
	}
	eor1 ^= eor2;
	cout << "eor1 = " << eor1 << " eor2 = " << eor2 << endl;
}