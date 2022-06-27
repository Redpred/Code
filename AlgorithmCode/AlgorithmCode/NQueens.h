#pragma once
#include <vector>
#include <iostream>

using namespace std;

class NQueens
{
public:
	NQueens(int n);
	int nums1(int n);
	int nums2(int n);
	int process1(int i, vector<int>& record, int n);
	int process2(int limit, int colLim, int leftDiaLim, int rightDiaLim);
	bool isValid(const vector<int>& record, int i, int j);
};

