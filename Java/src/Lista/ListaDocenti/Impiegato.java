package Lista.ListaDocenti;
public class Impiegato extends Dipendente {
    private String ufficio;

    public Impiegato(String nome, String cognome) {
        super(nome, cognome);
    }
    public Impiegato(String nome, String cognome, String ufficio) {
        super(nome, cognome);
        this.ufficio = ufficio;
    }

    public void setUfficio(String ufficio) {
        this.ufficio = ufficio;
    }

    public String getUfficio() {
        return ufficio;
    }
    @Override
    public String getNome() {
        return super.getNome();
    }
    @Override
    public String getCognome() {
        return super.getCognome();
    }

    @Override
    public String toString() {
        return super.toString() + " - " + this.ufficio;
    }
}
