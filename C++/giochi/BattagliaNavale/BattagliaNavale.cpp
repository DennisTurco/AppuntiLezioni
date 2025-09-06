#include <iostream>
using namespace std;

/* esempio griglia von navi:
    A, B, C -> navi

    N N N C N
    N A N C N
    N N A N N
    N N N N N
    N B B B N
*/

struct cella {
    char codice_nave;   // se la cella non ha la nave, il codice sara' 'N'
    int stato_cella;    // 0 -> acqua; 1 -> nave; 2 -> acqua colpita; 3 -> nave colpita
};

void costruisci_griglia(cella griglia[5][5], int rows, int cols) {
    griglia[0][0].codice_nave = 'N';
    griglia[0][1].codice_nave = 'N';
    griglia[0][2].codice_nave = 'N';
    griglia[0][3].codice_nave = 'C';
    griglia[0][4].codice_nave = 'N';

    griglia[1][0].codice_nave = 'N';
    griglia[1][1].codice_nave = 'A';
    griglia[1][2].codice_nave = 'N';
    griglia[1][3].codice_nave = 'C';
    griglia[1][4].codice_nave = 'N';

    griglia[2][0].codice_nave = 'N';
    griglia[2][1].codice_nave = 'N';
    griglia[2][2].codice_nave = 'A';
    griglia[2][3].codice_nave = 'N';
    griglia[2][4].codice_nave = 'N';

    griglia[3][0].codice_nave = 'N';
    griglia[3][1].codice_nave = 'N';
    griglia[3][2].codice_nave = 'N';
    griglia[3][3].codice_nave = 'N';
    griglia[3][4].codice_nave = 'N';

    griglia[4][0].codice_nave = 'N';
    griglia[4][1].codice_nave = 'B';
    griglia[4][2].codice_nave = 'B';
    griglia[4][3].codice_nave = 'B';
    griglia[4][4].codice_nave = 'N';

    // faccio il doippio ciclo per evitarmi di ripetere tutte queste righe in alto anche per lo stato, siccome riesco a farlo cosi'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (griglia[i][j].codice_nave == 'N') {
                griglia[i][j].stato_cella = 0;
            } else {
                griglia[i][j].stato_cella = 1;
            }
        }
    }
}

void stampa_griglia(cella griglia[5][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            // la lettare non colpita la converto con '0'
            if (griglia[i][j].stato_cella == 0 || griglia[i][j].stato_cella == 1) {
                cout << "0 ";
            } 
            // l'acqua colpita la converto con '*'
            else if (griglia[i][j].stato_cella == 2) {
                cout << "* ";
            }
            // nave colpita la converto con 'X'
            else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

// qui modifichiamo lo stato della nave
void sparo(cella griglia[5][5], int x, int y) {
    if (griglia[x][y].stato_cella == 0) {
        griglia[x][y].stato_cella = 2;
        cout << "Acqua!" << endl;
    } else if (griglia[x][y].stato_cella == 1) {
        griglia[x][y].stato_cella = 3;
        cout << "Colpita!" << endl;
    } else {
        cout << "Hai gia' sparato qui!" << endl;
    }
}

// true se e' affondata, false altrimenti
bool is_nave_affondata(cella griglia[5][5], int rows, int cols, char codice) {
    
    // itero per ogni cella della nave
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // caso nave intatta
            if (griglia[i][j].codice_nave == codice && griglia[i][j].stato_cella == 1) {
                return false;
            }
        }
    }

    return true;
}

// true se tutte le navio sono state colpite. false altrimenti
bool is_game_over(cella griglia[5][5], int rows, int cols) {
    // itero per ogni cella della nave
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // caso nave intatta
            char codice = griglia[i][j].codice_nave;
            if (codice != 'N' && is_nave_affondata(griglia, rows, cols, codice) == false) {
                return false;
            }
        }
    }

    return true;
}

int main () {
    int rows = 5;   // righe
    int cols = 5;   // colonne

    cella griglia[5][5];
    costruisci_griglia(griglia, rows, cols);

    int x, y;
    do {
        cout << "Posizione (x, y): ";
        cin >> x >> y;

        sparo(griglia, x, y);
        stampa_griglia(griglia, rows, cols);

    } while (is_game_over(griglia, rows, cols) == false); // il ciclo continua finche' il gioco non e' finito

    cout << "Tutte le navi sono state affondate!";
}