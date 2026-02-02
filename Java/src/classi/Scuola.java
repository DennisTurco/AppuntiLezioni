package classi;

import java.util.ArrayList;

public class Scuola {
    private ArrayList<Studente> studenti;
    private int numeroStudenti;

    public Scuola() {
        studenti = new ArrayList<>();
        numeroStudenti = 0;
    }

    public void aggiungiStudente(Studente studente) {
        studenti.add(studente);
        numeroStudenti++;
    }

    public void stampa() {
        for (Studente stud : studenti) {
            stud.stampa();
        }
    }

    public Studente getStudenteConEtaMaggiore() {
        Studente studenteConEtaMax = studenti.get(0);
        for (Studente stud : studenti) {
            if (stud.getAnno() < studenteConEtaMax.getAnno()) {
                studenteConEtaMax = stud;
            }
        }
        return studenteConEtaMax;
    }

    public int getNumeroStudenti() {
        return numeroStudenti;
    }
}
