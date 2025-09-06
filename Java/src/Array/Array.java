import java.util.Random;

public class Array {
    
    private int[] numeri;

    public Array(int dim) {
        numeri = new int[dim];
    }

    public void popola_valori() {
        Random random = new Random();
        
        for (int i = 0; i < numeri.length; i++) {
            numeri[i] = random.nextInt(0, 9);
        }
    }

    public void stampa() {
        for (int i = 0; i < numeri.length; i++) {
            System.out.print(numeri[i] + " ");
        }
    }
    

}
