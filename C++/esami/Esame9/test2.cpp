#include <iostream>
#include <fstream>
#include <string>
#include "StringListImpl2.h"

using namespace std;

int main() {
    StringListImpl list;
    ifstream file("../testo.txt");

    if (!file) {
        cerr << "Errore apertura file" << endl;
        return 1;
    }

    string word;
    while (file >> word) {   // separa automaticamente per spazi
        list.push_back(word);
    }

    cout << list << endl;

    file.close();
    return 0;
}
