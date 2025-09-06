package Lista.ListaAuto;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Parcheggio {
    private String nome;
    private ArrayList<Automobile> automobili;

    /**
     * Costruttore della classe Parcheggio.
     * @param nome il nome del parcheggio
     */
    public Parcheggio(String nome) {
        this.nome = nome;
        this.automobili = new ArrayList<>();
    }

    /**
     * Restituisce il nome del parcheggio.
     * @return il nome del parcheggio
     */
    public String getNome() {
        return nome;
    }

    /**
     * Restituisce la prima automobile parcheggiata nel parcheggio.
     * @return la prima automobile parcheggiata nel parcheggio
     */
    public Automobile getPrimaAutomobile() {
        return automobili.get(0);
    }

    /**
     * Aggiunge un'automobile alla lista di automobili parcheggiate nel parcheggio.
     * @param nuovaAutomobile l'automobile da aggiungere al parcheggio
     */
    public void aggiungiAutomobile(Automobile nuovaAutomobile) {
        automobili.add(nuovaAutomobile);
    }
    
    /**
     * Conta il numero di automobili parcheggiate nel parcheggio.
     * @return il numero di automobili parcheggiate nel parcheggio
     */
    public int contaAutomobili() {
        return automobili.size();
    }
    
    /**
     * Rimuove le automobili che hanno effettuato un numero minimo di viaggi dal parcheggio.
     * @param viaggiMinimi il numero minimo di viaggi per mantenere un'automobile nel parcheggio
     */
    public void rimuoviAutomobili(int viaggiMinimi) {
        Iterator<Automobile> iter = automobili.iterator();

        while(iter.hasNext()) {
            Automobile auto = iter.next();

            if (auto.getViaggi() >= viaggiMinimi){
                iter.remove();
            }
        }
    }

    /**
     * Rimuove l'automobile con la targa passata.
     * @param targa targa dell'auto da rimuovere
     */
    public void rimuoviAutomobili(String targa) {
        for (Automobile auto : automobili) {
            if (auto.getTarga().equals(targa)){
                automobili.remove(auto);
                break;
            }
        }
    }

    /**
     * ritorna tutte le auto presenti in un dato parcheggio.
     * @return la lista delle automobili di un parcheggio
     */
    public List<Automobile> getAutomobili() {
        return automobili;
    }
}