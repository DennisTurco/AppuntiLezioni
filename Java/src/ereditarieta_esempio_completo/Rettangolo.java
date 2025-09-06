package Java.src.ereditarieta_esempio_completo;

// classe base
public class Rettangolo {
    // attributi
    private int base;
    private int altezza;
    
    // costruttore senza parametri
    public Rettangolo() {
        this.base = 0;
        this.altezza = 0;
    }

    // costruttore con 2 parametri
    public Rettangolo(int base, int altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    // metodo
    public int perimetro() {
        return 2*base + 2*altezza;
    }

    // metodo
    public int area() {
        return base * altezza;
    }

    // metodi getter
    public int getBase() {
        return base;
    }
    public int getAltezza() {
        return altezza;
    }
}
