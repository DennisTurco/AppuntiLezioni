package Lista.ListaAuto;
public class Automobile {
    private String targa;
    private Parcheggio locazione; 
    private int viaggi; 

    /**
     * Costruttore della classe Automobile.
     * @param targa la targa dell'automobile
     * @param locazione la posizione del parcheggio dell'automobile
     */
    public Automobile(String targa, Parcheggio locazione) {
        this.targa = targa;
        this.locazione = locazione;
        this.viaggi = 0;
    }

    /**
     * Restituisce la targa dell'automobile.
     * @return la targa dell'automobile
     */
    public String getTarga() {
        return targa;
    }

    /**
     * Restituisce il numero di viaggi effettuati dall'automobile.
     * @return il numero di viaggi effettuati dall'automobile
     */
    public int getViaggi() {
        return viaggi;
    }

    /**
     * Restituisce la posizione del parcheggio dell'automobile.
     * @return la posizione del parcheggio dell'automobile
     */
    public Parcheggio getLocazione() {
        return locazione;
    }

    /**
     * Imposta la posizione del parcheggio dell'automobile.
     * @param locazione la nuova posizione del parcheggio dell'automobile
     */
    public void setLocazione(Parcheggio locazione) {
        this.locazione = locazione;
    }
    public void setViaggi(int viaggi) {
        this.viaggi = viaggi;
    }
    
    public void incrementaViaggi() {
        viaggi++;
    }

    /**
     * Imposta la targa dell'automobile.
     * @param targa la nuova targa dell'automobile
     */
    public void setTarga(String targa) {
        this.targa = targa;
    }

    @Override
    public String toString() {
        return locazione.getNome() + "," + targa + "," + viaggi;
    }
}