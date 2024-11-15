#include <iostream>
#include "merge.h"

int main() {
    string a;
    cout << "Podaj liczby do sortowania rozdzielając je spacjami: " << endl;
    getline(cin, a);

    merge b(a);

    int i = 0;
    while (i < b.tablen(a)) {
        cout << b.tab[i] << " , ";
        i++;
    }
}
