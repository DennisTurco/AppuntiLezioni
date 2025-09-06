package Lista.ListaDocenti;
import java.util.ArrayList;

public class Dipendenti {
    private ArrayList<Dipendente> dipendenti;

    public Dipendenti() {
        dipendenti = new ArrayList<>(); 
    }

    public void AggiungiDipendente(Dipendente dipendente) {
        dipendenti.add(dipendente);
    }

    public boolean EliminaDipendente(String nome, String cognome) {
        for (int i = 0; i < dipendenti.size(); i++) {
            if (nome.equals(dipendenti.get(i).getNome()) && cognome.equals(dipendenti.get(i).getCognome())) {
                dipendenti.remove(i);
                return true;
            }
        }

        return false;
    }

    public Dipendente RicercaDipendente(String nome, String cognome) {
        for (int i = 0; i < dipendenti.size(); i++) {
            if (nome.equals(dipendenti.get(i).getNome()) && cognome.equals(dipendenti.get(i).getCognome())) {
                return dipendenti.get(i);
            }
        }

        return null;
    }     

    public int GetDocenti() {
        int res = 0;

        for (int i = 0; i < dipendenti.size(); i++) {
            if (dipendenti.get(i) instanceof Docente) {
                res++;
            }
        }

        return res;
    }

    public void StampaDipendenti() {
        for (int i = 0; i < dipendenti.size(); i++) {
            System.out.println(dipendenti.get(i).toString());
        }
    }
}
