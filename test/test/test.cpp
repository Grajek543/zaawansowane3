#include "pch.h"
#include <cstdlib>
#include <ctime>



TEST(Testyogolne, Zachowanie_niezmienionej_tablicy) {
	string input = ("1 2 3 4 5 6 7");
	merger a(input);
	EXPECT_EQ(input, a.returntabs(input));
}

TEST(Testyogolne, sortowanie_odwrotnej_tablicy) {
	string input = ("10 9 8 7 6 5 4 3 2 1 0");
	merger a(input);
	EXPECT_EQ("0 1 2 3 4 5 6 7 8 9 10", a.returntabs(input));
}

TEST(Testyogolne, randomowa_tablica) {
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 1;
	while (i < t) {
		r += to_string(rand() % 10000 - 2001);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	merger a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}

	
	int j = 0;
	int* tab = a.tabser();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}

TEST(Testyogolne, ujemne_elementy) {
	string input = ("-1, -2 -54 -67 -213 -678 -12 -9 -78 -3 -123342 -1456");
	merger a(input);
	EXPECT_EQ("-123342 -1456 -678 -213 -78 -67 -54 -12 -9 -3 -2 -1", a.returntabs(input));
}

TEST(Testyogolne, elementy_dodatnie_i_ujemne) {
	string input = ("5 1 7 2 4 3 6 8 0 -2 -1");
	merger a(input);
	EXPECT_EQ("-2 -1 0 1 2 3 4 5 6 7 8", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_bez_elemenow) {
	string input = ("");
	merger a(input);
	EXPECT_EQ("", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_jeden_element) {
	string input = ("1");
	merger a(input);
	EXPECT_EQ("1", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy) {
	string input = ("1 1 1 3 3 3 2 2 2 2 2 25 12 12 12");
	merger a(input);
	EXPECT_EQ("1 1 1 2 2 2 2 2 3 3 3 12 12 12 25", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_powtarzajace_ujemne_elementy) {
	string input = ("-1 -1 -1 -3 -3 -3 -2 -2 -2 -2 -2 -25 -12 -12 -12");
	merger a(input);
	EXPECT_EQ("-25 -12 -12 -12 -3 -3 -3 -2 -2 -2 -2 -2 -1 -1 -1", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy_dodatnie_ujemne) {
	string input = ("-1 -1 1 3 -3 -3 2 2 -2 -2 2 25 12 -12 12");
	merger a(input);
	EXPECT_EQ("-12 -3 -3 -2 -2 -1 -1 1 2 2 2 3 12 12 25", a.returntabs(input));
}

TEST(Testyogolne, sortowanie_tablicy_dwa_elementy_rosnaco) {
	string input = ("1 3");
	merger a(input);
	EXPECT_EQ("1 3", a.returntabs(input));
}

TEST(Testyogolne, randomowa_tablica_większa_niz_100){
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 100;
	while (i < t) {
		r += to_string(rand() % 10000 - 2001);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	merger a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}


	int j = 0;
	int* tab = a.tabser();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}

TEST(Testyogolne, randomowa_tablica_wieksza_niz_100_dod_uj_dup) {
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 100;
	while (i < t) {
		int y = rand() % 4000 - 2001;
		r += to_string(y);
		r += " ";
		r += to_string(y);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	merger a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}


	int j = 0;
	int* tab = a.tabser();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}