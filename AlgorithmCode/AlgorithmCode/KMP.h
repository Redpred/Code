#pragma once
#include <string>
#include <vector>

using namespace std;

class KMP
{
public:
	int getIndexOf(const string& s, const string& m);
	vector<int> getNextArray(const string& ms);
};

