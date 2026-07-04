package EsercizioAereo;

public class Main {

    public static void main(String[] args) {
        Cliente c1 = new Cliente("Mario", "Rossi", "MRARSS", "T1", 20);
        Cliente c2 = new Cliente("Luca", "Bianchi", "LCBNCH", "T2", 15);
        Cliente c3 = new Cliente("Anna", "Verdi", "ANNVRD", "T3", 40);
        Cliente c4 = new Cliente("Sara", "Neri", "SRANER", "T4", 10);
        Volo v = new Volo(2, 10);

        System.out.println(v.inserisciprenotazione(c1));
        System.out.println(v.inserisciprenotazione(c2));
        System.out.println(v.inserisciprenotazione(c3));
        System.out.println(v.inserisciprenotazione(c4));
        v.visualizzaPrenotati();
        v.visualizzaAttesa();
        v.cercaOreVolo("ANNVRD");
        System.out.println("Clienti con più di 18 ore: " + v.contaClienti(18));
        v.disdetta("MRARSS");
        v.visualizzaPrenotati();
        v.visualizzaAttesa();
    }
}
