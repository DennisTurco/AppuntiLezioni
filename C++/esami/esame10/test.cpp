#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main () {
    // ---------------------- punto 1
    Paragrafo par1{"Primo paragrafo","Questo e' il testo del primo paragrafo."};
    Paragrafo par2{"Secondo paragrafo","Questo e' il testo del secondo paragrafo."};
    vector<Paragrafo> paragrafi{par1, par2};

    for (const auto& p : paragrafi) {
        cout << p.titolo() << endl;
        cout << p.testo() << endl << endl;
    }

    cout << "--------------------------------" << endl;

    // ---------------------- punto 2
    Capitolo cap1{"Capitolo Primo"};
    for (const auto& par: paragrafi)
        cap1.add(par);

    cout << cap1.titolo() << endl;
    auto parag = cap1.paragrafi()
    int i = 1;
    for (const auto& p : parag) {
        cout << i << ". " << p.titolo() << endl;
        cout << p.testo() << endl << endl;
        i++;
    }

    cout << "--------------------------------" << endl;

    // ---------------------- punto 3
    Capitolo cap2{"Capitolo Secondo"};
    cap2.add(par1);

    Libro libro1{"Nuovo Libro"};
    libro1.add(cap1);
    libro1.add(cap2);
    libro1.print(cout);

    cout << "--------------------------------" << endl;

    // ---------------------- punto 4
    cout << libro1;

    ofstream file("libro.txt");
    if (file) {
        file << libro1;
        file.close();
    }
}
