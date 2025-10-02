/*

Avete a disposizione il file strutturato PHONE2025.DAT
avente il seguente tracciato:
Nome    string[6];
Numtel  string[10];
Il vostro compito � prima di tutto caricare i dati di PHONE2025.DAT su di una lista SENZA MANDARE NULLA A VIDEO.
Terminato il caricamento, dovete mandare a video un menu con le seguenti opzioni:
1. mostrare il contenuto della lista
2. eliminare dalla lista tutti gli elementi con il Numtel che inizia con una cifra inserita dall�utente
3. riordinare la lista in ordine di numero di telefono
4. salvare la lista cos� com�� sul file NUOVOPHONE.DAT
5. salvare la lista ordinata per numero di telefono sul file ORDPHONE.DAT
6. eliminare la lista
7. terminare il programma
Le opzioni del menu possono essere richieste ed eseguite
in qualunque ordine e anche pi� volte (tranne ovviamente l�opzione 7).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro {
    char nome[6];
    char numtel[10];
};

struct nodo {
    struct registro elenco;
    struct nodo *next;
};

void stampa_lista(struct nodo *head) {
    struct nodo *temp = head;
    while (temp != NULL) {
        puts(temp->elenco.nome);
        puts(temp->elenco.numtel);
        temp = temp->next;
    }
}

void elimina_lista(struct nodo **head) {
    while (*head != NULL) {
        struct nodo *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void elimina_in_base_al_numero(struct nodo **head) {
    if (head == NULL || *head == NULL) return;

    char cifranumtel;
    printf("\nInserisci la prima cifra del numero di telefono: ");
    scanf(" %c", &cifranumtel);

    struct nodo *curr = *head, *prev = NULL;

    while (curr != NULL) {
        if (curr->elenco.numtel[0] == cifranumtel) {
            struct nodo *da_eliminare = curr;
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
            free(da_eliminare);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void scambio(struct registro *a, struct registro *b) {
    struct registro temp = *a;
    *a = *b;
    *b = temp;
}

void ordinamento_per_num(struct nodo *head) {
    if (!head) return;

    int scambi;
    struct nodo *ptr1, *lptr = NULL;

    do {
        scambi = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->elenco.numtel, ptr1->next->elenco.numtel) > 0) {
                scambio(&ptr1->elenco, &ptr1->next->elenco);
                scambi = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (scambi);
}

void leggi_da_file(struct nodo **head, FILE *file) {
    struct registro buffer;
    struct nodo *temp = NULL;

    while (fread(&buffer, sizeof(struct registro), 1, file) == 1) {
        struct nodo *nuovo = malloc(sizeof(struct nodo));
        if (!nuovo) {
            printf("Errore allocazione memoria");
            exit(EXIT_FAILURE); // per interompere forzatamente il programma
        }

        nuovo->elenco = buffer;
        nuovo->next = NULL;

        if (*head == NULL) {
            *head = nuovo;
        } else {
            temp->next = nuovo;
        }
        temp = nuovo;
    }

    fclose(file);
}

void menu(struct nodo **head) {
    int risposta;

    do {
        printf("\n============================================================\n");
        printf("                          MENU PRINCIPALE\n");
        printf("============================================================\n");
        printf("1. Mostrare il contenuto della lista\n");
        printf("2. Eliminare numeri con una cifra iniziale specifica\n");
        printf("3. Riordinare la lista per numero di telefono\n");
        printf("4. Salvare su NUOVOPHONE.DAT [Non implementato]\n");
        printf("5. Salvare ordinata su ORDPHONE.DAT [Non implementato]\n");
        printf("6. Eliminare la lista\n");
        printf("7. Uscire\n");
        printf("Scegli un'opzione (1-7): ");
        scanf("%d", &risposta);

        switch (risposta) {
            case 1:
                stampa_lista(*head);
                break;
            case 2:
                elimina_in_base_al_numero(head);
                break;
            case 3:
                ordinamento_per_num(*head);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                elimina_lista(head);
                printf("Lista eliminata.\n");
                break;
            case 7:
                printf("Fine programma.\n");
                break;
            default:
                printf("Opzione non valida!\n");
        }
    } while (risposta != 7);
}

int main(void) {
    struct nodo *head = NULL;
    FILE *file = fopen("../phone2025.dat", "rb");

    if (!file) {
        printf("Errore nell'apertura del file");
        return -1;
    }

    leggi_da_file(&head, file);
    menu(&head);

    return 0;
}