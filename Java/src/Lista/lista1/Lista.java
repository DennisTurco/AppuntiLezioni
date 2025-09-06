package Lista.lista1;
public class Lista {
    private Nodo head;      // punta al primo elemento della lista (null se vuota)
    private int dimensione; // numero di elementi nella lista

    public Lista() {
        this.head = null;
        this.dimensione = 0;
    }

    // restituisce la dimensione della lista
    public int getDimensione() {
        return dimensione;
    }

    // stampa
    public void VisitaLista() {
        Nodo p = head;

        // itero fino a trovare l'ultimo elemento della lista 
        while (p != null) {
            System.out.print(p.getInfo() + " ");
            p = p.getLink();
        }
    }

    public void InserisciInTesta(int info) {
        Nodo n = new Nodo(info);    // nuovo nodo
        n.setLink(head);            // Il link del nuovo nodo punta al nodo corrente (head)
        head = n;                   // Il nuovo nodo diventa la nuova testa della lista
        dimensione++;
    }    

    public void InserisciInCoda(int info) {
        Nodo n = new Nodo(info);    // nuovo nodo

        if (head == null) {  // caso in cui la lista e' vuota
            head = n;
        } else {
            Nodo p = head;  // Nodo al primo elemento della lista

            while (p.getLink() != null) {
                p = p.getLink();
            }

            n.setLink(null);
            p.setLink(n);
        }

        dimensione++;
    }

    public void InserisciInMezzo(int info, int posizione) {
        if (posizione < 0 || posizione > dimensione) 
            throw new IllegalArgumentException("Errore: Posizione non valida");
        
        Nodo n = new Nodo(info); // nuovo nodo
        if (posizione == 0) {
            // inserimento in testa
            n.setLink(head);
            head = n;
        } else {
            Nodo p = head;
            for (int i = 0; i < posizione-1; i++) {
                p = p.getLink();
            }
            n.setLink(p.getLink());
            p.setLink(n);
        }

        dimensione++;
    }

    public void EliminaInTesta() {
        // se la lista e' vuota non posso eliminare nulla
        if (head == null) 
            return;

        head = head.getLink();
        dimensione--;
    }

    public void EliminaInCoda() {
        if (head == null)
            return;
        
        if (head.getLink() == null) {  // caso in cui la lista contiene un solo elemento
            head = null;
        } else {
            Nodo p = head;  // nodo di testa

            // p.getList() -> nodo i; p.getLink().getLink() -> nodo i+1
            while (p.getLink().getLink() != null) {
                p = p.getLink();
            }

            p.setLink(null);
        }

        dimensione--;
    }

    public void EliminaInMezzo(int posizione) {
        if (posizione < 0 || posizione > dimensione)
            throw new IllegalArgumentException("Errore: Posizione non valida");
        if (head == null)
            throw new IllegalStateException("Errore: Lista gia' vuota");
        
        if (posizione == 0) {
            // elimina in testa
            head = head.getLink();
        } else {
            Nodo p = head;
            for (int i = 0; i < posizione - 1; i++) {
                p = p.getLink();
            }
            p.setLink(p.getLink().getLink());
        }

        dimensione--;
    }
}