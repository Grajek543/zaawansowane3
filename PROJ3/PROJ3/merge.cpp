#include "merge.h"

merge::merge(string a) {
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

merge::~merge() {
    delete[] tab;
    delete[] tabs;
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

void merge::returntab(string a) {
    int i = 0;
    while (i < this->tablen(a)) {
        cout << this->tab[i] << " , ";
        i++;
    }
}

void merge::tabtotabs(int spaces) {
    int i = 0;
    while (i < (spaces)) {
        tabs[i] = stoi(tab[i]);
        i++;
    }
}

void merge::sort(int spaces) {
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




void merge::returntabs(string a) {
    int i = 0;
    string r;
    while (i < this->tablen(a)) {
        r += to_string(tabs[i]);
        if (i != (tablen(a) - 1)) {
            r += " ";
        }
        i++;
    }
    cout << r;
}