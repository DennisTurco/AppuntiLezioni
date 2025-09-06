package Scuola;
public class Segretaria extends LavoratoreScolastico implements Lavoratore {
    private String tipo;

    // costruttore
    public Segretaria(String nome, float ore_mensili, float paga_oraria, String tipo) {
        super(nome, ore_mensili, paga_oraria);
        this.tipo = tipo;
    }

    public Segretaria clone() {
        Segretaria nuovaSegretaria = new Segretaria(getNome(), getOre_mensili(), getPaga_oraria(), tipo);
        return nuovaSegretaria;
    }

    public boolean equals(Segretaria segretaria) {
        if (getNome().equals(segretaria.getNome()) &&
            getOre_mensili() == segretaria.getOre_mensili() &&
            getPaga_oraria() == segretaria.getPaga_oraria() &&
            tipo.equals(segretaria.getTipo()) &&
            segretaria instanceof Segretaria) {
                return true;   
        }
        else {
            return false;
        }
    }

    @Override
    public String toString() {
        return super.toString() + "," + tipo;
    }

    @Override
    public float CalcolaStipendio() {
        return getOre_mensili() * getPaga_oraria();
    }

    // setter e getter
    public String getTipo() {
        return tipo;
    }
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
    
}