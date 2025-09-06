package Lista.ListaAuto;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CarSharing {
    private List<Parcheggio> parcheggi;
    
    /**
     * Costruttore della classe CarSharing.
     * Inizializza il primo parcheggio a null.
     */
    public CarSharing() {
        this.parcheggi = new ArrayList<>();
    }
    
    /**
     * Aggiunge un nuovo parcheggio al sistema di Car Sharing.
     * @param nomeParcheggio il nome del nuovo parcheggio da aggiungere
     */
    public void  aggiungiParcheggio(String nomeParcheggio) {
        if (trovaParcheggio(nomeParcheggio) != null) {
            throw new IllegalArgumentException("Il parcheggio " + nomeParcheggio + " esiste gia'");
        }

        parcheggi.add(new Parcheggio(nomeParcheggio));
    }
    public void  aggiungiParcheggio(Parcheggio parcheggio) {
        if (trovaParcheggio(parcheggio.getNome()) != null) {
            throw new IllegalArgumentException("Il parcheggio " + parcheggio.getNome() + " esiste gia'");
        }

        parcheggi.add(parcheggio);
    }
    
    public void aggiungiAutomobile(String targa, String nomeParcheggio) {
        Parcheggio parcheggio = trovaParcheggio(nomeParcheggio);
        if (parcheggio == null) {
            throw new IllegalArgumentException("Il parcheggio " + nomeParcheggio + " non esiste");
        }

        if (trovaAutomobile(targa) != null) {
            throw new IllegalArgumentException("L'automobile " + targa + " esiste gia'");
        }

        Automobile auto = new Automobile(targa, parcheggio);
        parcheggio.aggiungiAutomobile(auto);
    }

    public void aggiungiAutomobile(Automobile auto, String nomeParcheggio) {
        Parcheggio parcheggio = trovaParcheggio(nomeParcheggio);
        if (parcheggio == null){
            throw new IllegalArgumentException("Il parcheggio " + nomeParcheggio + " non esiste");
        }

        parcheggio.aggiungiAutomobile(auto);
    }
    
    /**
     * Gestisce il transito di un'automobile da un parcheggio all'altro nel sistema di Car Sharing.
     * @param targa la targa dell'automobile da spostare
     * @param nomeNuovoParcheggio il nome del nuovo parcheggio in cui spostare l'automobile
     */
    public void transito(String targa, String nomeNuovoParcheggio) {
        Parcheggio nuovoParcheggio = trovaParcheggio(nomeNuovoParcheggio);
        if (nuovoParcheggio == null) {
            throw new IllegalArgumentException("Il parcheggio " + nomeNuovoParcheggio + " non esiste");
        }

        Automobile auto = trovaAutomobile(targa);
        if (auto == null) {
            throw new IllegalArgumentException("l'auto di targa " + targa + " non esiste");
        }

        Parcheggio vecchioParcheggio = auto.getLocazione();
        vecchioParcheggio.rimuoviAutomobili(targa);
        nuovoParcheggio.aggiungiAutomobile(auto);
        auto.incrementaViaggi();
    }
    
    /**
     * Conta il numero di automobili presenti nel parcheggio specificato nel sistema di Car Sharing.
     * @param nomeParcheggio il nome del parcheggio di cui contare le automobili
     * @return il numero di automobili presenti nel parcheggio specificato
     */
    public int contaAutomobili(String nomeParcheggio) {
        Parcheggio parcheggio = trovaParcheggio(nomeParcheggio);
        if (parcheggio == null) {
            throw new IllegalArgumentException("Il parcheggio " + nomeParcheggio + " non esiste");
        }

        return parcheggio.contaAutomobili();
    }
    
    /**
     * Rimuove le automobili da tutti i parcheggi nel sistema di Car Sharing
     * che hanno effettuato un numero di viaggi almeno pari a quello specificato.
     * @param viaggiMinimi il numero minimo di viaggi per mantenere un'automobile
     */
    public void rimuoviAutomobili(int viaggiMinimi) {
        for (Parcheggio parcheggio : parcheggi) {
            parcheggio.rimuoviAutomobili(viaggiMinimi);
        }
    }
    
    // scrivo su file
    // Cosa Salviamo? --> nomeParcheggio/locazione,targa,viaggi
    public void SalvaSuFile(String nomeFile) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeFile))){
            for (Parcheggio parcheggio : parcheggi) {
                for (Automobile auto : parcheggio.getAutomobili()) { // per ogni parcheggio ottengo la lista delle auto
                    writer.write(auto.toString()+"\n");
                }
            }
        } catch (IOException e) {
            throw new IllegalArgumentException("errore nella creazione del file di nome " + nomeFile);
        }
    }

    // lettura da file
    // Cosa Leggiamo? --> nomeParcheggio/locazione,targa,viaggi
    public void CaricaDaFile(String nomeFile) {
        try (BufferedReader writer = new BufferedReader(new FileReader(nomeFile))){
            parcheggi.clear();
            String line;
            while ((line = writer.readLine()) != null) {
                String[] parts = line.split(",");
                String nomeParcheggio = parts[0];
                String targa = parts[1];
                Integer viaggi = Integer.parseInt(parts[2]);
                
                aggiungiParcheggio(nomeParcheggio);
                aggiungiAutomobile(targa, nomeParcheggio);
                Parcheggio parcheggio = new Parcheggio(nomeParcheggio);
                Automobile auto = new Automobile(targa, parcheggio);
                auto.setViaggi(viaggi);
            }
        } catch (IOException e) {
            throw new IllegalArgumentException("impossibile aprire il file con nome " + nomeFile);
        }
    }
    
    /**
     * Trova e restituisce il parcheggio corrispondente al nome specificato.
     * @param nomeParcheggio il nome del parcheggio da cercare
     * @return il parcheggio corrispondente al nome specificato, null se non trovato
     */
    public Parcheggio trovaParcheggio(String nomeParcheggio) {
        for (Parcheggio parcheggio : parcheggi) {
            if (parcheggio.getNome().equals(nomeParcheggio)){
                return parcheggio;
            }
        }

        return null;
    }
    
    /**
     * Trova e restituisce l'automobile corrispondente alla targa specificata.
     * @param targa la targa dell'automobile da cercare
     * @return l'automobile corrispondente alla targa specificata, null se non trovata
     */
    public Automobile trovaAutomobile(String targa) {
        for (Parcheggio parcheggio : parcheggi) {
            for (Automobile auto : parcheggio.getAutomobili()) { // parcheggio.getAutomobili() -> ottengo la lista delle auto per ogni parcheggio
                if (auto.getTarga().equals(targa)) {
                    return auto;
                }
            }
        }
        return null;
    }
    public Automobile trovaAutomobile(String targa, Parcheggio parcheggio) {
        for (Automobile auto : parcheggio.getAutomobili()) {
            if (auto.getTarga().equals(targa)) {
                return auto;
            }
        }
        return null;
    }
}