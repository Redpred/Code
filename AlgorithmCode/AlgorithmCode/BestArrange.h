#pragma once
#include <algorithm>

using namespace std;

class Program
{
public:
	int start;
	int end;
	Program(int _start, int _end);
};

int bestArrange(Program programs[], int timePoint, int nums);