#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo *link;
struct nodo {
    int numero;
    link sinistra;
    link destra;
};

void in_print(link nodo) {
    if (nodo != NULL) {
        in_print(nodo->sinistra);
        printf("%d ", nodo->numero);
        in_print(nodo->destra);
    }
}

link creanodo(int valore) {
    link nuovonodo = (link)malloc(sizeof(struct nodo));
    nuovonodo->numero = valore;
    nuovonodo->sinistra = NULL;
    nuovonodo->destra = NULL;
    return nuovonodo;
}

link inserisci(link nodo, int valore) {
    if (nodo == NULL) {
        return creanodo(valore);
    } else {
        if (valore < nodo->numero)
            nodo->sinistra = inserisci(nodo->sinistra, valore);
        else
            nodo->destra = inserisci(nodo->destra, valore);
    }
    return nodo;
}

int main(void) {
    FILE *f;
    int valore;
    link radice = NULL;

    f = fopen("ALBERI.DAT", "rb");
    if (f == NULL) {
        perror("Errore apertura file");
        return -1;
    }

    while (fread(&valore, sizeof(int), 1, f) == 1) {
        radice = inserisci(radice, valore);
    }

    fclose(f);

    printf("Contenuto dell'albero (in ordine):\n");
    in_print(radice);
    printf("\n");

    return 0;
}
