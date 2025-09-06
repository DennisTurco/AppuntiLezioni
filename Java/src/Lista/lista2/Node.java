package Lista.lista2;
package Lista.lista2.src;

public class Node {
    private int info;  // dato che contiene il nodo (in questo caso è intero)
    private Node next; // collegamento al nodo successivo

    public Node(int info) {
        this.info = info;
        this.next = null;
    }

    // gettere e setter
    public int getInfo() {
        return info;
    }
    public Node getNext() {
        return next;
    }
    public void setInfo(int info) {
        this.info = info;
    }
    public void setNext(Node next) {
        this.next = next;
    }
}
