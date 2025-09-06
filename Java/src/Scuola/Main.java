package Scuola;
public class Main {
    public static void main(String[] args) throws Exception {
        // test per scrittura su file
        Insegnate insegnate1 = new Insegnate("Tracker TheBest", 60, 20, "Non insegno nulla");
        Insegnate insegnate2 = new Insegnate("Carlo Guareschi", 70, (float)7.5, "Religione");
        Segretaria segretaria1 = new Segretaria("AnnaMaria Incoronata", 20, (float) 8.22, "Segretaria Semplice");
        Segretaria segretaria2 = new Segretaria("Antonietta Pinetta", 25, 7, "Segretaria Tirocinante");
        LavoratoreScolastico[] lavoratori1 = new LavoratoreScolastico[4];
        lavoratori1[0] = (LavoratoreScolastico) insegnate1; // upcasting
        lavoratori1[1] = (LavoratoreScolastico) insegnate2;
        lavoratori1[2] = (LavoratoreScolastico) segretaria1;
        lavoratori1[3] = (LavoratoreScolastico) segretaria2;
        LavoratoreScolastico.SalvaLavoratori(lavoratori1, "LavoratoriScolastici.txt");

        System.out.println("Letto dal toString --> " + insegnate1.toString());

        // test per lettura da file
        LavoratoreScolastico[] lavoratori2 = new LavoratoreScolastico[4];
        lavoratori2 = LavoratoreScolastico.CaricaLavoratori("LavoratoriScolastici.txt", 4);
        stampaArray(lavoratori2);
    }

    private static void stampaArray(LavoratoreScolastico[] lavoratori) {
        for (int i=0; i < lavoratori.length; i++) {
            System.out.println(lavoratori[i].toString());
        }
    }
}
