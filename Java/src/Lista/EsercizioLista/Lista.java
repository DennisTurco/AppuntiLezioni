package Lista.EsercizioLista;
public class Lista {
    private int elementi;
    private Nodo head;

    public Lista() {
        this.elementi = 0; 
        this.head = null;
    }

    public void VisitaLista() {
        Nodo p = head;
        
        while (p != null) {
            System.out.print(p.getInfo()+ " ");
            p = p.getLink();
        }
    }

    public int getElementi() {
        return elementi;
    }

    public void AggiungiInCoda(int info) {
        Nodo n = new Nodo(info);

        if (head == null) {
            head = n;
        } else {
            Nodo p = head;

            while (p.getLink() != null) {
                p = p.getLink();
            }

            p.setLink(n);
        }

        elementi++;
    }
}
