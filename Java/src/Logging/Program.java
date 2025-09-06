package Logging;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Logger; 
import java.util.logging.SimpleFormatter;
import java.util.logging.Level;

// il logging serve ad esempio quando realizzi un applicazione con interfaccia grafica, altrimenti è abbastanza inutile

public class Program {

    private static final Logger logger= Logger.getLogger(Program.class.getName());

    public static void main(String[] args) throws Exception {
        ConsoleHandler consoleHandler = new ConsoleHandler();  // Creazione di un handler per la console 
        consoleHandler.setFormatter(new CustomFormatter());  // Impostazione di un formatter semplice per i messaggi di log 
        logger.addHandler(consoleHandler);  // Aggiunta dell'handler al logger 

        FileHandler fileHandler = new FileHandler("logFile.log");  // Creazione di un handler per il logging su file 
        fileHandler.setFormatter(new CustomFormatter());  // Impostazione di un formatter semplice per i messaggi di log 
        logger.addHandler(fileHandler);  // Aggiunta dell'handler al logger 
 
        // Disabilitazione degli handler predefiniti 
        logger.setUseParentHandlers(false); 
 
        // Impostazione del livello di log 
        logger.setLevel(Level.ALL); 
        consoleHandler.setLevel(Level.ALL); 
 
        // Log di messaggi di vari livelli 
        logger.info("Messaggio informativo"); 
        logger.warning("Messaggio di avvertimento"); 
        logger.severe("Messaggio di errore grave");
        logger.config("Messaggio config");
        
        // 3 sottotipi di messaggi di debug
        logger.fine("log di debug");
        logger.finer("log di debug");
        logger.finest("log di debug");


        try { 
            int risultato = 10 / 0; 
            System.out.println("Il risultato è: " + risultato);  
        } catch (Exception e) { 
            logger.log(Level.SEVERE, "Errore durante il calcolo: ", e.getMessage()); 
        } 
    }
}
