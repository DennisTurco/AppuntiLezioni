package Lista.ListaAuto;
import static org.junit.Assert.*;
import org.junit.Test;

import org.junit.After;
import org.junit.Before;

public class CarSharingTest {
    private CarSharing car;

    @Before
    public void setup() {
        car = new CarSharing();
    }

    @After
    public void cleanup() {
        car = null;
    }

    @Test
    public void testAggiungiParcheggio() {
        car.aggiungiParcheggio("ParcheggioA");
        assertTrue(car.trovaParcheggio("ParcheggioA") != null);
    }

    @Test
    public void testAggiungiAutomobile() {
        car.aggiungiParcheggio("ParcheggioA");
        car.aggiungiAutomobile("AutomobileA", "ParcheggioA");
        assertTrue(car.trovaAutomobile("AutomobileA") != null);
    }

    @Test
    public void testAggiungiAutomobileErrato() {
        car.aggiungiParcheggio("ParcheggioA");
        car.aggiungiAutomobile("AutomobileA", "ParcheggioA");
        assertThrows(IllegalArgumentException.class, () -> {
            car.aggiungiAutomobile("AutomobileA", "ParcheggioA");
        });
    }

    @Test
    public void testAggiungiParcheggioErrato() {
        car.aggiungiParcheggio("ParcheggioA");
        assertThrows(IllegalArgumentException.class, () -> {
            car.aggiungiParcheggio("ParcheggioA");
        });
    }

    @Test
    public void testSpostaAutomobile() {
        Parcheggio parcheggioA = new Parcheggio("ParcheggioA");
        Parcheggio parcheggioB = new Parcheggio("ParcheggioB");
        car.aggiungiParcheggio(parcheggioA);
        car.aggiungiParcheggio(parcheggioB);

        Automobile auto = new Automobile("AutomobileA", parcheggioA);
        parcheggioA.aggiungiAutomobile(auto);

        car.transito("AutomobileA", parcheggioB.getNome());
        car.transito("AutomobileA", parcheggioA.getNome());
        car.transito("AutomobileA", parcheggioB.getNome());
        
        assertEquals(3, auto.getViaggi());
    }

}