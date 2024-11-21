/// @file pch.h Plik zawieraj¹cy klasê merger

//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief Klasa merger oraz deklaracje jej metod
class merger {
private:
	string* tab;///< wskaŸnik do Zmiennej zawieraj¹cej nieposortowan¹ tablicê typu string
	int* tabs;///< wskaŸnik do tablicy zawieraj¹cej posortowan¹ tablicê tab
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