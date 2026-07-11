package EsercizioStudenteBaseEreditarieta;

import java.util.LinkedList;
import java.util.List;

public class Main {
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

        Insegnante i1 = new Insegnante("Laura", "Verdi", "Matematica", true, 45);
        Insegnante i2 = new Insegnante("Paolo", "Neri", "Storia", false, 38);

        System.out.println(i1.toString());
        System.out.println(i2.toString());

        // dimostrazione di polimorfismo: Studente e Insegnante sono entrambi delle Persona
        List<Persona> persone = List.of(s1, s2, i1, i2);
        for (int i = 0; i < persone.size(); i++) {
            System.out.println(persone.get(i).toString());
        }
    }
}
