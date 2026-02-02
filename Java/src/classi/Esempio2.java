package classi;

// esempio piu' complesso -> classe dentro a classe
public class Esempio2 {
    public static void main(String[] args) {
        Studente s1 = new Studente("Giorgio", 2000, "3274654", "H1");
        Studente s2 = new Studente("Maria", 2002, "2347864", "G3");
        Studente s3 = new Studente("Francesco", 2002, "3217863", "G3");
        Studente s4 = new Studente("Matteo", 2012, "1236751", "J5");

        Scuola scuola = new Scuola();
        scuola.aggiungiStudente(s1);
        scuola.aggiungiStudente(s2);
        scuola.aggiungiStudente(s3);
        scuola.aggiungiStudente(s4);

        scuola.stampa();

        Studente studenteEtaMaggiore = scuola.getStudenteConEtaMaggiore();
        System.out.println("Studente più grande: " + studenteEtaMaggiore.calcolo_eta());
    }
}
