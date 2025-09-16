/*
es_struct 6. Il file "planet.csv" contiene le informazioni relative ai 9
    pianeti del sistema solare (nome, diametro, massa e numero
    satelliti). Definire opportuna struct e relativo array (statico)
    per memorizzare tali informazioni. Si legga quindi il contenuto
    del file (ignorare la prima riga), lo si memorizzi nell'array
    definito e, solo alla fine, se ne stampi il contenuto.

Si modifichi l'esercizio precedente allocando l'array in maniera
 dinamica

Si modifichi l'esercizio precedente salvando il contenuto
 dell'array su file binario

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pianeti{
    char nome[30];
    double diametro;
    char massa[30];
    unsigned int satelliti;
};


int main()
{
    int dim = 9;
    struct pianeti *dati=calloc(dim, sizeof(struct pianeti));

    FILE *file = fopen("../planet.csv","r");
    if(file==NULL){
        printf("Errore di apertura file");
        return -1;
    }

    fscanf(file, "%*[^\n]\n"); // skippa la prima riga (header)

    for(int i=0; i<dim; i++){
        fscanf(file, "%[^,],%lf,%[^,],%u\n",dati[i].nome,&dati[i].diametro,dati[i].massa,&dati[i].satelliti);
        printf("%s,%.2f,%s,%u\n",dati[i].nome,dati[i].diametro,dati[i].massa,dati[i].satelliti );
    }

    fclose(file);

    // SLAVATAGGIO NEL FILE BINARIO
    FILE *bin = fopen("../planet.bin", "wb");
    if (bin == NULL) {
        printf("Errore di apertura file binario\n");
        free(dati);
        return -1;
    }

    fwrite(dati, sizeof(struct pianeti), dim, bin);

    fclose(bin);
    free(dati);

    printf("\nDati salvati correttamente in planet.bin\n");

    return 0;
}