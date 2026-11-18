/*
    L'obbiettivo dell'esercizio è quello di stampare a schermo
    100 valori, nell'intervallo da 1 a 100 multipli di 3
*/

// 3 tipi di ciclo in java: for, foreach (for), while

// divisioni e resti per 3 (r = resto, v = valore):
// 3 : 3 -> v = 1, r = 0
// 4 : 3 -> v = 1, r = 1
// 5 : 3 -> v = 1, r = 2
// 6 : 3 -> v = 2, r = 0
// 9 : 3 -> v = 3, r = 0
// 14 : 3 -> v = 4, r = 2

public class EsercizioIntroduttivo {
    public void Esercizio() {
        for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0) { // controlliamo se il resto della divione è 0
                System.out.print(i + " ");
            }
        }
    }
}
