package CorsoMinecraft.classi.esempioClasseConStatic;

import java.time.LocalDate;

/*
in questo caso la classe non ha nessun attributo,
dispone unicamente di metodi che fanno cose ma che non salvano nulla internamente
di conseguenza questi metodi possono essere statici
*/

public class TimeUtil {

    public static boolean precede(LocalDate data1, LocalDate data2) {
        if (data1.isBefore(data2)) {
            return true;
        } else {
            return false;
        }
    }

    public static void stampaData(LocalDate data) {
        System.out.println(data.getDayOfMonth() + "/" + data.getMonth() + "/" + data.getYear());
    }

    public static LocalDate sommaDate(LocalDate data, int giorniDaAggiungere) {
        return data.plusDays(giorniDaAggiungere);
    }
}
