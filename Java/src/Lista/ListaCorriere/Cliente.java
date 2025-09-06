package Lista.ListaCorriere;
public class Cliente {
    private String CF;
    private String denominazione;
    private String indirizzo;
    private String nazione;
    private String telefono;

    public Cliente(String CF, String denominazione, String nazione, String indirizzo, String telefono) {
        if (denominazione == null || denominazione.length() == 0)
            throw new IllegalArgumentException("Denominazione non valida");
        if (CF == null || CF.length() != 16)
            throw new IllegalArgumentException("Codice fiscale non valido");
        if (indirizzo == null || indirizzo.length() == 0)
            throw new IllegalArgumentException("Indirizzo non valido");
        if (nazione == null || nazione.length() == 0)
            throw new IllegalArgumentException("Nazione non valida");
        if (telefono == null || telefono.length() <= 5)
            throw new IllegalArgumentException("Telefono non valido");
        
            this.CF = CF;
        this.denominazione = denominazione;
        this.indirizzo = indirizzo;
        this.nazione = nazione;
        this.telefono = telefono;
    }

    public void setCF(String CF) {
        if (CF == null || CF.length() != 16)
            throw new IllegalArgumentException("Codice fiscale non valido");
        this.CF = CF;
    }
    public void setIndirizzo(String indirizzo) {
        if (indirizzo == null || indirizzo.length() == 0)
            throw new IllegalArgumentException("Indirizzo non valido");
        this.indirizzo = indirizzo;
    }
    public void setTelefono(String telefono) {
        if (telefono == null || telefono.length() <= 5)
            throw new IllegalArgumentException("Telefono non valido");
        this.telefono = telefono;
    }

    public String getCF() {
        return CF;
    }
    public String getDenominazione() {
        return denominazione;
    }
    public String getIndirizzo() {
        return indirizzo;
    }
    public String getNazione() {
        return nazione;
    }
    public String getTelefono() {
        return telefono;
    }

    @Override
    public String toString() {
        return CF + "," + denominazione + "," + nazione + "," + indirizzo + "," + telefono;
    }
}
