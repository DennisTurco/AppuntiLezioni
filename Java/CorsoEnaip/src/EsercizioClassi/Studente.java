package EsercizioClassi;

public class Studente {
    // attributi della classe
    private String nome;
    private String cognome;
    private int eta;
    private float altezza;

    // costruttore
    public Studente(String nome, String cognome, int eta, float altezza) {
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.altezza = altezza;
    }

    public String nomeCompleto() {
        return nome + " " + cognome;
    }
}
