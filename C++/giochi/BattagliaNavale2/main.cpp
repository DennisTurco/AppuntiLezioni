#include "battaglia_navale.cpp"

void stampa(int griglia[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            cout << griglia[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int griglia[DIM][DIM]; // 0 = acqua, 1 = nave1, 2 = nave2, 3 = nave3, 4 = nave4, 5 = nave5
    int x, y;
    
    // generazione randomica della griglia di gioco
    genera_griglia(griglia);

    stampa(griglia);

    // menu
    int scelta;
    do {
        cout << "Menu:\n1) Gioca;\n2) Inserisci;\n3) Help;\n4) Esci;\nOpzione: ";
        cin >> scelta;
        switch (scelta) {
        case 1:
            cout << "Preparazione griglia di gioco..." << endl;
            
            stampa_matrice(griglia);
            cout << endl;

            // gioco
            do {
                cout << "Inserisci la coordinata di x: ";
                cin >> x;
                cout << "Inserisci la coordinata di y: ";
                cin >> y;

                // controllo correttezza coordinate
                if(x < 0 || x >= DIM || y < 0 || y >= DIM) {
                    cout << "Coordinate non valide!" << endl;
                    continue;
                }

                if (griglia[x][y] == 0 || griglia[x][y] == -1) {
                    cout << "Acqua!" << endl;
                }
                else if(nave_affondata(griglia, griglia[x][y])) {
                    cout << "Affondata!" << endl;
                    griglia[x][y] = -1;
                } else {
                    cout << "Colpita!" << endl;
                    griglia[x][y] = -1;
                }

                stampa_matrice(griglia);
                cout << endl;
            } while(somma_totale(griglia) != -15);

            cout << "Hai Vinto!! Tutte le navi sono state affondate!!" << endl ;
            break;
        case 2:
            cout << "???" << endl;
            break;
        case 3:
            cout << "L'obbiettivo del giocatore e' quello di fornire le posizioni delle caselle in cui si suppone la presenza di una nave.\nIl programma, una volta aver ottenuto la posizione dal giocatore, dira' se si ha o meno colpita una nave.\nIl gioco termina quando il giocatore affonda tutte le navi.\n";
            break;
        case 4:
            cout << "Arrivederci!" << endl;
            break;
        default:
            cout << "Opzione non consentita." << endl;
            break;
        }
    } while (scelta != 4);

    return 0;
}