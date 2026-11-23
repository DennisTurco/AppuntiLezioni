package Ereditarieta2;

public class Animale {
    private String nome;
    private String colore;
    private double peso;
    private char sesso;

    public Animale(String nome, String colore, double peso, char sesso) {
        this.nome = nome;
        this.colore = colore;
        this.sesso = sesso;
        this.peso = peso;
    }

    public void suono() {
        System.out.println("Suono generico");
    }

    @Override
    public String toString() {
        return "nome: " + nome + ", colore: " + colore + ", peso: " + peso + ", sesso: " + sesso;
    }

    // getter
    public String getColore() {
        return colore;
    }
    public String getNome() {
        return nome;
    }
    public char getSesso() {
        return sesso;
    }
    public double getPeso() {
        return peso;
    }

    // setter
    public void setPeso(double peso) {
        this.peso = peso;
    }
}
