package classi;

import java.time.LocalDate;

public class Studente {
    // attributi della classe. Per seguire la regola dell'incapsulamento, mettiamo tutti gli attributi private
    private String nome;
    private int anno;
    private String matricola;
    private String classe;

    // metodo costruttore -> permette di creare (istanziare) l'oggetto
    // di norma public. non ha valore di ritorno. Deve avere lo stesso nome della classe
    public Studente(String nome, int anno, String matricola, String classe) {
        this.nome = nome;
        this.anno = anno;
        this.matricola = matricola;
        this.classe = classe;
    }

    public int calcolo_eta() {
        return LocalDate.now().getYear() - anno;
    }

    public void stampa() {
        System.out.println("nome: " + nome + ", Anno: " + anno + ", Matricola: " + matricola + ", classe: " + classe);
    }

    // getter
    public String getNome() {
        return nome;
    }
    public int getAnno() {
        return anno;
    }
    public String getMatricola() {
        return matricola;
    }
    public String getClasse() {
        return classe;
    }

    // setter
    // per gli altri attributi non metto il setter perchè non ha senso logico poter modificare quei valori di uno studente 
    public void setClasse(String classe) {
        this.classe = classe;
    }
}
