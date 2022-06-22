#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class printAllSubsquence
{
public:
	printAllSubsquence(string str);
	void process(string str, int n, vector<char> res);
	void process(string str, int n);
	void process(string* str, int n, vector<string>* res);
	vector<string> function(string str);
	void swap(string* str, int i, int j);
};

