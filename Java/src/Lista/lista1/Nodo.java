package Lista.lista1;
public class Nodo {
    private int info;   // valore del nodo corrente
    private Nodo link;  // puntatore al nodo successivo

    public Nodo(int info) {
        this.info = info;
        this.link = null;   // non ha ancora un nodo successivo
    }

    public int getInfo() {
        return info;
    }
    public Nodo getLink() {
        return link;
    }

    public void setLink(Nodo link) {
        this.link = link;   // setto il nodo successivo
    }
    public void setInfo(int info) {
        this.info = info;
    }
}