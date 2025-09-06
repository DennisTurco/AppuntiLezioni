package EserciziRandom;
/*
 * Programma che passa un array ad una funzione e che ritorni un nuovo array ordinato al chiamante.
*/

public class App {
    
    public static double[] ordinaValori(double[] valori) {
        // 1. crea copia array
        double valoriOrdinati[] = new double[valori.length];
        for (int i = 0; i < valori.length; i++) {
            valoriOrdinati[i] = valori[i];
        }

        // 2. ordina la copia (bubble sort)
        for (int i = 0; i < valoriOrdinati.length; i++) {
            for (int j = 0; j < valoriOrdinati.length - 1; j++) {
                if (valoriOrdinati[j] > valoriOrdinati[j+1]) {
                    double temp = valoriOrdinati[j];
                    valoriOrdinati[j] = valoriOrdinati[j+1];
                    valoriOrdinati[j+1] = temp;
                }
            }
        }
        // Arrays.sort(valoriOrdinati);

        // 3. ritorna la copia ordinata
        return valoriOrdinati;
    }

    public static void stampa(double[] valori) {
        for (int i = 0; i < valori.length; i++) {
            System.out.print(valori[i] + " ");
        }
        System.out.println();
    }

    
    public static void main(String[] args) throws Exception {
        double valori[] = new double[5];
        valori[0] = 2; 
        valori[1] = 1; 
        valori[2] = 4; 
        valori[3] = 0; 
        valori[4] = 3; 

        
        double valoriOrdinati[] = ordinaValori(valori);
        stampa(valori);
        stampa(valoriOrdinati);
    }
}
