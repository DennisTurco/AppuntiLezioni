#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    char nome[32];
    char cognome[32];
    char nome_completo[65] = ""; // 65 perchè 32 + 32 = 64 + il carattere spazio = 65

    printf("Inserire il nome: ");
    scanf("%[^\n]", nome);
    printf("Inserire il cognome: ");
    scanf("%[^\n]", cognome);
    
    // creazione nome completo
    strcat(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, cognome);

    // stampo il nome completo  
    printf("%s\n", nome_completo);

    // sostituisco lo spazio con il terminatore
    for (int i = 0; i < strlen(nome_completo); i++) {
        if (nome_completo[i] == ' ') {
            nome_completo[i] = '\0';
        }
    }

    printf("%s", nome_completo);
}