package Incapsulamento;
/*
    L'incapsulamento sta alla base dell'OOP.

    L'idea dell'incapsulamento è quella di avere tutto comne una black box, ovvero nascondere l'implementazione
    e la struttura interna, dfando però all'esterno tutti i servizi per operare. 
*/

public class Persona {
    // variabili private (incapsulate) 
    private String nome;
    private int eta;
    private int countModifiche;
    private static final String razza = "umano"; // razza umana
    private final String pianeta = "terra";

    // costruttore
    public Persona(String nome, int eta) {
        this.nome = nome;
        this.eta = eta;

        countModifiche = 0;
    }

    // siccome gli attributi sono privati devo fornire all'esterno dei metodi (pubblici) per poter operare su essi
    public int getEta() {
        return eta;
    }
    public String getNome() {
        return nome;
    }
    public int getCountModifiche() {
        return countModifiche;
    }
    public static String getRazza() {
        return razza;
    }
    public String getPianeta() {
        return pianeta;
    }
    public void setEta(int eta) {
        this.eta = eta;

        countModifiche++;
    }
    public void setNome(String nome) {
        if (nome == null || nome.length() == 0) {
            throw new IllegalArgumentException();
        }

        this.nome = nome;

        countModifiche++;
    }

}   
