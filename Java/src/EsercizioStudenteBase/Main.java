package EsercizioStudenteBase;

import java.util.LinkedList;
import java.util.List;

public class Main {

    // punto iniziale di un rpogramma in java
    public static void main(String[] args) {
        Studente s1 = new Studente("Anna", "Bianchini", 'H', 16);
        Studente s2 = new Studente("Marco", "Rossini", 'A', 18);

        s1.setEta(17);
        s2.setEta(19);
        s2.setSezione('F');
        // s1.setNome("Nuovo Nome"); // non esiste il set del nome -> non vogliamo che uno studente possa cambiare nome

        System.out.println(s1.toString());
        System.out.println(s2.toString());

        System.out.println("Eta di Marco: " + s2.getEta());

        s1.aggiungiVoto(6);
        s1.aggiungiVoto(10);
        s1.aggiungiVoto(5);
        s1.aggiungiVoto(8);
        s1.aggiungiVoto(7);
        s1.aggiungiVoti(new LinkedList<>(List.of(6,3,7)));
        float media = s1.calcolaMedia();
        System.out.println("Media voti Anna: " + media);
    }
}
