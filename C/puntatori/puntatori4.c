#include <stdlib.h>
#include <stdio.h>

int* numeriunici(const int array[], int dim, int* outputdim)
{
    int* unici = malloc(dim * sizeof(int));
    *outputdim = 0;

    for (int i = 0; i < dim; i++)
    {
        int trovato = 0;

        for (int j = 0; j < *outputdim; j++)
        {
            if (array[i] == unici[j])
            {
                trovato = 1;
                break;
            }
        }

        if (!trovato)
        {
            unici[*outputdim] = array[i];
            *outputdim += 1;
        }
    }

    return unici;
}

int main()
{
    const int array[] = {2, -11, 0, 2, -11, 2, 2};
    int dim = 7;
    int outputdim = 0;

    int* unici = numeriunici(array, dim, &outputdim);

    for (int i = 0; i < outputdim; i++)
    {
        printf("%d ", unici[i]);
    }

    free(unici);
}