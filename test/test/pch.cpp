/// @file test.cpp Plik g³ówny

//
// pch.cpp
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief konstruktor, automatycznie sortuje tablicê
/// @param a - tablica do posortowania 
merger::merger(string a) {
    if (a != "") {
        int i = 0;
        int tabcheck = 0;
        int spaces = tablen(a);
        tab = new string[spaces + 1];
        tabs = new int[spaces + 1];

        while (i < a.length()) {
            if (a[i] == ' ') {
                i += 1;
                continue;
            }

            int wordLength = check(i, a);

            tab[tabcheck] = a.substr(i, wordLength);
            tabcheck += 1;

            i += wordLength;
        }
        tabtotabs(spaces);
        sort(spaces);
    }
    else {
        tab = new string[1];
        tab[0] = "";
        tabs = new int[0];
    }
    
}
/// @brief Destruktor, usuwa zmienne dynamiczne tab i tabs
merger::~merger() {
    delete[] tab;
    delete[] tabs;
};

/// @brief metoda check, zwraca d³ugoœæ danego elementu tablicy (np. 3 element to 25 czyli ma d³ugoœæ 2) 
/// @param i - miejece elementu w string a 
/// @param a - nieposortowana tablica tab
int merger::check(int i, string a) {
    int length = 0;
    while (i + length < a.length() && a[i + length] != ' ') {
        length += 1;
    }
    return length;
}

/// @brief metoda tablen
/// @param a - nieposortowana tablica tab
int merger::tablen(string a) {
    int spaces = 0;
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == ' ') {
            spaces += 1;
        }
    }
    return spaces + 1;
}
/// @brief metoda returntab, wypisuje tablicê z przecinkami
/// @param a - nieposortowana tablica tab
void merger::returntab(string a) {
    int i = 0;
    while (i < tablen(a)) {
        cout << tab[i] << " , ";
        i++;
    }
}
/// @brief metoda returntab, konwertuje string tab do tablicy int tabs 
/// @param spaces - iloœæ elementów tablicy tabs
void merger::tabtotabs(int spaces) {
    int i = 0;
    while (i < (spaces)) {
        tabs[i] = stoi(tab[i]);
        i++;
    }
}
/// @brief metoda sort, sortuje tablicê tabs
/// @param spaces - iloœæ elementów tablicy tabs
void merger::sort(int spaces) {
    int mnoznik = 1;

    while (mnoznik < spaces) {
        for (int i = 0; i < spaces; i += (2 * mnoznik)) {
            int mid = min(i + mnoznik, spaces);
            int end = min(i + 2 * mnoznik, spaces);


            int* temp = new int[spaces];
            int left = i, right = mid, k = i;


            while (left < mid && right < end) {
                if (tabs[left] <= tabs[right]) {
                    temp[k++] = tabs[left++];
                }
                else {
                    temp[k++] = tabs[right++];
                }
            }


            while (left < mid) {
                temp[k++] = tabs[left++];
            }


            while (right < end) {
                temp[k++] = tabs[right++];
            }


            for (int j = i; j < end; j++) {
                tabs[j] = temp[j];
            }

            delete[] temp;
        }

        mnoznik *= 2;
    }
}



/// @brief metoda returntabs,zwraca tablicê w stringu
/// @param a - nieposortowana tablica tab
string merger::returntabs(string a) {
    if (tab[0] == "") {
        return "";
    }
    else {
        int i = 0;
        string r;
        while (i < tablen(a)) {
            r += to_string(tabs[i]);
            if (i != (tablen(a) - 1)) {
                r += " ";
            }
            i++;
        }
        return  r;
    }
}
/// @brief metoda tabser, zwraca wskaŸnik na tabs
int* merger::tabser() {
    return tabs;
}