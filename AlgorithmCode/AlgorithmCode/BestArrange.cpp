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
//���Ż��飬һ�������п�ʼʱ��ͽ���ʱ�䣬һ��ʱ����ֻ�ܰ���һ����Ҫ������ʱ�䵽���ʱ��֮�ڰ������Ļ��顣
//̰���㷨˼·�ǣ����ջ������ʱ�����򣬽���ʱ�����������ǰ��timePoint������ʱ�䣬Ҳ��ָ��
//�Ȱ��ջ���Ŀ�ʼʱ�����ж���Щ������Щ����̭��С��timePoint�ı���̭������timePoint�ļ���
//����timePoint����timePoint��Ϊ�������Ľ���ʱ��
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