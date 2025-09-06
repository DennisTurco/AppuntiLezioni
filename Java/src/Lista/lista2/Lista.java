package Lista.lista2;
package Lista.lista2.src;
public class Lista {
    private Node head;
    private int dim;

    public Lista() {
        // inizialmente la lista è vuota
        this.head = null;
        this.dim = 0;
    }

    // aggiungiamo un nuovo nodo in fondo alla lista
    public void aggiungiInCoda(int info) {
        Node newNode = new Node(info);

        // 2 casi: 1) la lista è vuota -> head == null; 2) la lista non è vuota -> scorrere la lista fino ad arrivare in fondo
        if (head == null) {
            head = newNode; // il nuovo nodo è la testa
        } else {
            Node temp = head;
            while (temp.getNext() != null) {
                temp = temp.getNext();
            }
            temp.setNext(newNode);
        }

        dim++;
    }

    // head -> nodo1 -> nodo2 -> null
    // newNode -> head -> nodo1 -> nodo2 -> null
    // head -> newNode -> nodo1 -> nodo2 -> null

    // aggiungiamo un nuovo nodo come primo elemento della lista
    public void aggiungiInTesta(int info) {
        Node newNode = new Node(info);

        newNode.setNext(head);  // aggiungiamo prima della testa
        head = newNode;         // il nuovo nodo è la testa

        dim++;
    }


    // head -> node1 -> node2 -> node3 -> null
    // head -> node1 -> node2 -> newNode -> node3 -> null
    public void aggiungiInPosizione(int info, int pos) {
        // controllo errori
        if (pos < 0 || pos > dim) {
            throw new IllegalArgumentException("Posizione non valida!");
        }

        if (pos == 0) {
            aggiungiInTesta(info);
        } else {
            Node temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp.getNext();
            }

            // inserire il nodo in posizione intermedia
            Node newNode = new Node(info);
            newNode.setNext(temp.getNext());
            temp.setNext(newNode);

            dim++;
        }
    }

    // head -> node1 -> node2 -> null
    public int eliminaInCoda() {
        // caso in cui la lista è vuota
        if (head == null) {
            throw new IllegalStateException("Impossibile eliminare elementi dalla lista vuota");
        }

        int infoRimosso;

        // 2 casi: 1) caso in cui nella lista c'è solo l'head. 2) caso in cui nella lista hai più elementi -> scorrere la lista
        if (head.getNext() == null) {
            infoRimosso = head.getInfo();
            head = null;
        } else { // scorrio la lista fino ad arrivare al penultimo nodo
            Node temp = head;
            while (temp.getNext().getNext() != null) {
                temp = temp.getNext();
            }
            infoRimosso = temp.getNext().getInfo();
            temp.setNext(null); // cancellando il collegamento dal penultimo verso l'ultimo -> cancelliamo l'ultimo
        }

        dim--;
        return infoRimosso;
    }

    // head -> node1 -> node2
    // head -> head -> node2
    // head -> node2
    public int eliminaInTesta() {
        // caso in cui la lista è vuota
        if (head == null) {
            throw new IllegalStateException("Impossibile eliminare elementi dalla lista vuota");
        }

        int infoRimosso = head.getInfo();
        head = head.getNext();
        dim--;
        return infoRimosso;
    }

    public int eliminaInPosizione() {
        return 0;
    }

    // per stampare la lista occorre scorrela dal primo nodo (head) all'ultimo
    @Override
    public String toString() {
        String riga = "[";

        Node temp = head;
        while (temp != null) {
            riga += temp.getInfo() + ", ";
            temp = temp.getNext();
        }

        return riga + "]";
    }

    public Node getHead() {
        return head;
    }
    public int getDim() {
        return dim;
    }
}
