package EsercizioStudenteBase;

import java.util.LinkedList;

// una classe contiene attributi che definiscono l'oggetto
// e contiene dei metodi per poter operare su tale oggetto.
public class Studente {
    // attributi della classe. Di norma si fanno sempre private
    private String nome;
    private String cognome;
    private char sezione;
    private int eta;
    private LinkedList<Integer> voti;

    // metodo costruttore, serve per costruire (istanziare) un oggetto della classe
    public Studente(String nome, String cognome, char sezione, int eta) {
        this.nome = nome;
        this.cognome = cognome;
        this.sezione = sezione;
        this.eta = eta;
        this.voti = new LinkedList<>(); // alla costruzione, lo studente non ha voti
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

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public char getSezione() {
        return sezione;
    }

    public int getEta() {
        return eta;
    }

    public void setSezione(char sezione) {
        this.sezione = sezione;
    }

    public void setEta(int eta) {
        this.eta = eta;
    }

    // mettiamo override perche' questo motodo e' definito nella classe Object e tutte
    // le classi, inclusa questa, deriva da Object. In questo caso staimo ridefinendo il comportamento
    // della funzione toString.
    @Override
    public String toString() {
        return "Nome: " + nome + ", cognome: " + cognome + ", sezione: " + sezione + ", eta: " + eta;
    }
}
