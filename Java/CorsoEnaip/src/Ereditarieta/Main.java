package Ereditarieta;

public class Main {
    public static void main() {
        Cane c1 = new Cane("Patrik", "Marrone", 30.12, 'm', false);
        Gatto g1 = new Gatto("Mario", "Rosso", 3.32, 'm');

        System.out.println(c1.toString());
        System.out.println(g1.toString());

        c1.cambiaAggressivita();
        System.out.println(c1.toString());

        c1.suono();
        g1.suono();

        while (g1.getViteRimaste() > 0) {
            g1.perdiVita();
        }
    }
}
