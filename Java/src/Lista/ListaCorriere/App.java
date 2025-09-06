package Lista.ListaCorriere;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Corriere corriere = new Corriere();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            // Stampa la cornice
            System.out.println("|==========================================|");
            System.out.println("|    Benvenuto nel sistema di logistica!   |");
            System.out.println("|==========================================|");
            System.out.println("| Seleziona un'opzione:                    |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 1. Aggiungi un cliente                   |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 2. Aggiungi una spedizione               |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 3. Mostra clienti                        |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 4. Mostra spedizioni                     |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 5. Rimuovi cliente                       |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 6. Rimuovi spedizione                    |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 7. Salva su file                         |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 8. Carica da file                        |");
            System.out.println("|------------------------------------------|");
            System.out.println("| 9. Esci                                  |");
            System.out.println("|==========================================|");

            System.out.print("Scelta: ");
            int scelta = scanner.nextInt();
            scanner.nextLine(); // Consuma il newline dopo il nextInt()

            switch (scelta) {
                case 1:
                    try {
                        System.out.print("Codice Fiscale = ");
                        String cf = scanner.nextLine();
                        System.out.print("Denominazione = ");
                        String denominazione = scanner.nextLine();
                        System.out.print("Nazione = ");
                        String nazione = scanner.nextLine();
                        System.out.print("Indirizzo = ");
                        String indirizzo = scanner.nextLine();
                        System.out.print("Telefono = ");
                        String telefono = scanner.nextLine();

                        corriere.aggiungiCliente(new Cliente(cf, denominazione, nazione, indirizzo, telefono));
                        
                        System.out.println("Cliente aggiunto con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante l'inserimento del cliente..." + ex.getMessage());
                    }
                    break;
                case 2:
                    try {
                        System.out.print("Codice spedizione = ");
                        String codice = scanner.nextLine();
                        System.out.print("Codice Fiscale mittente = ");
                        String cf_mittente = scanner.nextLine();
                        System.out.print("Codice Fiscale destinatario = ");
                        String cf_destinatario = scanner.nextLine();

                        corriere.aggiungiSpedizione(codice, cf_mittente, cf_destinatario);
                        
                        System.out.println("Spedizione aggiunta con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante l'inserimento della spedizione..." + ex.getMessage());
                    }
                    break;
                case 3:
                    corriere.stampaClienti();
                    break;
                case 4:
                    corriere.stampaSpedizioni();
                    break;
                case 5:
                    try {
                        System.out.print("Codice Fiscale = ");
                        String cf = scanner.nextLine();

                        corriere.rimuoviCliente(cf);
                        
                        System.out.println("Cliente rimosso con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante la rimozione del cliente..." + ex.getMessage());
                    }
                    break;
                case 6:
                    try {
                        System.out.print("Codice spedizione = ");
                        String codice = scanner.nextLine();

                        corriere.rimuoviSpedizione(codice);
                        
                        System.out.println("Spedizione rimossa con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante la rimozione della spedizione..." + ex.getMessage());
                    }
                    break;
                case 7:
                    try {
                        System.out.print("Nome file clienti = ");
                        String filename_clienti = scanner.nextLine();
                        corriere.salvaClientiSuFile(filename_clienti);

                        System.out.print("Nome file spedizioni = ");
                        String filename_spedizioni = scanner.nextLine();
                        corriere.salvaSpedizioniSuFile(filename_spedizioni);
                        
                        System.out.println("Salvataggio avvenuto con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante il salvataggio dei file..." + ex.getMessage());
                    }
                    break;
                case 8:
                    try {
                        System.out.print("Nome file clienti = ");
                        String filename_clienti = scanner.nextLine();
                        corriere.caricaClienteDaFile(filename_clienti);

                        System.out.print("Nome file spedizioni = ");
                        String filename_spedizioni = scanner.nextLine();
                        corriere.caricaSpedizioniDaFile(filename_spedizioni);
                        
                        System.out.println("Caricamento avvenuto con successo!");
                    } catch (Exception ex) {
                        System.out.println("Errore durante il caricamento dei file..." + ex.getMessage());
                    }
                    break;
                case 9:
                    break;
                default:
                    System.out.println("Scelta non valida. Riprova.");
                    break;
            }

            if (scelta==9) break;
        }

        scanner.close();
        System.out.println("|---------Grazie per aver utilizzato il sistema di logistica!-------|");
    }
}
