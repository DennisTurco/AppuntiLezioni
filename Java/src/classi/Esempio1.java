package classi;

// esempio base

public class Esempio1 {
    public static void main(String[] args) {
        Studente s1 = new Studente("Giorgio", 2000, "3274654", "H1");

        s1.stampa();

        s1.setClasse("G3");

        s1.stampa();
        System.out.println("Eta': " + s1.calcolo_eta());
    }
}
