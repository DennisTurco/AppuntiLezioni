#include <iostream>
#include <string>
#include "StringBufferImpl.h"

using namespace std;

void testBuffer(StringBuffer& sb) {
    string text[] = {
        "Questo ", "e' ", "un ", "testo ", "di ", "esempio."
    };
    for (auto& s : text)
        sb.append(s);
}

int main() {
    StringBufferImpl sb;

    testBuffer(sb);
    sb.print(cout);
    cout << endl;

    sb.append('1').append(234);
    sb.print(cout);
    cout << endl;

    cout << "Lunghezza totale: " << sb.size() << endl;

    cout << sb << endl;   // operatore <<

    sb.clear();
    string file_name = "esempio.txt";
    read(file_name, sb);
    sb.print(cout);

    auto sb_ptr = read(file_name);
    sb_ptr->print(cout);

    return 0;
}
