#pragma once
#include<vector>

using namespace std;

class Knapsack
{
public:
	int process(const vector<int>& weight, const vector<int>& value, int i, int alreadyWeight, int alreadyValue, int bag);
};

