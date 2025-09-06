package Lista.lista1;
public class Main {
    public static void main(String[] args) {
        // Creazione di una nuova lista
        Lista lista = new Lista();

        // Inserimento di alcuni elementi
        lista.InserisciInCoda(10);
        lista.InserisciInCoda(20);
        lista.InserisciInCoda(30);

        // Stampa della lista
        System.out.println("Lista dopo l'inserimento:");
        lista.VisitaLista();

        // Eliminazione in testa
        lista.EliminaInTesta();
        System.out.println("\nLista dopo l'eliminazione in testa:");
        lista.VisitaLista();

        // Eliminazione in coda
        lista.EliminaInCoda();
        System.out.println("\nLista dopo l'eliminazione in coda:");
        lista.VisitaLista();

        // Inserimento in testa
        lista.InserisciInTesta(40);
        System.out.println("Lista dopo l'inserimento in testa:");
        lista.VisitaLista();

        // Inserimento in mezzo
        lista.InserisciInMezzo(25, 1);
        System.out.println("Lista dopo l'inserimento in mezzo:");
        lista.VisitaLista();

        // Eliminazione in mezzo
        lista.EliminaInMezzo(1);
        System.out.println("Lista dopo l'eliminazione in mezzo:");
        lista.VisitaLista();
    }
}
