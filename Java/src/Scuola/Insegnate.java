package Scuola;
public class Insegnate extends LavoratoreScolastico implements Lavoratore {
    private String materia;

    // costruttore
    public Insegnate(String nome, float ore_mensili, float paga_oraria, String materia) {
        super(nome, ore_mensili, paga_oraria);
        this.materia = materia;
    }

    public Insegnate clone() {
        Insegnate nuovoInsegnate = new Insegnate(getNome(), getOre_mensili(), getPaga_oraria(), materia);
        return nuovoInsegnate;
    }

    public boolean equals(Insegnate insegnate) {
        if (getNome().equals(insegnate.getNome()) &&
            getOre_mensili() == insegnate.getOre_mensili() &&
            getPaga_oraria() == insegnate.getPaga_oraria() &&
            materia.equals(insegnate.getMateria()) &&
            insegnate instanceof Insegnate) {
                return true;   
        }
        else {
            return false;
        }
    }

    @Override
    public String toString() {
        return super.toString() + "," + materia;
    }

    @Override
    public float CalcolaStipendio() {
        return getOre_mensili() * getPaga_oraria() * (float) 1.2; // moltiplico per 1.2 perchè un isegnate è bello e merita di più
    }

    // getter e setter
    public String getMateria() {
        return materia;
    }
    public void setMateria(String materia) {
        this.materia = materia;
    }
    
}

