#include <string>
#include <iostream>
using namespace std;

class merge {
private:
	string* tab;
	int *tabs;
public:
	
	merge(string a);
	~merge();
	int check(int i, string a);
	int tablen(string a);
	void returntab(string a);
	void tabtotabs(int a);
	void sort(int a);
	void returntabs(string a);
};