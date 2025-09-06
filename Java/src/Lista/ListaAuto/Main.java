package Lista.ListaAuto;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        CarSharing carSharing = new CarSharing();
        Scanner scanner = new Scanner(System.in);

        while (true) {

            // Stampa la cornice
            System.out.println("|==========================================|");
            System.out.println("|    Benvenuto nel sistema di Car Sharing! |");
            System.out.println("|==========================================|");
            System.out.println("| Seleziona un'opzione:                    |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 1. Aggiungi un parcheggio                |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 2. Aggiungi un'automobile                |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 3. Sposta un'automobile                  |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 4. Conta le automobili in un parcheggio  |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 5. Rimuovi automobili con un numero      |");
            System.out.println("|    minimo di viaggi                      |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 6. Salva su file                         |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 7. Carica da file                        |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 8. Esci                                  |");
            System.out.println("|==========================================|");

            System.out.print("Scelta: ");
            int scelta = scanner.nextInt();
            scanner.nextLine(); // Consuma il newline dopo il nextInt()

            switch (scelta) {
                case 1:
                    System.out.print("Nome del parcheggio da aggiungere: ");
                    String nomeParcheggio = scanner.nextLine();
                    try {
                        carSharing.aggiungiParcheggio(nomeParcheggio);
                        System.out.println("Parcheggio aggiunto con successo: " + nomeParcheggio);
                    } catch (Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 2:
                    System.out.print("Targa dell'automobile da aggiungere: ");
                    String targaAutomobile = scanner.nextLine();
                    System.out.print("Nome del parcheggio in cui aggiungere l'automobile: ");
                    String nomeParcheggioAutomobile = scanner.nextLine();
                    try {
                        carSharing.aggiungiAutomobile(targaAutomobile, nomeParcheggioAutomobile);
                        System.out.println("Automobile aggiunta con successo: " + targaAutomobile);
                    } catch(Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 3:
                    System.out.print("Targa dell'automobile da spostare: ");
                    String targaSpostamento = scanner.nextLine();
                    System.out.print("Nome del nuovo parcheggio: ");
                    String nomeNuovoParcheggio = scanner.nextLine();
                    try {
                        carSharing.transito(targaSpostamento, nomeNuovoParcheggio);
                        System.out.println("Automobile transitata al parcheggio: " + nomeNuovoParcheggio);
                    } catch(Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    
                    break;
                case 4:
                    System.out.print("Nome del parcheggio di cui contare le automobili: ");
                    String nomeParcheggioConteggio = scanner.nextLine();
                    try {
                        int numeroAutomobili = carSharing.contaAutomobili(nomeParcheggioConteggio);
                        System.out.println("Il numero di automobili nel parcheggio " + nomeParcheggioConteggio + " e': " + numeroAutomobili);
                    } catch(Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 5:
                    System.out.print("Numero minimo di viaggi per rimuovere le automobili: ");
                    int viaggiMinimi = scanner.nextInt();
                   
                    try {
                        carSharing.rimuoviAutomobili(viaggiMinimi);
                        System.out.println("Automobile rimossa con successo");
                    } catch(Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    
                    break;
                case 6:
                    System.out.print("Nome del file: ");
                    String nomeFileSalva = scanner.nextLine();
                    try {
                        carSharing.SalvaSuFile(nomeFileSalva);
                    } catch (Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 7:
                    System.out.print("Nome del file: ");
                    String nomeFileCarica = scanner.nextLine();
                    try {
                        carSharing.CaricaDaFile(nomeFileCarica);
                    } catch (Exception ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 8:
                    break;
                default:
                    System.out.println("Scelta non valida. Riprova.");
                    break;
            }

            if (scelta==8) break;
        }

        scanner.close();
        System.out.println("|---------Grazie per aver utilizzato il sistema di Car Sharing!-------|");
    }
}