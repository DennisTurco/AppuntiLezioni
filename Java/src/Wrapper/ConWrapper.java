package Wrapper;
public class ConWrapper {

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
        stampa(valori, null);
    }

    public static void function2(int[] valori) {
        stampa(valori, '-');
    }

    // la classe Wrapper permette di avere dei parametri opzionali (il chiamante passera' null)
    // Character e' il wrapper di char
    public static void stampa(int[] valori, Character delimitatore) {
        if (delimitatore == null) {
            delimitatore = ' ';
        }

        for (int i = 0; i < valori.length; i++) {
            System.out.print(valori[i] + "" + delimitatore);
        }
    }
}
