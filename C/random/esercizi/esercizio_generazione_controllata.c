/*
Scrivi un programma in cui il computer genera casualmente 5 numeri positivi minori o uguali di 1000.
Ad ogni iterazione il computer deve generare un numero maggiore del precedente, se viene generato
1000 prima dell'ultimo turno viene generato sempre 1000 anche nei rimanenti turni successivi.

Stampare in output qual é stato il "salto" maggiore tra un numero generato e l'altro. Considerare come
salto la differenza tra l'ennesimo numero ed il precedente.

Esempio: vengono generati 5, 20, 158, 559, 789. In output viene stampato 401 ovvero la differenza tra 158 e 559.
Le altre differenze sono infatti minori (20-5=15, 158-20=138, 559-158=401, 789-559=230)
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
    srand(time(NULL));

    int generazioni = 5;
    int valore;

    int min = 1;
    int max = 1000;

    int salto_maggiore = 0;

    for (int i = 0; i < generazioni; i++) {
        valore = rand() % (max - min + 1) + min;

        // min mi rappresenta il precedente numero generato quindi basta fare valore - min per capire la differenza
        // se i = 0 significa che abbiamo generato un solo numero, ma per il controllo ne vogliamo 2
        int salto = valore - min;
        if (salto > salto_maggiore && i != 0) {
            salto_maggiore = salto;
        }

        min = valore;
        printf("%d ", valore);
    }

    printf("\nLa differenza maggiore tra un numero generato e il successivo e' di: %d", salto_maggiore);

    return 0;
}