#include "BestArrange.h"

using namespace std;

Program::Program(int _start, int _end)
{
	start = _start;
	end = _end;
}

struct ProgramComparator
{
	bool operator()(Program o1, Program o2)
	{
		return o1.end < o2.end;
	}
};
//安排会议，一个会议有开始时间和结束时间，一段时间内只能安排一场。要在最早时间到最迟时间之内安排最多的会议。
//贪心算法思路是，按照会议结束时间排序，结束时间最早的在最前。timePoint是最早时间，也是指针
//先按照会议的开始时间来判断哪些计入哪些被淘汰：小于timePoint的被淘汰，大于timePoint的计入
//更新timePoint：将timePoint变为计入会议的结束时间
int bestArrange(Program programs[], int timePoint, int nums)
{
	sort(programs, programs + nums, ProgramComparator());
	int result = 0;
	for (int i = 0; i < nums; i++)
	{
		if (timePoint <= programs[i].start)
		{
			result++;
			timePoint = programs[i].end;
		}
	}
	return result;
}