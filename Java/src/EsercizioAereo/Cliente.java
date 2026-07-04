package EsercizioAereo;

public class Cliente extends Clientsuper {

    private String nome;
    private String cognome;
    private String codiceFiscale;

    public Cliente(String nome, String cognome, String codiceFiscale, String tessera, int oreVolo) {
        super(tessera, oreVolo);
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
    }

    public Cliente(Cliente cliente) {
        super(cliente.getTessera(), cliente.getOreVolo());
        this.nome = cliente.getNome();
        this.cognome = cliente.getCognome();
        this.codiceFiscale = cliente.getCodiceFiscale();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }

    @Override
    public String toString() {
        return "Cliente [nome=" + nome + ", cognome=" + cognome + ", codiceFiscale=" + codiceFiscale + "]";
    }

}
