package EsercizioAereo;

import java.util.LinkedList;

public class Volo {

    private int posti;
    private int attesa;
    private LinkedList<Cliente> listaAttesa;
    private LinkedList<Cliente> listaPrenotazione;

    public int getPosti() {
        return posti;
    }

    public void setPosti(int posti) {
        this.posti = posti;
    }

    public int getAttesa() {
        return attesa;
    }

    public void setAttesa(int attesa) {
        this.attesa = attesa;
    }
    //costruttore

    public Volo(int posti, int attesa) {
        this.posti = posti;
        this.attesa = attesa;
    }

    public void inserisciAttesa(Cliente c) {
        listaAttesa.add(c);
    }

    public int inserisciprenotazione(Cliente c) {
        if (posti <= listaPrenotazione.size()) {
            inserisciAttesa(c);
            return 0;//lista prenotazione piena mandato in attesa
        } else {
            listaPrenotazione.add(c);
        }
        return 1; //cliente accettato
    }

    public void disdetta(String codiceFiscale) {
        for (int i = 0; i < listaPrenotazione.size(); i++) {
            if (listaPrenotazione.get(i).getCodiceFiscale().equals(codiceFiscale)) {
                listaPrenotazione.remove(i);
                System.out.println("prenotazione elliminata");
            }
            if (!listaAttesa.isEmpty()) {
                Cliente c = listaAttesa.removeFirst();
                listaPrenotazione.add(c);
                System.out.println("cliente spostato da attesa a prenotazione");
            }
            return;
        }

    }

    public void visualizzaPrenotati() {
        System.out.println("clienti prenotati");
        for (int i = 0; i < listaPrenotazione.size(); i++) {
            System.out.println(listaPrenotazione.get(i));
        }
    }

    public void visualizzaAttesa() {
        System.out.println("Clienti in atesa");
        for (int i = 0; i < listaAttesa.size(); i++) {
            System.out.println(listaAttesa.get(i));
        }
    }

    public void cercaOreVolo(String codiceFiscale) {
        for (int i = 0; i < listaPrenotazione.size(); i++) {
            if (listaPrenotazione.get(i).getCodiceFiscale().equals(codiceFiscale)) {
                System.out.println("ore di volo: " + listaPrenotazione.get(i).getOreVolo());
                return;
            }
        }
        for (int i = 0; i < listaAttesa.size(); i++) {
            System.out.println("ore di volo: " + listaAttesa.get(i).equals(codiceFiscale));
            return;
        }
        System.out.println("cliente non trovato");
    }

    public int contaClienti(int ore) {
        int contatore = 0;
        for (int i = 0; i < listaPrenotazione.size(); i++) {
            if (listaPrenotazione.get(i).getOreVolo() > ore) {
                contatore++;
            }
        }
        for (int i = 0; i < listaAttesa.size(); i++) {
            if (listaAttesa.get(i).getOreVolo() > ore) {
                contatore++;
            }
        }
        return contatore;
    }
}
