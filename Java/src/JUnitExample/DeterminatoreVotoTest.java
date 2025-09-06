package JUnitExample;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertThrows;

import org.junit.Before;
import org.junit.After;

public class DeterminatoreVotoTest {
    
    private DeterminatoreVoto determinatore;

    /*
        ####################### Setup e Teardown #######################
        Setup e Teardown sono concetti fondamentali nei test unitari che ti 
        permettono di preparare l'ambiente di test prima che i test vengano eseguiti (Setup) 
        e di pulirlo dopo che i test sono stati eseguiti (Teardown). 
    */

    @Before
    public void startup() {
        determinatore = new DeterminatoreVoto();
    }

    @After
    public void cleanup() {
        determinatore = null;
    }

    /*
        ####################### Test dei Limiti #######################
        Aggiungere test per i limiti inferiori e superiori di ciascuna fascia di 
        voto può aiutare a garantire che il comportamento della funzione sia 
        corretto ai bordi delle condizioni.
    */

    @Test
    public void testCinquantacinqueDovrebbeRitornareF() {
        char lettera = determinatore.determinaVotoInLettera(55);
        assertEquals('F', lettera);
    }

    @Test
    public void testSessantacinqueDovrebbeRitornareD() {
        char lettera = determinatore.determinaVotoInLettera(65);
        assertEquals('D', lettera);
    }

    @Test
    public void testSettantacinqueDovrebbeRitornareC() {
        char lettera = determinatore.determinaVotoInLettera(75);
        assertEquals('C', lettera);
    }

    @Test
    public void testOttantacinqueDovrebbeRitornareB() {
        char lettera = determinatore.determinaVotoInLettera(85);
        assertEquals('B', lettera);
    }

    @Test
    public void testNovantacinqueDovrebbeRitornareA() {
        char lettera = determinatore.determinaVotoInLettera(95);
        assertEquals('A', lettera);
    }

    /*
        ####################### Utilizzo di Assert più Avanzati #######################
    */

    @Test
    public void testCheNonRestituisceNull() {
        char lettera = determinatore.determinaVotoInLettera(75);
        assertNotNull(lettera);
    }


    /*
        ####################### Test delle Eccezioni #######################
        Questo tipo di test è fondamentale per garantire che il software gestisca gli 
        errori come previsto, migliorando la robustezza e l'affidabilità del codice.
    */

    @Test
    public void testVotoNegativoDovrebbeRitornareException() {
        assertThrows(IllegalArgumentException.class, () -> {
            determinatore.determinaVotoInLettera(-10);
        });
    }

    @Test
    public void testVotoEccessivoDovrebbeRitornareException() {
        assertThrows(IllegalArgumentException.class, () -> {
            determinatore.determinaVotoInLettera(101);
        });
    }

    @Test
    public void testVotoNegativoDovrebbeRitornareExceptionConMessaggio() {
        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            determinatore.determinaVotoInLettera(-10);
        });
        assertEquals("Il voto non puo' essere negativo", exception.getMessage());
    }
}
