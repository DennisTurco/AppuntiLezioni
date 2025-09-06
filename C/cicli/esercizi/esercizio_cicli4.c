#include <stdlib.h>
#include <stdio.h>

/* ESERCIZIO
Far inserire 10 numeri all’utente, ogni volta che viene inserito
un numero negativo, viene fatto reinserire fino a che non viene 
inserito un numero positivo, alla fine dire quanti negativi 
sono stati inseriti e scrivere la somma solo dei numeri positivi 
inseriti.
*/

int main()
{
    int negativi=0;
    int somma=0;
    int n;
    for(int i=0; i<10; i++)
    {
        printf("inserisci il numero %d: ", i+1);
        scanf("%d", &n);
        
        while(n<0)
        {
            printf("hai inserito un numero negativo\n");
            printf("reinserisci il numero %d: ", i+1);
            negativi++;
            scanf("%d", &n);
        }
        
        somma+=n;
    }
    printf("la somma e' %d\n", somma);
    printf("sono stati inseriti %d numeri negativi", negativi);
}