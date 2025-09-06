package Lista.ListaCorriere;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Corriere {
    private List<Cliente> clienti;
    private List<Spedizione> spedizioni;

    public Corriere() {
        clienti = new ArrayList<>();
        spedizioni = new ArrayList<>();
    }

    public void aggiungiCliente(Cliente cliente) {
        // verifico se esiste gia' un cliente con il codice fiscale passato (se si lancio l'eccezione)
        if (getClienteByCF(cliente.getCF()) != null)
            throw new IllegalArgumentException("Codice fiscale gia' inserito, non sono ammessi duplicati");

        clienti.add(cliente);
    }    
    
    // rimuovo un cliente dalla lista passando un oggetto Cliente
    public void rimuoviCliente(Cliente cliente) {
        clienti.remove(cliente);
    }
    // rimuovo un cliente dalla lista passando il codice fiscale
    public void rimuoviCliente(String cf) {
        for (Cliente cliente : clienti) {
            // entro nell'if quando ho ottenuto il cliente ricercato
            if (cliente.getCF().equals(cf)) {
                rimuoviCliente(cliente);
                return;
            }
        }

        // se sono arrivato a questo punto significa che non ho ttrovato l'utente e quindi mi e' stato passato un CF sbagliato
        throw new IllegalArgumentException("Codice fiscale non valido");
    }

    public void aggiungiSpedizione(Spedizione spedizione) {
        // verifico se esiste gia' una spedizione con il codice passato (se si lancio l'eccezione)
        if (getSpedizioneByCode(spedizione.getCodice()) != null)
            throw new IllegalArgumentException("Codice spedizione gia' inserito, non sono ammessi duplicati");


        spedizioni.add(spedizione);
    }
    public void aggiungiSpedizione(String codice, String CF_mittente, String CF_destinatario) {
        Cliente mittente = getClienteByCF(CF_mittente);
        Cliente destinatario = getClienteByCF(CF_destinatario);

        if (mittente == null || destinatario == null)
            throw new IllegalArgumentException("Codici fiscali non validi");

        aggiungiSpedizione(new Spedizione(codice, mittente, destinatario));
    }

    // rimuovo una spedizione dalla lista passando un oggetto spedizione
    public void rimuoviSpedizione(Spedizione spedizione) {
        spedizioni.remove(spedizione);
    }
    // rimuovo una spedizione dalla lista passando il codice associato
    public void rimuoviSpedizione(String codice) {
        for (Spedizione spedizione : spedizioni) {
            // entro nell'if quando ho ottenuto la spedizione ricercata
            if (spedizione.getCodice().equals(codice)) {
                rimuoviSpedizione(spedizione);
                return;
            }
        } 
        
        // se sono arrivato a questo punto significa che non ho trovato la spedizione e quindi mi e' stato passato un codice sbagliato
        throw new IllegalArgumentException("Codice spedizione non valido");
    }

    public void salvaClientiSuFile(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Cliente cliente : clienti) {
                writer.write(cliente.toString() + "\n");
            }
        } catch (IOException e) {
            System.out.println("Errore durante la scrittura del file: " + e.getMessage());
        }
    }

    public void caricaClienteDaFile(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            clienti.clear();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                Cliente cliente = new Cliente(parts[0], parts[1], parts[2], parts[3], parts[4]);
                aggiungiCliente(cliente);
            } 
        } catch (IOException e) {
            System.out.println("Errore durante la lettura del file: " + e.getMessage());
        }
    }

    public void salvaSpedizioniSuFile(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Spedizione spedizione : spedizioni) {
                writer.write(spedizione.toString() + "\n");
            }
        } catch (IOException e) {
            System.out.println("Errore durante la scrittura del file: " + e.getMessage());
        }
    }

    public void caricaSpedizioniDaFile(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            spedizioni.clear();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                Cliente mittente = getClienteByCF(parts[1]);
                Cliente destinatario = getClienteByCF(parts[2]);
                Spedizione spedizione = new Spedizione(parts[0], mittente, destinatario);
                aggiungiSpedizione(spedizione);
            } 
        } catch (IOException e) {
            System.out.println("Errore durante la lettura del file: " + e.getMessage());
        }
    }

    // ritorna un oggetto di tipo Cliente passando come argomento il suo codice fiscale
    // ritorna null se non viene trovato
    public Cliente getClienteByCF(String CF) {
        for (Cliente cliente : clienti) {
            if (cliente.getCF().equals(CF)) {
                return cliente;
            }
        }
        return null;
    }

    // ritorna un oggetto di tipo Spedizione passando come argomento il suo codice spedizione
    // ritorna null se non viene trovato
    public Spedizione getSpedizioneByCode(String codice) {
        for (Spedizione spedizione : spedizioni) {
            if (spedizione.getCodice().equals(codice)) {
                return spedizione;
            }
        }
        return null;
    }

    public void stampaClienti() {
        for (Cliente cliente : clienti) {
            System.out.println(cliente.toString());
        }
    }

    public void stampaSpedizioni() {
        for (Spedizione spedizione : spedizioni) {
            System.out.println(spedizione.toString());
        }
    }
}