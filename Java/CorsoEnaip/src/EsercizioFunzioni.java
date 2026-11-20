/*
Rifare l'esercizio EsercizioArray2.java
usando le funzioni
*/

/*
Perchè le funzioni?
Danno diversi benefici:
1. Riusabilità del codice -> evitiamo quindi la duplicazione
2. Leggibilità del codice
3. Manutenibilità del codice
*/

import java.util.Random;

public class EsercizioFunzioni {
    public void Esercizio() {
        int[] numeri = new int[10];

        popolamentoArrayRandomico(numeri); // chiamata delle funzione

        stampaArray(numeri);

        int somma = calcolaSomma(numeri);

        System.out.println("\nSomma = " + somma);
        System.out.println("Media = " + (float) somma / 10);

        int max = ottieniMassimo(numeri);
        System.out.println("Max = " + max);

        ordinamentoCrescente(numeri);

        stampaArray(numeri);
    }

    private void popolamentoArrayRandomico(int[] numeri) {
        Random random = new Random();
        for (int i = 0; i < numeri.length; i++) {
            numeri[i] = random.nextInt(51);
        }
    }

    private void stampaArray(int[] numeri) {
        for (int i = 0; i < numeri.length; i++) {
            System.out.print(numeri[i] + " ");
        }
    }

    private int calcolaSomma(int[] numeri) {
        int somma = 0;
        for (int i = 0; i < numeri.length; i++) {
            somma = somma + numeri[i];
        }
        return somma;
    }

    private int ottieniMassimo(int[] numeri) {
        int max = numeri[0];
        for (int i = 0; i < numeri.length; i++) {
            if (max < numeri[i]) {
                max = numeri[i];
            }
        }
        return max;
    }

    private void ordinamentoCrescente(int[] numeri) {
        for (int i = 0; i < numeri.length; i++) {
            for (int j = 0; j < numeri.length-1; j++) {
                if (numeri[j] > numeri[j+1]) {
                    int temp = numeri[j];
                    numeri[j] = numeri[j+1];
                    numeri[j+1] = temp;
                }
            }
        }
    }
}
