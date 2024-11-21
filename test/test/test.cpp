/// @file test.cpp Plik główny

#include "pch.h"
#include <cstdlib>
#include <ctime>


/// @brief Test1, sprawdza czy tablica zostanie niezmieniona jeżeli wpiszemy już posortowaną tablicę
TEST(Testyogolne, Zachowanie_niezmienionej_tablicy) {
	string input = ("1 2 3 4 5 6 7");
	merger a(input);
	EXPECT_EQ(input, a.returntabs(input));
}
/// @brief Test2, Sprawdza czy dobrze posortuje odwróconą tablicę
TEST(Testyogolne, sortowanie_odwrotnej_tablicy) {
	string input = ("10 9 8 7 6 5 4 3 2 1 0");
	merger a(input);
	EXPECT_EQ("0 1 2 3 4 5 6 7 8 9 10", a.returntabs(input));
}
/// @brief Test3, sprawdza czy posortuje randomową tablicę
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
/// @brief Test4 sprawdza czy posortuje tablicę z ujemnymi elementami
TEST(Testyogolne, ujemne_elementy) {
	string input = ("-1, -2 -54 -67 -213 -678 -12 -9 -78 -3 -123342 -1456");
	merger a(input);
	EXPECT_EQ("-123342 -1456 -678 -213 -78 -67 -54 -12 -9 -3 -2 -1", a.returntabs(input));
}
/// @brief Test5 sprawdza czy posortuje tablicę z ujemnymi i dodatnimi elementami
TEST(Testyogolne, elementy_dodatnie_i_ujemne) {
	string input = ("5 1 7 2 4 3 6 8 0 -2 -1");
	merger a(input);
	EXPECT_EQ("-2 -1 0 1 2 3 4 5 6 7 8", a.returntabs(input));
}
/// @brief Test6 sprawdza czy wyskoczy błąd przy tablicy bez elementów
TEST(Testyogolne, sortowanie_tablicy_bez_elemenow) {
	string input = ("");
	merger a(input);
	EXPECT_EQ("", a.returntabs(input));
}
/// @brief Test7 sprawdza czy posortuje tablicę z jednym elementem
TEST(Testyogolne, sortowanie_tablicy_jeden_element) {
	string input = ("1");
	merger a(input);
	EXPECT_EQ("1", a.returntabs(input));
}
/// @brief Test8 sprawdza czy posortuje tablicę z powtarzającymi się elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy) {
	string input = ("1 1 1 3 3 3 2 2 2 2 2 25 12 12 12");
	merger a(input);
	EXPECT_EQ("1 1 1 2 2 2 2 2 3 3 3 12 12 12 25", a.returntabs(input));
}
/// @brief Test9 sprawdza czy posortuje tablicę z powtarzającymi się ujemnymi elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_ujemne_elementy) {
	string input = ("-1 -1 -1 -3 -3 -3 -2 -2 -2 -2 -2 -25 -12 -12 -12");
	merger a(input);
	EXPECT_EQ("-25 -12 -12 -12 -3 -3 -3 -2 -2 -2 -2 -2 -1 -1 -1", a.returntabs(input));
}
/// @brief Test10 sprawdza czy posortuje tablicę z powtarzającymi się ujemnymi i dodatnimi elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy_dodatnie_ujemne) {
	string input = ("-1 -1 1 3 -3 -3 2 2 -2 -2 2 25 12 -12 12");
	merger a(input);
	EXPECT_EQ("-12 -3 -3 -2 -2 -1 -1 1 2 2 2 3 12 12 25", a.returntabs(input));
}
/// @brief Test11 sprawdza czy posortuje tablicę z dwoma elementami rosnąco
TEST(Testyogolne, sortowanie_tablicy_dwa_elementy_rosnaco) {
	string input = ("1 3");
	merger a(input);
	EXPECT_EQ("1 3", a.returntabs(input));
}
/// @brief Test12 sprawdza czy posortuje tablicę większą niż 100
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
/// @brief Test13 sprawdza czy posortuje tablicę większą niż 100 z ujemnymi, dodatnimi elementami i duplikatami
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