package Wrapper;
public class SenzaWrapper {
    
    /*
    
    le classi wrapper a differnza dei tipi primitivi
    permettono di avere un valore null per quel tipo.

    es:

    Integer (wrapper di int) -> potra' avere valori come: 1, 0, -400, -3, 56, ..., null
    String (wrapper di string) -> potra' avere valori come: "ciao", "asd", ..., null
    ...
    */

    public static void main(String[] args) throws Exception {
        int[] valori = new int[5];
        valori[0] = 1;
        valori[1] = 0;
        valori[2] = 2;
        valori[3] = 3;
        valori[4] = 1;
        
        System.out.println("###################### FUNCTION 1 ######################");
        function1(valori);

        System.out.println("\n###################### FUNCTION 2 ######################");
        function2(valori);
    }

    public static void function1(int[] valori) {
        stampa(valori);
    }

    public static void function2(int[] valori) {
        stampa(valori, '-');
    }

    public static void stampa(int[] valori) {
        for (int i = 0; i < valori.length; i++) {
            System.out.print(valori[i] + " ");
        }
    }

    public static void stampa(int[] valori, char delimitatore) {
        for (int i = 0; i < valori.length; i++) {
            System.out.print(valori[i] + "" + delimitatore);
        }
    }
}
