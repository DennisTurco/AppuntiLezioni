package EsercizioStudenteBaseEreditarieta;

public class Insegnante extends Persona {
    private String materia;
    private boolean diRuolo;

    public Insegnante(String nome, String cognome, String materia, boolean diRuolo, int eta) {
        super(nome, cognome, eta);
        this.materia = materia;
        this.diRuolo = diRuolo;
    }

    public String getMateria() {
        return materia;
    }

    public boolean isDiRuolo() {
        return diRuolo;
    }

    public void setDiRuolo(boolean diRuolo) {
        this.diRuolo = diRuolo;
    }

    @Override
    public String toString() {
        return super.toString() + ", materia: " + materia + ", diRuolo: " + diRuolo;
    }
}
