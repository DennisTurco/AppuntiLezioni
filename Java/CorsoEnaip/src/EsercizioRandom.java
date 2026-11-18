/*
    Genera 20 numeri casuali nell'intervallo da 0 a 10
    stampiamo solo i numeri > 5
*/

import java.util.Random;

public class EsercizioRandom {
    public void Esercizio() {
        Random random = new Random();
        for (int i = 0; i < 20; i++) {
            int valore = random.nextInt(11);
            if (valore > 5){
                System.out.print(valore + " ");
            }
        }
    }
}
