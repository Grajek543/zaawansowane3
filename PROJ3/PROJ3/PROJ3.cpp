#include <iostream>
#include "merge.h"

int main() {
    string a;
    cout << "Podaj liczby do sortowania rozdzielając je spacjami: " << endl;
    getline(cin, a);

    merge b(a);

    b.returntab(a);
    cout << endl << endl;
    b.returntabs(a);
}
