package Ereditarieta2;

public class Gatto extends Animale {
    private int viteRimaste;

    public Gatto(String nome, String colore, double peso, char sesso, int viteRimaste) {
        super(nome, colore, peso, sesso);
        this.viteRimaste = viteRimaste;
    }

    public Gatto(String nome, String colore, double peso, char sesso) {
        super(nome, colore, peso, sesso);
        this.viteRimaste = 7;
    }

    @Override
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

    @Override
    public String toString() {
        return super.toString() + ", viteRimaste: " + viteRimaste;
    }
}
