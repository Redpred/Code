#include "BitMap.h"

BitMap::BitMap()
{
	int a = 0;//32 bit

	int arr[10]{};// 32bit * 10 =320bits

	//arr[0] int 0~31
	//arr[1] int 32~63
	//arr[2] int 64~95

	int i = 178;//想获取第178位bit的状态

	int numIndex = 178 / 32;//寻找178位在arr数组第几元素上
	int bitIndex = 178 % 32;//在arr[5]的二进制第几位

	//拿到178位状态
	int s = ((arr[numIndex] >> bitIndex) & 1);//arr[5]右移bitIndex位，就是将178位移到最右边，与上1能消除其他位。

	//把178位改成1
	arr[numIndex] = arr[numIndex] | (1 << bitIndex);

	//把178位改成0
	arr[numIndex] = arr[numIndex] & (~(1 << bitIndex));
}