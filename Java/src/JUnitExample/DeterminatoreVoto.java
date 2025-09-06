package JUnitExample;
public class DeterminatoreVoto {
    public char determinaVotoInLettera (int voto) {
        if (voto < 0) {
            throw new IllegalArgumentException("Il voto non puo' essere negativo");
        } 
        else if (voto > 100) {
            throw new IllegalArgumentException("Il voto non puo' essere superiore a 100");
        }
        else if (voto < 60) {
            return 'F';
        }
        else if (voto < 70) {
            return 'D';
        }
        else if (voto < 80) {
            return 'C';
        }
        else if (voto < 90) {
            return 'B';
        }
        else {
            return 'A';
        }
    }
}