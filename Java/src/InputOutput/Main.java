// package serve ad indicare dove si trova il file attuale rispetto alla cartella src (cartella root) -> in che cartella si trova?
package InputOutput;

import java.util.Scanner;

public class Main {

    // metodo main - ogni progetto possiede un metodo main, dove tutto parte
    public static void main(String[] args) { 

        int x = 5;

        //?------------------------------- Output
        //* output1
        System.out.println("Questa e' una frase"); 
        System.out.println("Come Stai?");
        System.out.println("Il valore x equilave a: " + x);

        System.out.println("----------------------");

        //* output2
        System.out.print("Questa e' una frase");
        System.out.print("Come Stai?");
        System.out.print("Il valore x equilave a: " + x);

        System.out.println("\n----------------------");

        //* output3
        System.out.printf("Questa e' una frase");
        System.out.printf("Come Stai?");
        System.out.printf("Il valore x equilave a: %d", x);

        System.out.println("\n----------------------");
       
        //?------------------------------- Input
        // creazione oggetto di tipo scanner
        Scanner input = new Scanner(System.in);

        // lettura su variabile
        int y = input.nextInt();

        // stampa a schermo dalla variabile ottenuta
        System.out.println("y = " + y);

        // chiusura dell'oggetto di tipo scanner
        input.close();

        //! input metodo alternativo e brutto
        /*InputStreamReader inputStreamReader = new InputStreamReader(System.in);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        try {
            String frase = bufferedReader.readLine();
            int z = Integer.valueOf(frase).intValue();
            bufferedReader.close();
            inputStreamReader.close();
            System.out.println("z = " + z);
        } catch (IOException exception) {
            exception.printStackTrace();
        }*/

        System.out.println("Programma Terminato");
    }
}
