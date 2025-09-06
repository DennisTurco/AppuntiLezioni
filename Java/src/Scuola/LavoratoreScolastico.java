package Scuola;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class LavoratoreScolastico implements Cloneable {
    // attributi della classe
    private String nome;
    private float ore_mensili;
    private float paga_oraria;

    // costruttore
    public LavoratoreScolastico(String nome, float ore_mensili, float paga_oraria) {
        if (nome == null || nome.length() == 0)
            throw new IllegalArgumentException("nome nullo non accettabile");
        if (ore_mensili < 0)
            throw new IllegalArgumentException("le ore non possono essere negative");
        if (paga_oraria < 0)
            throw new IllegalArgumentException("la paga non può essere negativa");

        this.nome = nome;
        this.ore_mensili = ore_mensili;
        this.paga_oraria = paga_oraria;
    }

    // metodi
    // creo un nuovo lavoratore che è una copia di quello attuale
    public LavoratoreScolastico clone() {
        LavoratoreScolastico nuovoLavoratore = new LavoratoreScolastico(nome, ore_mensili, ore_mensili);
        return nuovoLavoratore;
    }

    // prendo come argomento un oggetto dello stesso tipo della classe corrente e verifico che sia uguale a quello attuale
    public boolean equals(LavoratoreScolastico lavoratore) {
        if (nome.equals(lavoratore.getNome()) &&
                ore_mensili == lavoratore.getOre_mensili() &&
                paga_oraria == lavoratore.getPaga_oraria() &&
                lavoratore instanceof LavoratoreScolastico)
            return true;
        else
            return false;
    }

    @Override
    public String toString() {
        return nome + "," + ore_mensili + "," + paga_oraria;
    }

    // scrivi su file
    // metodo statico perchè richiamabile senza instaziare un oggetto di questa classe
    public static void SalvaLavoratori(LavoratoreScolastico[] lavoratori, String percorsoFile) {
        try (BufferedWriter reader = new BufferedWriter(new FileWriter(percorsoFile))) {
            for (int i = 0; i < lavoratori.length; i++) {
                reader.write(lavoratori[i].toString());
                reader.write("\n");
            }
        } catch (Exception e) { // cattura gli errori
            System.err.println(e.getMessage());
        }
    }

    // leggi da file
    // metodo statico perchè richiamabile senza instaziare un oggetto di questa classe
    public static LavoratoreScolastico[] CaricaLavoratori(String percorsoFile, int dimensione) {
        try (BufferedReader reader = new BufferedReader(new FileReader(percorsoFile))) {
            
            LavoratoreScolastico[] lavoratori = new LavoratoreScolastico[dimensione];
            int cont = 0;
            String line;
            
            // continuo a leggere finchè ci sono righe all'interno del file
            while((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                
                String nome = data[0];
                float ore_mensili = Float.parseFloat(data[1]);
                float paga_oraria = Float.parseFloat(data[2]);
                LavoratoreScolastico nuovoLavoratore = new LavoratoreScolastico(nome, ore_mensili, paga_oraria);
                lavoratori[cont] = nuovoLavoratore;

                // modo alternativo
                //lavoratori[cont] = new LavoratoreScolastico(data[0], Float.parseFloat(data[1]), Float.parseFloat(data[2]));

                cont++;
            }

            return lavoratori;

        } catch (Exception e) {
            System.err.println(e.getMessage()); // stampo l'errore
            return null; // se siamo qui dentro si è verificato un errore e quindi ritorniamo null
        }
    }

    // getter e setter
    public String getNome() {
        return nome;
    }
    public float getOre_mensili() {
        return ore_mensili;
    }
    public float getPaga_oraria() {
        return paga_oraria;
    }
    public void setOre_mensili(float ore_mensili) {
        if (ore_mensili < 0)
            throw new IllegalArgumentException("le ore non possono essere negative");

        this.ore_mensili = ore_mensili;
    }
    public void setPaga_oraria(float paga_oraria) {
        if (paga_oraria < 0)
            throw new IllegalArgumentException("la paga non può essere negativa");

        this.paga_oraria = paga_oraria;
    }
}
