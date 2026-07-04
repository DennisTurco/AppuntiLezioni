package EsercizioStudenteBaseEreditarieta;

import java.util.LinkedList;

public class Studente extends Persona {
    private char sezione;
    private LinkedList<Integer> voti;

    public Studente(String nome, String cognome, char sezione, int eta) {
        super(nome, cognome, eta); // richiama il costruttore della classe base per questi 3 attibuti
        this.sezione = sezione;
        this.voti = new LinkedList<>();
    }

    public void aggiungiVoto(int voto) {
        voti.add(voto);
    }

    public void aggiungiVoti(LinkedList<Integer> votiDaAggiungere) {
        for (int i = 0; i < votiDaAggiungere.size(); i++) {
            aggiungiVoto(votiDaAggiungere.get(i));
        }
    }

    public float calcolaMedia() {
        float somma = 0;
        for (int i = 0; i < voti.size(); i++) {
            somma = somma + voti.get(i);
        }
        return somma / voti.size();
    }

    public char getSezione() {
        return sezione;
    }

    public void setSezione(char sezione) {
        this.sezione = sezione;
    }

    @Override
    public String toString() {
        return super.toString() + ", sezione: " + sezione;
    }
}
