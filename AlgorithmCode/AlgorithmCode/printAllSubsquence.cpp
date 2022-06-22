#include "printAllSubsquence.h"

using namespace std;

//打印所有子序列 以字符串为例
//两种方式，第二种比较省空间 
printAllSubsquence::printAllSubsquence(string str)
{
	int times = 0;
	vector<string> res = function(str);
	for (const auto& item : res)
	{
		cout << item << endl;
		times++;
	}
	cout << times << endl;
}
//一个字符串，返回每一个子字符串，包括空字符串
//str是字符串，n是字符位置，开始是0，res是一条子字符串的内容
void printAllSubsquence::process(string str, int n, vector<char> res)
{
	//base case 基础
	//当n达到str长度，说明遍历完一次字符串，该输出一条子字符串了
	if (n == str.size())
	{
		for (const auto& item : res)
		{
			cout << item;
		}
		cout << endl;
		return;
	}
	//选出应该保留的字符存入resKeep中
	vector<char> resKeep = res;
	resKeep.push_back(str[n]);
	process(str, n + 1, resKeep);//将resKeep当作下一次的res
	//剔除不应该保留的字符，将空字符存入resNoInclude
	vector<char> resNoInclude = res;
	resNoInclude.push_back(' ');
	process(str, n + 1, resNoInclude);//将resNoInclude当作下一次的res
}
//上一种的优化，节省了空间
void printAllSubsquence::process(string str, int n)
{
	//base case 基础
	if (n == str.size())
	{
		cout << str << endl;//返回完整字符串，其中已经剔除不需要的了
		return;
	}
	//返回需要的字符串
	process(str, n + 1);
	//剔除不需要的字符再返回
	char tmp = str[n];//当不需要一个位置的字符时，存入tmp再将原位置变为空
	str[n] = 0;
	process(str, n + 1);
	//复原
	str[n] = tmp;//将tmp放回原位置
}
//返回一个字符串的各种排序方式，同时剔除重复的
//字符串str使用同一个内存空间，n代表字符位置，res代表存放字符串的容器，也保证同一个
void printAllSubsquence::process(string* str, int n, vector<string>* res)
{
	//base case
	if (n == (*str).size())
	{
		(*res).push_back((*str));//因为交换的原因，始终存入str即可
		return;
	}
	//从第0位置开始到n结束，交换的位置是从n开始到结束，这样就能有序
	for (int j = n; j < (*str).size(); j++)
	{
		swap(str, n, j);
		process(str, n + 1, res);
		swap(str, n, j);
	}
}
//返回的是一个字符串容器，其中每一元素都是一条字符串序列
//注意始终保持容器res为同一个，否则会申请n个容器，每个容器存放一条，最后返回空容器。
//字符串也需要始终使用同一内存空间，这是由process的方式决定的。
vector<string> printAllSubsquence::function(string str)
{
	vector<string> res;
	if (str.size() == 0)
	{
		return res;
	}
	process(&str, 0, &res);//使用引用
	return res;
}
//交换字符串中的两个字符
void printAllSubsquence::swap(string* str, int i, int j)
{
	char tmp = (*str)[i];
	(*str)[i] = (*str)[j];
	(*str)[j] = tmp;
}

