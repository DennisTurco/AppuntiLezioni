package DowncastUpcasting;
public class Program {
    public static void main(String[] args) throws Exception {
        Persona persona = new Persona("Carlo", "Magno", "SDGSHJGFDui23yDSDGH");
        Studente studente = new Studente("Maria", "Billi", "ashjdashjvd123123", "237651273");

        System.out.println("\n--- UPCASTING ---");
        // upcasting implicito (Studente -> Persona)
        Persona persona1 = new Studente("Gigi", "Sali", "DSKNGHSJDJH2323DSH", "23723");
        System.out.println("Upcasting: Studente -> Persona (persona1)");
        System.out.println(persona1.toString());

        System.out.println("\n--- CHIAMATA METODI CON UPCASTING ---");
        PersonaGenericaCheSaluta(persona); // NO upcasting
        PersonaGenericaCheSaluta(studente); // upcasting implicito

        System.out.println("\n----------------------------------------------");

        System.out.println("\n--- DOWNCASTING CORRETTO ---");
        // downcasting (Persona -> Studente) con oggetto effettivamente Studente
        Studente studente1 = (Studente) persona1;
        System.out.println("Downcasting: Persona -> Studente (studente1)");
        System.out.println(studente1.toString());
        StudenteCheSaluta(studente1);

        System.out.println("\n--- USO DEL METODO StampaInfoStudente CON instanceof ---");
        StampaInfoStudente(studente); // oggetto Studente -> va bene
        StampaInfoStudente(persona); // oggetto Persona -> no cast
        StampaInfoStudente(persona1); // oggetto Studente castato a Persona -> va bene

        System.out.println("\n--- DOWNCASTING NON SICURO (CON CONTROLLO instanceof) ---");
        if (persona instanceof Studente) {
            Studente studente2 = (Studente) persona;
            System.out.println("Downcasting riuscito: Persona -> Studente (studente2)");
            System.out.println(studente2.toString());
            StudenteCheSaluta(studente2);
        } else {
            System.out.println("Downcasting FALLITO: persona NON è un'istanza di Studente");
        }
    }

    private static void StudenteCheSaluta(Studente studente) {
        System.out.println("Studente che saluta:");
        studente.saluta();
    }

    private static void PersonaGenericaCheSaluta(Persona persona) {
        System.out.println("Persona che saluta:");
        persona.saluta();
    }

    private static void StampaInfoStudente(Persona persona) {
        if (persona instanceof Studente) {
            System.out.println("L'oggetto è un Studente:");
            System.out.println(persona.toString());
        } else {
            System.out.println("L'oggetto passato NON è un'istanza di Studente");
        }
    }
}