package Binding;

public class Smartphone implements Device {
    private String modello;
    private float prezzo;

    public Smartphone(String modello, float prezzo) {
        this.modello = modello;
        this.prezzo = prezzo;
    }

    public void setMarca(String marca) {
        System.out.println("settiamo la nuova marca");
    }

    public void calcolaSconto(float sconto) {
        System.out.println("calcoliamo lo sconto per lo smartphone");
    }

    @Override
    public String toString() {
        return "Smatphone -> modello: " + modello + ", prezzo: " + prezzo;
    }
}
