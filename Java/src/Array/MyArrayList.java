import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MyArrayList {
    
    private int dim;
    private List<Integer> numeri;

    public MyArrayList(int dim) {
        this.dim = dim;
        numeri = new ArrayList<>();
    }

    public void popola_valori() {
        Random random = new Random();
        
        for (int i = 0; i < dim; i++) {
            numeri.add(random.nextInt(0, 9));
        }
    }

    public void stampa() {
        for (int i = 0; i < dim; i++) {
            System.out.print(numeri.get(i) + " ");
        }
    }
    

}
