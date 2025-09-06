package Binding;
public class PC implements Device {
    private String modello;
    private float prezzo;
    private int ram;

    public PC(String modello, float prezzo, int ram) {
        this.modello = modello;
        this.prezzo = prezzo;
        this.ram = ram;
    }

    public void setMarca(String marca) {
        System.out.println("settiamo la nuova marca");
    }

    public void calcolaSconto(float sconto) {
        System.out.println("calcoliamo lo sconto per il pc");
    }

    @Override
    public String toString() {
        return "PC -> modello: " + modello + ", prezzo: " + prezzo + ", ram: " + ram;
    }
}