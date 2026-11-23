package EsercizioClassi2;

public class Main {
    public static void main() {
        Triangolo t1 = new Triangolo(2.5, 4.3, 0);
        System.out.println(t1.calcolaArea());

        Triangolo t2 = new Triangolo(0, 4.3, 12.3);
        System.out.println(t2.calcolaAltezza());
    }
}
