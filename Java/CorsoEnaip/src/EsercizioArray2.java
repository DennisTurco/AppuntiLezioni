/*
    1. Popolamento array casuare di 10 elementi interi di valore 0-50
    2. Stampiamo l'array
    3. Calcolare la somma e la media
    4. Ricercare il massimo elemento dell'array
    5. Ordiniamo l'array in senso crescente (usando il bubble sort)
*/

import java.util.Random;

public class EsercizioArray2 {
    public void Esercizio() {
        int[] numeri = new int[10];

        // popolamento array
        Random random = new Random();
        for (int i = 0; i < numeri.length; i++) {
            numeri[i] = random.nextInt(51);
        }

        // stampiamo l'array
        for (int i = 0; i < numeri.length; i++) {
            System.out.print(numeri[i] + " ");
        }

        // somma
        int somma = 0;
        for (int i = 0; i < numeri.length; i++) {
            somma = somma + numeri[i]; // somma += numeri[i];
        }

        /*
        In questo abbiamo messo tutto in 3 cicli separati:
        1. popolamento, 2. stampa, 3. somma
        Potremmo semplicemente fare tutto sotto lo stesso ciclo

        for (int i = 0; i < 10; i++) {
            numeri[i] = random.nextInt(51); // assegnazione (per il popolamento)
            System.out.print(numeri[i] + ""); // stampa
            somma = somma + numeri[i]; // somma
        }
        */

        System.out.println("\nSomma = " + somma);
        System.out.println("Media = " + (float) somma / 10);

        // ricerca massimo
        int max = numeri[0]; // il massimo per definizione appartiene all'insieme, per comodità lo assegnamo al primo valore dell'array
        for (int i = 0; i < numeri.length; i++) {
            if (max < numeri[i]) {
                max = numeri[i];
            }
        }
        System.out.println("Max = " + max);

        // ordinamento (bubble sort)
        for (int i = 0; i < numeri.length; i++) {
            for (int j = 0; j < numeri.length-1; j++) {
                if (numeri[j] > numeri[j+1]) {
                    int temp = numeri[j];
                    numeri[j] = numeri[j+1];
                    numeri[j+1] = temp;
                }
            }
        }

        // stampa
        for (int i = 0; i < numeri.length; i++) {
            System.out.print(numeri[i] + " ");
        }
    }
}
