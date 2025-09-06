package Wrapper;
/**
 * Breve descrizione della classe.
 * Una descrizione più dettagliata se necessario.
 *
 * @author TuoNome
 * @version 1.0
 */
public class Javadoc {

    /**
     * Campo di esempio.
     */
    private int valore;

    /**
     * Costruttore della classe EsempioClasse.
     *
     * @param valore Il valore iniziale del campo.
     */
    public Javadoc(int valore) {
        this.valore = valore;
    }

    /**
     * Ottiene il valore del campo.
     *
     * @return Il valore del campo.
     */
    public int getValore() {
        return valore;
    }

    /**
     * Imposta il valore del campo.
     *
     * @param valore Il nuovo valore da impostare.
     */
    public void setValore(int valore) {
        this.valore = valore;
    }

    /**
     * Metodo di esempio che esegue un'operazione.
     *
     * @param numero Un parametro di tipo int da usare nell'operazione.
     * @return Il risultato dell'operazione.
     * @throws IllegalArgumentException se il numero è negativo.
     * @throws IllegalStateException se il numero è 0.
     */
    public int operazione(int numero) {
        if (numero < 0) {
            throw new IllegalArgumentException("Il numero non può essere negativo.");
        }

        if (numero == 0) {
            throw new IllegalStateException("Il numero non può essere 0.");
        }

        return valore + numero;
    }
}
