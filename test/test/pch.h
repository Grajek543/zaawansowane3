/// @file pch.h Plik zawieraj�cy klas� merger

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
	string* tab;///< wska�nik do Zmiennej zawieraj�cej nieposortowan� tablic� typu string
	int* tabs;///< wska�nik do tablicy zawieraj�cej posortowan� tablic� tab
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