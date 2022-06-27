#include "ConvertToLetterString.h"

using namespace std;

/*
返回一个数字字符串可以转化多少种字母字符串
A对应1~Z对应26 当两个数字连在一起能组成不同字母，总结能组成多少种
*/
int ConvertToLetterString::process(string str, int i)//i是字符位置
{
	//当i超出字符串长度，返回1
	if (i == str.size())
	{
		return 1;
	}
	//这里认为[0~i-1]的已经锁定，从i开始，如果i位置字符为0，那么i之后的位置也不能和i有组合
	if (str[i] == '0')
	{
		return 0;
	}
	if (str[i] == '1')
	{
		//[0~9]是一种可能，也就是只管i位置。
		int res = process(str, i + 1);
		//如果能和i+1位置组合，那么就是[10~19]
		if ((i + 1) < str.size())
		{
			res += process(str, i + 2);
		}
		return res;
	}
	if (str[i] == '2')
	{
		//同'1'
		int res = process(str, i + 1);
		//这里要考虑i+1位置的数在[0~6]范围
		if ((i + 1) < str.size() && (str[i + 1] >= '0' && str[i + 1] <= '6'))
		{
			res += process(str, i + 2);
		}
		return res;
	}
	//剩下的就是[3~9]范围的，没有要求
	return process(str, i + 1);
}
