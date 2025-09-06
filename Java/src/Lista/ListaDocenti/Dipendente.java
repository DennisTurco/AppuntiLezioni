package Lista.ListaDocenti;
public class Dipendente {
    private String nome;
    private String cognome;

    public Dipendente(String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
    }   

    public String getCognome() {
        return cognome;
    }
    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return this.nome + " " + this.cognome;
    }
}
