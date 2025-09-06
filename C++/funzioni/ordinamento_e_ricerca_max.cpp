#include <iostream>
using namespace std;
// variabile globale= variabile dichiarata fuori da blocchi interni (visibile su tutto il programma)
// variabile locale= variabile dichiarata dentro da blocchi interni (visibile soltanto nel blocco dove viene dichiarata)

void inserimento(int vett[]) // definizione comportamento
{
    cout << "Inserisci 5 numeri: "; // output
    for (int i = 0; i < 5; i++)
    {
        cin >> vett[i];
    }
}

void stampa(int vett[])
{
    cout << "Numeri stampati: ";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << vett[i];
    }
}


// la funzione restituisce (al chiamante) un valore di tipo intero (il massimo)
int massimo(int vett[]) {

    //int max = INT_MIN; SOLUZIONE 1
    int max = vett[0]; // SOLUZIONE 2
    
    for (int i=0; i<5; i++) {
        if (max < vett[i]) {
            max = vett[i];
        }
    }
    return max;
}

void ordinamento(int vett[]) {
    for (int i = 0; i < 5; i++)
    {
        for (int a = 0; a < 5; a++)
        {
            if (vett[a] > vett[i])
            {
                cout << "(vett[a] > vett[i]) -----> " << vett[a] << " > " <<vett[i] << endl;
                int temp = vett[i];
                vett[i] = vett[a];
                vett[a] = temp;
            }
        }
    }
}

int main() {
    int vett[5];       // variabile locale
    inserimento(vett); // chiamata di funzione
    cout << endl;
    stampa(vett);
    cout << endl;
    int valore_massimo = massimo(vett); // il valore di ritorno della funzione "massimo" e' di tipo intero, il cui risultato verra' assegnato alla variabile "valore_massimo"
    cout << "il massimo e': " << valore_massimo;
    cout << endl;
    ordinamento(vett);
    cout << endl;
    stampa(vett);
    cout << endl;

    return 0;
}