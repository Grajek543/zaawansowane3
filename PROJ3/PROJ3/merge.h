#include <string>
#include <iostream>
using namespace std;

class merge {
public:
	string* tab;
	merge(string a);
	~merge();
	int check(int i, string a);
	int tablen(string a);
};