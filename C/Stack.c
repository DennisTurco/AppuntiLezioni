// Push per l'inseriemento dei dati;
// Pop per l'estrazione dei dati;
// Clear per cancellare tutti i dati della pila;
// Print per stampare tutti i dati dall'elemento in alto a quello in basso.
// TODO: funzione "is_empty" restituisce true se lo stack e' vuoto, altrimenti false
// TODO: funzione "top_element" restituisce l'ultimo valore inserito (come pop ma non lo toglie dall'array) 

// Stack LIFO (Last in First Out)
// non usiamo puntatori in questo esempio perche' abbiamo un array di dimensione fissata a priori

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 3

int top = -1; // serve per capire la dimensione dell'array
int array[MAX_DIM];

int main () {

    pop();

    push(4);
    push(2);
    push(3);
    push(5);

    print();

    return 0;
}

////////////////////* POP *////////////////////
// toglie l'ultimo valore dall'array e lo restituisce al chiamante
int pop() {
    // controllo errore - prima di fare pop verifico se lo stack e' vuoto
    if (top == -1) {
        printf("Errore: non puoi fare pop su una struttura vuota!\n");
        return -1;
    }

    // facciamo la pop
    int temp = array[top];
    top--;
    return temp;
}

////////////////////* PUSH *////////////////////
// si limita ad aggiungere un nuovo valore nell'array
void push(int value) {
    // controllo errore (abbiamo una dimensione fissa)
    if (top == MAX_DIM - 1) {
        printf("Errore: l'array e' gia' pieno.\n");
        return; // esce dalla funzione senza fare la push
    }

    // facciamo la push
    top++;
    array[top] = value;
}

////////////////////* CLEAR *////////////////////
// fa ritornare il valore top a -1
void clear() {
    top = -1;
}

////////////////////* PRINT *////////////////////
// stampa l'intero array
void print() {
    for (int i=0; i<=top; i++) {
        printf("%d ", array[i]);
    }
}