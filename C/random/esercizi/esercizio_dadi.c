/*
Un dado a 6 facce viene lanciato un numero N di volte. Prendi in input N e stampa il risultato di ogni lancio.
- Fornisci poi in output quante volte sono uscite le diverse facce del dado e
- la percentuale di 4,5 e 6 usciti sul totale (p.es. Percentuale da 4 a 6: 36.45%).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int N;

    printf("Inserisci il numero di lanci da fare: ");
    scanf("%d", &N);

    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;
    int d5 = 0;
    int d6 = 0;
    for (int i = 0; i < N; i++) {
        int random = rand() % 6 + 1; // da 1 a 6
        if (random == 1){
            d1++;
        }
        else if (random == 2) {
            d2++;
        }
        else if (random == 3) {
            d3++;
        }
        else if (random == 4) {
            d4++;
        }
        else if (random == 5) {
            d5++;
        }
        else {
            d6++;
        }
    }

    printf("Risultati  ottenuti dai lanci: \n");
    printf("valore 1 uscito %d volte\n", d1);
    printf("valore 2 uscito %d volte\n", d2);
    printf("valore 3 uscito %d volte\n", d3);
    printf("valore 4 uscito %d volte\n", d4);
    printf("valore 5 uscito %d volte\n", d5);
    printf("valore 6 uscito %d volte\n", d6);

    float percentuale_valore4 = (float) d4 / N * 100; // serve il casting a float perche' altrimenti un operazione tra due int mi dara' comunque un int e quindi se il risultato e' per esempio 0.4, mi restituira' solo la parte intera che e' 0
    float percentuale_valore5 = (float) d5 / N * 100;
    float percentuale_valore6 = (float) d6 / N * 100;

    printf("il valore 4 e' uscito con percentuale = %0.2f%\n", percentuale_valore4);
    printf("il valore 5 e' uscito con percentuale = %0.2f%\n", percentuale_valore5);
    printf("il valore 6 e' uscito con percentuale = %0.2f%\n", percentuale_valore6);

    return 0;
}