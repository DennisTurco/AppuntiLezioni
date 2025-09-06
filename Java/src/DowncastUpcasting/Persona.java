package DowncastUpcasting;
public class Persona {
    private String nome;
    private String cognome;
    private String CF;

    public Persona(String nome, String cognome, String CF) {
        this.nome = nome;
        this.cognome = cognome;
        this.CF = CF;
    }

    public void saluta() {
        System.out.println("Ciao dalla persona: " + nome);
    }

    @Override
    public String toString() {
        return "nome = " + nome + ", cognome = " + cognome + ", CF = " + CF;
    }

    public String getNome() {
        return nome;
    }
}
