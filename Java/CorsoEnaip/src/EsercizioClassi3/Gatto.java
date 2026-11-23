package EsercizioClassi3;

public class Gatto {
    private String nome;
    private String colore;
    private double peso;
    private char sesso;
    private int viteRimaste;

    public Gatto(String nome, String colore, double peso, char sesso, int viteRimaste) {
        this.nome = nome;
        this.colore = colore;
        this.peso = peso;
        this.sesso = sesso;
        this.viteRimaste = viteRimaste;
    }

    public Gatto(String nome, String colore, double peso, char sesso) {
        this.nome = nome;
        this.colore = colore;
        this.peso = peso;
        this.sesso = sesso;
        this.viteRimaste = 7;
    }

    public void suono() {
        System.out.println("Miao!");
    }

    public void perdiVita() {
        viteRimaste--;
        if (viteRimaste == 0) {
            System.out.println("Sono morto!");
        }
        else {
            System.out.println("Aia!");
        }
    }

    public int getViteRimaste() {
        return viteRimaste;
    }
    //...

    @Override
    public String toString() {
        return "nome: " + nome + ", colore: " + colore + ", peso: " + peso + ", sesso: " + sesso + ", viteRimaste: " + viteRimaste;
    }
}
