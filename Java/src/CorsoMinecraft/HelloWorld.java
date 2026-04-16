package CorsoMinecraft;

import java.util.Scanner;

public class HelloWorld {

    // punto di partenza del programma -> tutto parte da qui
    public static void main(String[] args) {
        System.out.println("Hello World"); // sout e invio per autocompletamento

        // 1. controllo valore pari dispari
        int numero = 11;
        if (numero % 2 == 0) { // controllo se il resto della divisione per 2 del numero e' 0
            System.out.println("Pari");
        }
        else {
            System.out.println("Dispari");
        }

        // 2. controllo valore positivo, negativo, nullo
        // = assegnazione
        // == confronto
        int valore = 0;
        if (valore > 0) { // se
            System.out.println("Positivo");
        }
        else if (valore == 0) { // altrimenti se
            System.out.println("Nullo");
        }
        else { // altrimenti
            System.out.println("Negativo");
        }

        // 3. stampiamo i primi 10 numeri positivi
        // il for ripete le operazioni nelle graffe (nel corpo) finche' la condizione e' vera
        // il for ha 3 parti -> 1. valore di partenza, 2. condizione (si interrompe se falsa), 3. passo
        // i++ significa i = i + 1
        for (int i = 1; i <= 10; i++) {
            System.out.println(i);
        }

        // 4. chiedere input all'utente
        System.out.print("Dammi un numero: ");
        Scanner sc = new Scanner(System.in);
        int valoreInserito = sc.nextInt();
        System.out.println("Il valore inserito e': " + valoreInserito);

        // 5. stampiamo un triangolo
        /*
        *
        **
        ***
        ****
        *****
        */
        int altezza = sc.nextInt();
        for (int i = 0; i < altezza; i++) { // ciclo delle righe
            for (int j = 0; j < i + 1; j++) { // ciclo delle colonne
                System.out.print("*");
            }
            System.out.println(); // per andare a capo
        }
    }
}
