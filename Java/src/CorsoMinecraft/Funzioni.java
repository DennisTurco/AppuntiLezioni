package CorsoMinecraft;

public class Funzioni {
    public static void main(String[] args) {
        /* SENZA LE FUNZIONI:
        // stampa i numeri da 20 a 100
        for (int i = 20; i <= 100; i++) {
            System.out.print(i + " ");
        }

        // stampa i numeri da 40 a 50
        for (int i = 40; i <= 50; i++) {
            System.out.print(i + " ");
        }

        // stampa i numeri da 45 a 72
        for (int i = 45; i <= 72; i++) {
            System.out.print(i + " ");
        }

        I codice funziona, ma e' migliorabile.
        problemi: abbiamo 3 cicli completamente (o quasi) uguali
            - codice duplicato
            - poco manutebile
            - poco leggibile
        */

        // chiamata di funzione
        funzioneSaluta();

        stampaInRange(20, 100);
        stampaInRange(40, 50);
        stampaInRange(45, 72);

        // in questo caso catturiamo il valore di output della funzione perche' ritorna qualcosa
        float media = calcolaMedia(4, 8);
        System.out.println("Media = " + media);
    }

    /*
    la funzione puo' avere un valore di ritorno (int, float, ec...). Se la funzione e' void, allora
    non restituisce nulla.

    Il nome della funzione segue tutte le regole usate anche per i nomi delle variabili (non va bene qualcosa come
    34funzione)

    all'interno delle parentesi tornde mettiamo i parametri, ovvero quello che passiamo in input alla funzione
    */
    public static void funzioneSaluta() {
        System.out.println("Ciao!");
    }

    public static void stampaInRange(int inizio, int fine) {
        for (int i = inizio; i <= fine; i++) {
            System.out.print(i + " ");
        }
    }

    public static float calcolaMedia(int v1, int v2) {
        return (v1 + v2) / 2;
    }
}
