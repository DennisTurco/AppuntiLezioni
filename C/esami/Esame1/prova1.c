#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PERCORSO "../morse.txt"

int const numero_lettere = 21;

struct codifica {
    char lettera;
    char morse[10];
};

// PUNTO 1
struct codifica* leggi_file() {
    FILE *file = fopen(PERCORSO, "r");

    if (file == NULL) {
        printf("Errore: file inesistente!");
        exit(-1);
    }

    struct codifica *alfabeto = (struct codifica*)malloc(numero_lettere * sizeof(struct codifica));

    // lettura del file
    for (int i = 0; i < numero_lettere; i++) {
        fscanf(file, "%c %s\n", &alfabeto[i].lettera, alfabeto[i].morse);
    }

    fclose(file);

    return alfabeto;
}

void stampa (struct codifica *alfabeto) {
    for (int i = 0; i < numero_lettere; i++) {
        printf("%c %s\n", alfabeto[i].lettera, alfabeto[i].morse);
    }
}

// PUNTO 3
// ciao mondo
char *sentence2morse(char *frase, struct codifica *alfabeto)  { 
    char *frase_codificata = (char*) malloc(300 * sizeof(char));
    frase_codificata[0] = '\0'; // altrimenti mi becco questo: [`g;D♦☻--...--....-.-.]

    // itero per ogni lettera della frase da codificare
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == ' ') {
            strcat(frase_codificata, " ");
        }
        else {
            // itero alla ricerca della corrispondenza nel dizionario
            for (int j = 0; j < numero_lettere; j++) { 
                if (frase[i] == alfabeto[j].lettera || (frase[i] >= 97 && frase[i] <= 122 && frase[i]-32 == alfabeto[j].lettera)) {
                    strcat(frase_codificata, alfabeto[j].morse);
                    break;
                }
            }
        }
    }

    return frase_codificata;
}

int main () {
    struct codifica *alfabeto = leggi_file();
    //stampa(alfabeto);
    
    // PUNTO 2
    char responso;
    char *stringa = (char*)malloc(100 * sizeof(char));
    printf("Inserisci 'c' per codifica o 'x' per uscire: ");
    scanf("%c", &responso);
    if (responso == 'c') {
        printf("Inserisci la frase da codificare: ");
        scanf(" %[^\n]s", stringa);
        char *stringa_codificata = sentence2morse(stringa, alfabeto);
        printf("La frase [%s] in morse si codifica come [%s]", stringa, stringa_codificata);
        free(stringa_codificata);
    }

    free(stringa);
    free(alfabeto);

    return 0;
}