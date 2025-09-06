#include <iostream>
#define DIM 5
using namespace std;

struct libro {
    string codice;
    string titolo;
    string autore;
    int anno;
    string editore;
};

int main () {
    libro libri[DIM];
    int dimensione = 0; // conta quanti libri ho inserito nell'array

    string codice_ricerca;
    string titolo_ricerca;
    bool trovato;

    int scelta;
    while(true) {
        cout << "\nMenu:\n";
        cout << "1. Inserisci libro;\n";
        cout << "2. visualizzazione dell'elenco dei libri della collezione;\n";
        cout << "3. Ricerca libro per codice;\n";
        cout << "4. Ricerca libro per titolo;\n";
        cout << "5. Uscita;\n";
        cout << "Operazione: ";
        cin >> scelta;

        if (scelta == 5) break;

        switch (scelta){
            case 1:
                if (dimensione >= DIM) {
                    cout << "Non ci sono piu' spazi disponibili per inserire libri.\n";
                    break;
                }
                cout << "codice = ";
                cin >> libri[dimensione].codice;
                cout << "titolo = ";
                cin >> libri[dimensione].titolo;
                cout << "autore = ";
                cin >> libri[dimensione].autore;               
                cout << "anno = ";
                cin >> libri[dimensione].anno;
                cout << "editore = ";
                cin >> libri[dimensione].editore;

                dimensione++;

                cout << "Libro aggiunto con successo!\n";
                break;
            case 2:
                for (int i = 0; i < dimensione; i++) {
                    cout << "--- Libro " << i+1 << " ---\n";
                    cout << "Codice: " << libri[i].codice << "\n";
                    cout << "Titolo: " << libri[i].titolo << "\n";
                    cout << "Autore: " << libri[i].autore << "\n";
                    cout << "Anno: " << libri[i].anno << "\n";
                    cout << "Editore: " << libri[i].editore << "\n\n";
                }
                break;
            case 3:
                cout << "codice = ";
                cin >> codice_ricerca;

                trovato = false;
                for (int i = 0; i < dimensione; i++) {
                    if (codice_ricerca == libri[i].codice) {
                        cout << "Codice: " << libri[i].codice << "\n";
                        cout << "Titolo: " << libri[i].titolo << "\n";
                        cout << "Autore: " << libri[i].autore << "\n";
                        cout << "Anno: " << libri[i].anno << "\n";
                        cout << "Editore: " << libri[i].editore << "\n";
                        trovato = true;
                        break;
                    }    
                }

                if (trovato == false) { // puoi scriverso anche come !trovato
                    cout << "Libro non presente nella lista\n";
                }
                    
                break;
            case 4:
                cout << "titolo = ";
                cin >> titolo_ricerca;

                trovato = false;
                for (int i = 0; i < dimensione; i++) {
                    if (titolo_ricerca == libri[i].titolo) {
                        cout << "Codice: " << libri[i].codice << "\n";
                        cout << "Titolo: " << libri[i].titolo << "\n";
                        cout << "Autore: " << libri[i].autore << "\n";
                        cout << "Anno: " << libri[i].anno << "\n";
                        cout << "Editore: " << libri[i].editore << "\n";
                        trovato = true;
                        break;
                    }    
                }

                if (trovato == false) { // puoi scriverso anche come !trovato
                    cout << "Libro non presente nella lista\n";
                }
                break;
            default:
                cout << "Operazione non valida\n";
                break;
        }
    }

    return 0;
}