#include "NQueens.h"

NQueens::NQueens(int n)
{
	cout << nums1(n) << endl;
	cout << nums2(n) << endl;
}
int NQueens::nums1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	vector<int> record;//已经记录的皇后位置
	return process1(0, record, n);
}
//改进方法，用位运算，所以不能超过32皇后
int NQueens::nums2(int n)
{
	if (n < 1 || n>32)
	{
		return 0;
	}
	int limit = (n == 32) ? -1 : (1 << n) - 1;//这里limit的含义就是二进制从右往左数，前n个是1，后面全是0
	/*这样下来，N皇后棋盘就变成limit * limit的棋盘，比如 5皇后的棋盘就变成：
	17个0|1  1  1  1  1
	17个0|1  1  1  1  1
	17个0|1  1  1  1  1
	17个0|1  1  1  1  1
	17个0|1  1  1  1  1
	*/
	return process2(limit, 0, 0, 0);
}
//i 当前行数
int NQueens::process1(int i, vector<int>& record, int n)
{
	//base case
	if (i == n)
	{
		return 1;
	}
	int res = 0;//返回的结果
	record.push_back(0);//扩容
	for (int j = 0; j < n; j++)
	{
		//当前在i行的皇后，如果放在j列会不会和[0,i-1]行的皇后共行共列共斜线
		//如果 true ，认为无效
		//如果 false，认为有效
		if (isValid(record, i, j))
		{
			record[i] = j;
			res += process1(i + 1, record, n);
		}
	}
	return res;
}
//后三个参数都是限制，这里要求：二进制数中，1的位置不能放皇后，0的位置可以放皇后
//colLim：列的限制、leftDiaLim:左斜线的限制、rightDiaLim：右斜线的限制
//在这里的理解，这三个限制在后面不断递归中是不断增加的，不是单纯的一个位置的限制
//比如在第一行colLim=1，第二行colLim=4+1 二进制的101 叠加了第一行的1
int NQueens::process2(int limit, int colLim, int leftDiaLim, int rightDiaLim)
{
	//所以当colLim布满了棋盘第n行的limit的n个位置就结束了
	if (colLim == limit)
	{
		return 1;
	}
	int mostRightOne = 0;//指二进制最右边的数
	//pos含义是 取当前行的所有能放皇后的位置
	//colLim | leftDiaLim | rightDiaLim 是三个限制的位置相加
	//那么再取反之后 '与运算'limit 就能筛选出剩下能放皇后的位置了
	int pos = limit & (~(colLim | leftDiaLim | rightDiaLim));
	int res = 0;//返回的结果
	while (pos != 0)
	{
		mostRightOne = pos & (~pos + 1);//取二进制最右边的数
		pos = pos - mostRightOne;//取出后更新pos
		res += process2(limit, colLim | mostRightOne, //更新列限制 相加
			(leftDiaLim | mostRightOne) << 1, //更新左限制 因为要斜线 所以再左移一位
			(rightDiaLim | mostRightOne) >> 1);//更新右限制 再右移一位
		//这里的理解是，更新了限制 就相当于选择了这个位置，也就是mostRightOne位置
	}
	return res;
}

bool NQueens::isValid(const vector<int>& record, int i, int j)
{
	//只考虑[0,i-1]的皇后
	//在这里，i代表正要放的皇后的行数,j代表这个皇后要放的列数
	for (int k = 0; k < i; k++)
	{
		//  共列的情况      或         （ 列距离   ==  行距离 ） 也就是两者有45°夹角
		if (j == record[k] || abs(j - record[k]) == abs(i - k))
		{
			return false;
		}
	}
	return true;
}