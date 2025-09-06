#include <iostream>
using namespace std;

/*
    Si usano le funzioni per:
    1. ordina il codice;
    2. maggiore manutenibilità
    3. elimina ridondanza

    tipo nome_funzione(lista_parametri) {
        corpo_della_funzione
    }
*/

// void -> non restituisce nulla al chiamante
void stampa_frase() {
    cout << "Ciao Mondo!" << endl;
}

// prende un informazione come input
void stampa_numero_dato(int numero) {
    cout << numero << endl;
}

// funzione che ritorna un valore intero al chiamante
int somma(int valore1, int valore2) {
    int tot = valore1 + valore2;
    return tot; // ritorna il valore
}

// nel passaggio per valore si crea una copia della variabile che passa il chimante
void passaggio_per_valore(int numero) {
    numero = 25;
}

// nel passaggio per riferimento non si crea una copia della variabile che passa il chimante, ma si prende il riferimento ad essa
void passaggio_per_riferimento(int &numero) {
    numero = 25;
}

// prototipo
void funzione_prototipo(int, float);

int main () {
    // chiamata di funzione 
    stampa_frase();
    stampa_numero_dato(29);

    int risultato = somma(10, 2);
    stampa_numero_dato(risultato);

    int valore = 10;
    passaggio_per_valore(valore);
    cout << valore << endl;

    passaggio_per_riferimento(valore);
    cout << valore << endl;
}

// descrizione prototipo
void funzione_prototipo(int var1, float var2) {
    // ...
}