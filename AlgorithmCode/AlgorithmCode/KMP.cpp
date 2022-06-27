#include "KMP.h"

int KMP::getIndexOf(const string& s, const string& m)
{
	//先判断越界问题
	if (s.empty() || m.empty() || m.size() < 1 || s.size() < m.size())
	{
		return -1;
	}
	int i1 = 0;//字符串s的下标指针
	int i2 = 0;//字符串m的下标指针
	vector<int> next = getNextArray(m);

	while (i1 < s.size() && i2 < m.size())//直到有一条指针越界
	{
		if (s[i1] == m[i2])//如果两个字符匹配就向后指
		{
			i1++;
			i2++;
		}
		else if (next[i2] == -1)//如果m字符串向后跳，直到跳到m[0]还不行
		{
			i1++;//s字符串应该向下指了
		}
		else //当不匹配的时候，m字符串向后跳next[i2]长度
		{
			i2 = next[i2];//也就是i2指针指向next[i2]
		}
	}
	//i1越界了就返回-1，i2越界了说明找到了匹配的位置，返回i1 - i2
	return i2 == m.size() ? i1 - i2 : -1;
}
/*
作用是获得‘所查找字符串’的一个“相同前缀后缀最大数”的数组
所谓“相同前缀后缀最大数”是指：
对于ms的第i字符，都能得知i字符前面有n个字符，存在[0,n-1] == [i-n,i-1]
比如：
字符串ms = "abbxcabbm";
那么对于字符m来说，m对应值应该是3，因为在m前面有[0,2]的abb和[5,7]的abb相同，且是相同长度最大的
那么最后函数getNextArray对于ms返回的数组应该是{-1,0,0,0,0,0,0,0,3}
对于字符串{abaxabam}返回{-1,0,0,1,0,1,2,3}
*/
vector<int> KMP::getNextArray(const string& ms)
{
	if (ms.size() == 1)//边界问题
	{
		return vector<int>{ -1 };
	}
	vector<int> next(ms.size());//初始化next
	next[0] = -1;//默认初始化
	next[1] = 0;
	int i = 2;//next的位置 初始为2
	int cn = 0;//cn = next[i-1]
	while (i < next.size())//遍历next
	{
		//在字符串ms上ms[i - 1] == ms[cn]时，说明next[i]可以是cn+1，可以用反证的方式证明
		if (ms[i - 1] == ms[cn])
		{
			next[i++] = ++cn;//一行进行了三种操作：更新next[i]=cn+1;i++;cn++;
		}
		//如果ms[i - 1] != ms[cn]时，让cn = next[cn]，再返回上一个if
		else if (cn > 0)
		{
			cn = next[cn];
		}
		else//直到cn = -1，也就是next[i]没有符合条件的了
		{
			next[i++] = 0;//next[i] = 0并且i++;
		}
	}
	return next;
}