package EsercizioClassi;

public class Studente {
    // attributi della classe
    private String nome;
    private String cognome;
    private String matricola;
    private int eta;
    private float altezza;

    // costruttore
    public Studente(String nome, String cognome, String matricola, int eta, float altezza) {
        this.nome = nome;
        this.cognome = cognome;
        this.matricola = matricola;
        this.eta = eta;
        this.altezza = altezza;
    }

    public String nomeCompleto() {
        return nome + " " + cognome;
    }

    // getter (per leggere)
    public String getCognome() {
        return cognome;
    }
    public float getAltezza() {
        return altezza;
    }
    public int getEta() {
        return eta;
    }
    public String getNome() {
        return nome;
    }
    public String getMatricola() {
        return matricola;
    }

    // setter (per scrivere)
    public void setEta(int eta) {
        this.eta = eta;
    }
    public void setAltezza(float altezza) {
        this.altezza = altezza;
    }
    public void setCognome(String cognome) {
        this.cognome = cognome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + ", cognome: " + cognome  + ", matricola: " + matricola + ", eta': " + eta + ", altezza: " + altezza;
    }
}
