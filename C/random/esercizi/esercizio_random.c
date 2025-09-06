/*Esercizio 7
Generare un numero a caso compreso tra 1-100 e chiedere all’utente un numero fino a quando non è uguale a 
quello generato casualmente. 
Dire ogni volta se il numero immesso è > o < di quello iniziale. Indicare anche il numero di tentativi.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = -1;
    int random = rand() % 100 + 1; //genera un numero casuale da 1 a 100
    int cont = 0;

    while(x!=random){
        printf("inserisci numero tra 1 e 100: ");
        scanf("%d", &x);
        cont++;

        if(x>random){
            printf("il numero e maggiore di quello iniziale \n");
        }
        else if(x<random){
            printf("il numero e minore di quello iniziale \n");
        }
    }
    return 0;
}