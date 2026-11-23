package EsercizioClassi3;

public class Cane {
    private String nome;
    private String colore;
    private double peso;
    private char sesso;
    private boolean aggressivo;

    public Cane(String nome, String colore, double peso, char sesso, boolean aggressivo) {
        this.nome = nome;
        this.colore = colore;
        this.sesso = sesso;
        this.aggressivo = aggressivo;
    }

    public void suono() {
        System.out.println("Bau!");
    }

    public void cambiaAggressivita() {
        if (aggressivo) { // == true
            aggressivo = false;
        } else {
            aggressivo = true;
        }
    }


    @Override
    public String toString() {
        return "nome: " + nome + ", colore: " + colore + ", peso: " + peso + ", sesso: " + sesso + ", aggressivo: " + aggressivo;
    }
}
