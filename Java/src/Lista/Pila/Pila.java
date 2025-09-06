package Lista.Pila;
// LIFO (Last-In-First-Out)
public class Pila {
    private Nodo cima;      // riferimento al nodo in cima alla pila
    private int dimensione; // numero di Nodi interni

    public Pila() {
        this.cima = null;
        this.dimensione = 0;
    }

    // restituisce true se la pila è vuota, false altrimenti
    public boolean isEmpty() {
        return cima == null;
    } 

    // aggiunge un nuovo nodo
    public void push(int info) {
        Nodo n = new Nodo(info);
        n.setLink(cima);    // collegamento del nuovo nodo al nodo precedente in cima alla pila
        cima = n;           // il nuovo nodo diventa il nodo in cima alla pila

        dimensione++;
    }

    // rimuove il Nodo in cima e ne ritorna il contenuto
    public int pop() {
        if (isEmpty()) 
            throw new IllegalStateException("Errore: la pila e' vuota.");
        
        int elemento = cima.getInfo();  // estrazione del contenuto del Nodo in cima
        cima = cima.getLink();          // rimozione del Nodo in cima

        dimensione--;
        
        return elemento;
    }

    // ritorna il contenuto del Nodo in cima 
    public int peek() {
        if (isEmpty())
            throw new IllegalStateException("Errore: la pila e' vuota.");

        return cima.getInfo();
    }

    public int size() {
        return dimensione;
    }
}
