#include <stdio.h>
int main()
{

    int array[4];
    for (int i = 0; i < 4; i++)
    {
        printf("inserisci il numero");
        scanf("%d", &array[i]);
    }
    int max = array[0];
    for (int i = 0; i < 4; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    printf("il massimo e': %d", max);
}