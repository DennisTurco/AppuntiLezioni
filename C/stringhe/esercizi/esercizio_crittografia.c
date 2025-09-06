/*
    Esercizio 6. Scrivere una funzione che realizza un semplice algoritmo crittografico. 
    La funzione riceve come parametri una stringa s1 e un intero n e modifica s1 
    sostituendola con la sua versione criptata utilizzando il seguente semplice algoritmo 
    di cifratura. Ogni carattere da 'a' a 'z' viene rimpiazzato dal carattere che si 
    trova n posizioni più avanti nell'alfabeto. L'alfabeto va gestito circolarmente,
    cioè il carattere 'a' è successivo al carattere 'z'. 
    Tutti i caratteri che non rientrano nell' intervallo da 'a' a 'z' vanno lasciati inalterati.
    Scrivere anche una funzione che decodifica una stringa criptata 
    (tale funzione deve cioè funzionarein maniera inversa rispetto alla precedente).
    Scrivere infine un programma che permette di criptare e decriptare una stringa 
    inserita dall’utente.
*/

#include <stdio.h>
#include <string.h>

// abc, n = 3 -> def
void criptazione(char s1[], int n) {
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            
            for (int j = 0; j < n; j++) {
                if (s1[i] < 'z') {
                    s1[i] += 1;
                } else {
                    s1[i] = 'a';
                }   
            }
        }
    }
}

// def, n = 3 -> abc
void decriptazione(s1, n) {

}

int main () {
    // inserimento stringa
    char stringa_chiara[100];
    int n = 10;

    printf("Inserire una stringa da criptare: ");
    scanf("%s", stringa_chiara);

    char stringa_criptata[strlen(stringa_chiara)]; // stringa_criptata ha esattamente il numero di caratteri della stringa_chiara
    strcpy(stringa_criptata, stringa_chiara);

    // criptazione
    criptazione(stringa_criptata, n);
    printf("Stringa criptata: %s\n", stringa_criptata);

    // decriptazione
    // decriptazione(stringa, n);
    // printf("Stringa decriptata: %s\n", stringa);
}