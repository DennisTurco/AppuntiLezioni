#include <iostream>
#include "StringListImpl.h"

using namespace std;

int main() {
    StringListImpl phrase;
    phrase.push_front("ipsum");
    phrase.push_back("dolor");
    phrase.push_back("sit");
    phrase.push_back("amet.");
    phrase.push_front("Lorem");
    cout << phrase.str() << endl;
    cout << "size: " << phrase.size() << endl;

    phrase.remove(0);
    phrase.remove(1);
    phrase.remove(1);
    phrase.remove(1);
    phrase.push_front("Lorem");

    // stampiamo usando il metodo str()
    cout << phrase.str() << endl;

    // stampiamo usando operator<<
    cout << phrase << endl;
}