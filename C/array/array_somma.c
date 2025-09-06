#include <stdio.h>
int main()
{

    int array[4];
    for (int i = 0; i < 4; i++)
    {
        printf("inserisci il numero");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", array[i]);
    }

    int somma = 0;
    for (int i = 0; i < 4; i++)
    {
        somma = somma + array[i];
    }

    printf("la somma e': %d", somma);
}