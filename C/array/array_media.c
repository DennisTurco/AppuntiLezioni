#include <stdio.h>
int main()
{
    int dim = 4;
    int array[dim];
    for (int i = 0; i < dim; i++)
    {
        printf("inserisci valore");
        scanf("%d", &array[i]);
    }
    float somma = 0;
    for (int i = 0; i < dim; i++)
    {
        somma = somma + array[i];
    }

    float media;
    media = somma / dim;
    printf("la media e': %f", media);
}