#include "merge.h"

merge::merge(string a) {
    int i = 0;
    int tabcheck = 0;
    int spaces = tablen(a);
    tab = new string[spaces + 1];

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
}

merge::~merge() {
    delete[] tab;
};


int merge::check(int i, string a) {
    int length = 0;
    while (i + length < a.length() && a[i + length] != ' ') {
        length += 1;
    }
    return length;
}


int merge::tablen(string a) {
    int spaces = 0;
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == ' ') {
            spaces += 1;
        }
    }
    return spaces + 1;
}
