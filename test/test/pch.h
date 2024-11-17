//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class merger {
private:
	string* tab;
	int* tabs;
public:

	merger(string a);
	~merger();
	int check(int i, string a);
	int tablen(string a);
	void returntab(string a);
	void tabtotabs(int a);
	void sort(int a);
	string returntabs(string a);
	int* tabser();
};