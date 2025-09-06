package DowncastUpcasting;
public class Studente extends Persona{
    private String matricola;

    public Studente(String nome, String cognome, String CF, String matricola) {
        super(nome, cognome, CF);
        this.matricola = matricola;
    }

    public void saluta() {
        System.out.println("Ciao dallo studente: " + getNome());
    }

    @Override
    public String toString() {
        return super.toString() + ", matricola = " + matricola;
    }
}
