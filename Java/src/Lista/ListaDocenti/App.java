package Lista.ListaDocenti;
public class App {
    public static void main(String[] args) {
        Docente d1 = new Docente("Antonello", "Rossi", "matematica");
        Docente d2 = new Docente("Marcello", "Vasotti", "italiano");
        Impiegato i1 = new Impiegato("Angelo", "Paratelli", "via parigini 12");
        Impiegato i2 = new Impiegato("Marco", "Sambretti", "via montecchi 4");

        Dipendenti dipendenti = new Dipendenti();

        dipendenti.AggiungiDipendente(d1);
        dipendenti.AggiungiDipendente(d2);
        dipendenti.AggiungiDipendente(i1);
        dipendenti.AggiungiDipendente(i2);

        dipendenti.StampaDipendenti();

        System.out.println("Numero di docenti: " + dipendenti.GetDocenti());
    }
}
