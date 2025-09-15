/*
Esercizio:
    Leggere da file un elenco di tempi e salvarli in un array
    e stampare a video quelli maggiori di 40, dopo averli ordinati
*/

#include <iostream> // cout (printf), cin (scanf)
using namespace std;

float massimo(float tempi[], int n) {
    float max = tempi[0];
    for (int i = 0; i < n; i++) {
        if (tempi[i] > max) {
            max = tempi[i];
        }
    }

    return max;
}

// ordinamento: bubble sort
// 23, 34, 1, 45
// 23, 1, 34, 45
// 1, 23, 34, 45
// 1, 23, 34, 45
void ordinamento_array(float tempi[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (tempi[j] > tempi[j+1]) {
                float temp = tempi[j];
                tempi[j] = tempi[j+1];
                tempi[j+1] = temp;
            }
        }
    }
}

float* ordinamento_salvando_su_nuovo(float tempi[], int n) {
    float *new_tempi = (float*) calloc(n, sizeof(float));

    // copia il contenuto su new_tempi
    for (int i = 0; i < n; i++) {
        new_tempi[i] = tempi[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (new_tempi[j] > new_tempi[j+1]) {
                float temp = new_tempi[j];
                new_tempi[j] = new_tempi[j+1];
                new_tempi[j+1] = temp;
            }
        }
    }

    return new_tempi;
}

void stampa_maggiori_di_n(float tempi[], int dim, float n) {
    cout << "Tempi > n" << endl;
    for (int i = 0; i < dim; i++) {
        if (tempi[i] > n) {
            cout << tempi[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int dim = 7;
    float tempi[dim];
    FILE *file = fopen("../tempi.csv", "r");

    if (file == NULL) {
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }

    // leggiamo intestazione del file
    char intestazione[20];
    fscanf(file, "%s", intestazione);

    // lettura da file
    for (int i = 0; i < dim; i++) {
        fscanf(file, "%f", &tempi[i]);
    }

    float max = massimo(tempi, dim);
    cout << "il valore massimo e': " << max << endl;

    // float *tempi_ordinati = ordinamento_salvando_su_nuovo(tempi, dim);
    ordinamento_array(tempi, dim);

    stampa_maggiori_di_n(tempi, dim, 0);

    stampa_maggiori_di_n(tempi, dim, 40);

    // free(tempi_ordinati);
    fclose(file);
    return 0;
}