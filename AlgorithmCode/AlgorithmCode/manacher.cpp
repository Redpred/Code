#include "manacher.h"

/*
对于manacher算法，要创建一个回文半径数组pArr。
i : 当前进行的下标
C : 当前计算出回文串的中心点位置
R : 当前最大回文串的右边界
i': i镜像与中心点C的位置
能否加速回文串的判断条件有四个：
1、 i > R
2、 i < R && i的右边界 <  R
3、 i < R && i的右边界 == R
4、 i < R && i的右边界 >  R
执行方式：
1、直接往外扩，扩完记录pArr[i] 更新C和R
2、记录pArr[i] = pArr[2 * C - i]
3、记录pArr[i] = R - i
4、
*/

manacher::manacher(string s)
{
	if (s.size() == 0)//边界判断
	{
		return;
	}
	string str = manacherString(s);//修改原字符串
	vector<int> pArr(str.size());//回文半径数组
	int C = -1;//中心
	int R = -1;//有效右边界的下一个下标
	int Max = INT_MIN;//扩出来的最大值
	for (int i = 0; i != str.size(); i++)
	{
		//先设置一个“至少不用验证的区域”
		pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;//当i超出R的时候就先设置pArr[i] = 1，剩下的3种情况，取pArr[2 * C - i]和R - i两者最小

		//这个循环是将一个前面写出的4个判断条件整合
		//如果是条件2和3  那么就不能往外扩，就会break
		//如果是条件1和4  那么就会成功往外扩
		//整体不会影响时间复杂度 但是能简化判断条件
		while (i + pArr[i] < str.size() && i - pArr[i] > -1)//边界判断
		{
			if (str[i + pArr[i]] == str[i - pArr[i]])
			{
				pArr[i]++;
			}
			else
			{
				break;
			}
		}
		//更新C和R
		if (i + pArr[i] > R)
		{
			R = i + pArr[i];
			C = i;
		}
		Max = max(Max, pArr[i]);//更新Max
	}
	cout << Max - 1 << endl;//返回的最大回文串的长度
}

//将一个字符串的每一个字符中间插一个#  比如将123 变为 #1#2#3#
string manacher::manacherString(string str)
{
	string res = str + str + ' ';
	int index = 0;
	for (int i = 0; i != str.size() * 2 + 1; i++)
	{
		res[i] = (i & 1) == 0 ? '#' : str[index++];
	}
	return res;
}
