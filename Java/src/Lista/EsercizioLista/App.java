package Lista.EsercizioLista;
import java.io.BufferedReader;
import java.io.FileReader;

public class App {
    public static void main(String[] args) throws Exception {
        // creazione liste
        Lista valoriPositivi = new Lista(); // 36, 3, 21, 7, 28, 7, 9, 23
        Lista valoriNegativi = new Lista(); // -43, -55, -2, -45, -34, -65

        // lettura da file e salvataggio valori nelle liste
        try (BufferedReader reader = new BufferedReader(new FileReader("Valori.txt"))) {
            String line;
            while((line = reader.readLine()) != null) {
                int valore = Integer.parseInt(line);
                if (valore > 0) {
                    valoriPositivi.AggiungiInCoda(valore);
                } else if (valore < 0) {
                    valoriNegativi.AggiungiInCoda(valore);
                }
            }
        } catch (Exception ex) {
            System.err.println(ex.getMessage());
        }
        
        // stampa dimensioni liste
        System.out.println("Dimensione lista valori positivi: " + valoriPositivi.getElementi());
        System.out.println("Dimensione lista valori positivi: " + valoriNegativi.getElementi());

        // stampa delle liste
        System.out.print("I valori positivi sono: ");
        valoriPositivi.VisitaLista();
        System.out.print("\nI valori negativi sono: ");
        valoriNegativi.VisitaLista();
    }
}