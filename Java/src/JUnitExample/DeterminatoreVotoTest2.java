package JUnitExample;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThrows;

public class DeterminatoreVotoTest2 {

    private DeterminatoreVoto determinatore = new DeterminatoreVoto();

    @Test
    public void testVoti() {
        Object[][] testData = {
            {55, 'F'},
            {65, 'D'},
            {75, 'C'},
            {85, 'B'},
            {95, 'A'},
            {60, 'D'},
            {70, 'C'},
            {80, 'B'},
            {90, 'A'},
            {-10, "EXCEPTION"},
            {101, "EXCEPTION"}
        };

        for (Object[] data : testData) {
            int voto = (int) data[0];
            Object expected = data[1];

            if (expected.equals("EXCEPTION")) {
                assertThrows(IllegalArgumentException.class, () -> {
                    determinatore.determinaVotoInLettera(voto);
                });
            } else {
                char expectedLetter = (char) expected;
                char lettera = determinatore.determinaVotoInLettera(voto);
                assertEquals(expectedLetter, lettera);
            }
        }
    }
}
