package EquazioneSoluzioni;
import java.util.Scanner;

public class App {

    public static void calcoloRisultatiEquazioneSecondoGrado(double a, double b, double c) {
        // calcoliamo il delta
        double delta = b*b - 4*a*c;

        // caso delta negativo -> equazione impossibile
        if (delta < 0) {
            throw new IllegalStateException("Eccezione, Delta negativo con valore " + delta);
        }

        // calcolo risultati
        double x1, x2;
        if (delta == 0) {
            x1 = (-1 * b) / (2 * a);
            System.out.println("x = " + x1);
        } else if (delta > 0) {
            x1 = (-1 * b) + Math.sqrt(delta) / (2 * a);
            x2 = (-1 * b) - Math.sqrt(delta) / (2 * a);
            System.out.println("x1 = " + x1);
            System.out.println("x2 = " + x2);
        }
    }

    public static void main(String[] args){
        double a, b, c;
        System.out.print("passami i valori di a, b, c di un equazione di secondo grado: ");
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextDouble();
        b = scanner.nextDouble();
        c = scanner.nextDouble();
        scanner.close();
        
        try {
            calcoloRisultatiEquazioneSecondoGrado(a, b, c);
        } catch (IllegalStateException ex) {
            System.out.println("Si è verificata un eccezione: " + ex.getMessage());
            ex.printStackTrace(); // stampa la catena di chiamate che sono state fatte e che hanno provocato l'eccezione
        }
    }
}
