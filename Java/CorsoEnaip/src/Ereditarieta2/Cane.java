package Ereditarieta2;

public class Cane extends Animale {
    private boolean aggressivo;

    public Cane(String nome, String colore, double peso, char sesso, boolean aggressivo) {
        super(nome, colore, peso, sesso); // richiama il costruttore di animale (classe base)
        this.aggressivo = aggressivo;
    }

    // metto override perche' ridefinisco il funzionamento del metodo della
    // classe base (Animale)
    @Override
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
        return super.toString() + ", aggressivo: " + aggressivo;
    }
}
