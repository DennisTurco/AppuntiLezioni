package EsercizioClassi;

public class Main {
    public static void main() {
        Studente studente1 = new Studente("Marta", "Bianchi", "23D4", 19, 2.5f);
        Studente studente2 = new Studente("Antonio", "Rossi", "56G2", 19, 1.5f);

        System.out.println(studente1.toString());
        System.out.println(studente2.toString());

        System.out.println(studente1.getNome());

        studente1.setEta(20);
        studente2.setAltezza(1.7f);

        System.out.println(studente1.toString());
        System.out.println(studente2.toString());
    }
}
