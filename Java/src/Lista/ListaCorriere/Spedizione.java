package Lista.ListaCorriere;
public class Spedizione {
    private String codice;
    private Cliente destinatario;
    private Cliente mittente;

    public Spedizione(String codice, Cliente mittente, Cliente destinatario) {
        if (codice == null || codice.length() == 0)
            throw new IllegalArgumentException("Codice non valido");
        if (mittente == null)
            throw new IllegalArgumentException("Mittente mancante");
        if (destinatario == null)
            throw new IllegalArgumentException("Destinatario mancante");

        this.destinatario = destinatario;
        this.mittente = mittente;
        this.codice = codice;
    }

    public String getCodice() {
        return codice;
    }
    public Cliente getDestinatario() {
        return destinatario;
    }
    public Cliente getMittente() {
        return mittente;
    }

    @Override
    public String toString() {
        return codice + "," + mittente.getCF() + "," + destinatario.getCF();
    }
}
