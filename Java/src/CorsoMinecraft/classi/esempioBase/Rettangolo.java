package CorsoMinecraft.classi.esempioBase;

// public -> visibile ovunque
// protected -> visibile a tutti a patto che abbiano lo stesso package (stessa cartella)
// private -> visibile solo all'interno della stessa classe
// ha attributi e metodi
public class Rettangolo {
    // attributi
    private float base;
    private float altezza;

    // costruttore (si possono avere piu' di uno se si vuole)
    public Rettangolo() {
        this.base = 0;
        this.altezza = 0;
    }

    public Rettangolo(float base, float altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    // metodi / comportamenti
    public float calcolaPerimetro() {
        float perimetro = base * 2 + altezza * 2;
        return perimetro;
    }

    public float calcolaArea() {
        float area = base * altezza;
        return area;
    }

    // getter
    public float getBase() {
        return base;
    }
    public float getAltezza() {
        return altezza;
    }

    // setter
    public void setBase(float base) {
        this.base = base;
    }
    public void setAltezza(float altezza) {
        this.altezza = altezza;
    }
}
