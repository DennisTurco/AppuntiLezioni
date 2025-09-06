package Lista.ListaDocenti;
public class Docente extends Dipendente {
    private String disciplina;

    public Docente(String nome, String cognome) {
        super(nome, cognome);
    }
    public Docente(String nome, String cognome, String disciplina) {
        super(nome, cognome);
        this.disciplina = disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    public String getDisciplina() {
        return disciplina;
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
        return super.toString() + " - " + this.disciplina;
    }
}
