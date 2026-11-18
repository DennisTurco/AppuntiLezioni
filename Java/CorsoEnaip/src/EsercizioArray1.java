/*
    1. Popolare randomicamente un array di 10 numeri interi (da 0 a 5)
    2. Stampiamo l'array
    3. calcolare la somma totale
    4. calcolare la media
*/

import java.util.Random;

public class EsercizioArray1 {
    public void Esercizio() {

        // dichiarazione dell'array
        int[] valori = new int[10];

        Random random = new Random();

        // popolamento array
        for (int i = 0; i < 10; i++) {
            valori[i] = random.nextInt(6);
        }

        // stampa
        for (int i = 0; i < 10; i++) {
            System.out.print(valori[i] + " ");
        }

        // somma
        int somma = 0;
        for (int i = 0; i < 10; i++) {
            somma = somma + valori[i];
        }
        System.out.println("\nSomma complessiva = " + somma);

        // media
        float media = (float) somma / 10;
        System.out.println("La media è = " + media);
    }
}
