package CorsoMinecraft.classi.esempioClasseConStatic;

import java.time.LocalDate;

/*
static si usa quando non voglio creare un istanza di una classe, in parole semplici
quando voglio utilizzare dei metodi della classe ma non voglio salvare attributi al suo interno
*/

public class Main {

    public static void main(String[] args) {
        LocalDate data1 = LocalDate.now();
        LocalDate data2 = LocalDate.now().plusDays(45);

        System.out.println(TimeUtil.precede(data1, data2));
        TimeUtil.stampaData(data2);
    }
}
