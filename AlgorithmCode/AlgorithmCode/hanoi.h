#pragma once
#include <string>
#include <iostream>

using namespace std;

class hanoi
{
public:
	int times;
	hanoi(int n);
	void func(int n, string from, string to, string other);
};

