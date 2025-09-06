package Lista.Coda;
// FIFO (First-In-First-Out)
public class Coda {
    private Nodo front;     // riferimento all'inizio della coda
    private Nodo end;       // riferimento alla fine della coda
    private int dimensione; // numero di Nodi interni

    public Coda() {
        this.front = null;
        this.end = null;
        this.dimensione = 0;
    }

    // restituisce true se la coda è vuota, false altrimenti
    public boolean isEmpty() {
        return front == null;
    } 

    // aggiunge un nuovo nodo in fondo alla coda
    public void enqueue(int info) {
        Nodo n = new Nodo(info);

        if (isEmpty()) {
            front = n;
        } else {
            end.setLink(n);
        }
        end = n;
        
        dimensione++;
    }

    // rimuove il Nodo all'inizio della coda e ne ritorna il contenuto
    public int dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Errore: la coda e' vuota.");
        }

        int elemento = front.getInfo(); // Salva l'elemento all'inizio della coda
        front = front.getLink();        // Rimuove il nodo all'inizio della coda
        
        if (front == null) {
            end = null;     // Se la coda diventa vuota, anche il riferimento alla fine viene aggiornato
        }
        
        dimensione--;

        return elemento;
    }

    // ritorna il contenuto del Nodo all'inizio 
    public int peek() {
        if (isEmpty())
            throw new IllegalStateException("Errore: la coda e' vuota.");

        return front.getInfo();
    }

    public int size() {
        return dimensione;
    }
}
