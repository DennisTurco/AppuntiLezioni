package Lista.ListaCorriere;
import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/*
    I metodi @Before e @After sono importanti perché assicurano che ogni test parta da uno stato noto e coerente e che 
    non ci siano interferenze tra un test e un altro dovute allo stato residuo lasciato da test precedenti. 
*/

// void org.junit.Assert.assertEquals(double expected, double actual, double delta)
// void org.junit.Assert.assertTrue(boolean condition)

public class CorriereTest {
    private Corriere corriere;

    // setup
    @Before
    public void setUp() {
        corriere = new Corriere();
    }

    // cleanup
    @After
    public void tearDown() {
        corriere = null;
    }

    @Test
    public void testAggiungiCliente() {
        Cliente cliente = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        corriere.aggiungiCliente(cliente);
        assertTrue(corriere.getClienteByCF("MRORMR80A01H501K") != null);
    }

    @Test
    public void testRimuoviCliente() {
        Cliente cliente = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        corriere.aggiungiCliente(cliente);
        corriere.rimuoviCliente(cliente);
        assertTrue(corriere.getClienteByCF("MRORMR80A01H501K") == null);
    }

    @Test
    public void testRimuoviClienteByCF() {
        Cliente cliente = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        corriere.aggiungiCliente(cliente);
        corriere.rimuoviCliente("MRORMR80A01H501K");
        assertTrue(corriere.getClienteByCF("MRORMR80A01H501K") == null);
    }

    @Test
    public void testAggiungiSpedizione() {
        Cliente cliente1 = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        Cliente cliente2 = new Cliente("EROASDR878SD5012", "Alberto Bianchi", "Italia", "Via Napoli 13", "123456789");
        Spedizione spedizione = new Spedizione("DASHJ32", cliente1, cliente2);
        corriere.aggiungiSpedizione(spedizione);
        assertTrue(corriere.getSpedizioneByCode("DASHJ32") != null);
    }

    @Test
    public void testAggiungiSpedizione2() {
        Cliente cliente1 = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        Cliente cliente2 = new Cliente("EROASDR878SD5012", "Alberto Bianchi", "Italia", "Via Napoli 13", "123456789");
        corriere.aggiungiCliente(cliente1);
        corriere.aggiungiCliente(cliente2);
        corriere.aggiungiSpedizione("DASHJ32", "MRORMR80A01H501K", "EROASDR878SD5012");
        assertTrue(corriere.getSpedizioneByCode("DASHJ32") != null);
    }

    @Test
    public void testRimuoviSpedizione() {
        testAggiungiSpedizione();
        corriere.rimuoviSpedizione("DASHJ32");
        assertTrue(corriere.getSpedizioneByCode("DASHJ32") == null);
    }

    @Test
    public void testRimuoviSpedizione2() {
        Cliente cliente1 = new Cliente("MRORMR80A01H501K", "Mario Rossi", "Italia", "Via Roma 123", "123456789");
        Cliente cliente2 = new Cliente("EROASDR878SD5012", "Alberto Bianchi", "Italia", "Via Napoli 13", "123456789");
        Spedizione spedizione = new Spedizione("DASHJ32", cliente1, cliente2);
        corriere.aggiungiSpedizione(spedizione);
        corriere.rimuoviSpedizione(spedizione);
        assertTrue(corriere.getSpedizioneByCode("DASHJ32") == null);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testRimuoviClienteNonEsistente() {
        corriere.rimuoviCliente("CF_NON_ESISTENTE");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testAggiungiSpedizioneConMittenteNonEsistente() {
        Cliente destinatario = new Cliente("Luigi", "Verdi", "LVRLGI80A01H501L", "Via Milano 456", "luigi.verdi@example.com");
        corriere.aggiungiCliente(destinatario);
        corriere.aggiungiSpedizione("COD123", "CF_NON_ESISTENTE", "LVRLGI80A01H501L");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testAggiungiSpedizioneConDestinatarioNonEsistente() {
        Cliente mittente = new Cliente("Mario", "Rossi", "MRORMR80A01H501K", "Via Roma 123", "mario.rossi@example.com");
        corriere.aggiungiCliente(mittente);
        corriere.aggiungiSpedizione("COD123", "MRORMR80A01H501K", "CF_NON_ESISTENTE");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testRimuoviSpedizioneNonEsistente() {
        corriere.rimuoviSpedizione("COD_NON_ESISTENTE");
    }
}
