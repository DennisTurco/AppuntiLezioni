#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

// ritorna matrice dinamica di qualsiasi dimensione di CHAR
// i primi due numeri del file sono le righe e le colonne:
/*
10 10
a b e f g a b c m n
a b e f g a b c m n
a b e f g A b c m n
a b e f g a b c m n
a b e f g a b c m n
a b e f g a b c m n
a b e f g a b c m n
a b e f g a B c m n
a b e f g a b c m n
a b e f g a b c m N

Funzione che riceve una matrice di char m[MAX][MAX]
e una stringa s[] e verifica se la stringa � in
una linea o in una colonna della matrice matrice.
*/

char **caricaMatriceDaFile(const char nomeFile[], int rc[]) {
	char **matrice;
	char spazio;
	FILE *file = fopen(nomeFile, "r");
	if (file == NULL) {
		printf("Impossibile aprire il file %s\n", nomeFile);
		exit(0);
	}

	fscanf(file, "%d %d", &rc[0], &rc[1]); // carica righe in rc[0] e colonne in rc[1]

	matrice = malloc(rc[0] * sizeof(char *)); // alloco spazio x la matrice dinamica
	for (int i = 0; i < rc[0]; ++i)
		matrice[i] = malloc(rc[1]);

	for (int i = 0; i < rc[0]; i++) { // caricamento da file della matrice dinamica
		for (int j = 0; j < rc[1]; j++) {
			fscanf(file, "%c%c", &spazio, &matrice[i][j]);
		}
	}

	fclose(file);
	return matrice; // ritorno
}

int main() {
	char **matrice;
	int rc[2]; // rc[0]==righe / rc[1]==colonne

	matrice = caricaMatriceDaFile("../matrice.txt", rc);

	printf("Matrice %dx%d:\n", rc[0], rc[1]);
	for (int i = 0; i < rc[0]; i++) {
		for (int j = 0; j < rc[1]; j++) {
			printf("%2c", matrice[i][j]);
		}
		printf("\n");
	}
	char s[MAX];
	printf("Inserisci la tua stringa: ");
	gets(s);
	int countRow = 0;
	int countCol = 0;

	// Controllo righe
    for (int i = 0; i < rc[0]; i++) {
        for (int j = 0; j <= rc[1] - strlen(s); j++) {
            countRow = 0;
            while (countRow < strlen(s) && matrice[i][j + countRow] == s[countRow]) {
                countRow++;
            }
            if (countRow == strlen(s)) {
                printf("La stringa si trova nella riga %d.\n", i + 1);
                return 0;
            }
        }
    }

    // Controllo colonne
    for (int j = 0; j < rc[1]; j++) {
        for (int i = 0; i <= rc[0] - strlen(s); i++) {
            countCol = 0;
            while (countCol < strlen(s) && matrice[i + countCol][j] == s[countCol]) {
                countCol++;
            }
            if (countCol == strlen(s)) {
                printf("La stringa si trova nella colonna %d.\n", j + 1);
                return 0;
            }
        }
    }

	return 0;
}