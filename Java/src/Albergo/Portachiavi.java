public class Portachiavi {
    private Chiave[] chiavi;
    private int chiaviInserite; // facoltativo

    public Portachiavi(int dim) {
        if (dim <= 0) {
            throw new IllegalArgumentException("Dimensione portachiavi non valida!");
        }

        chiavi = new Chiave[dim];
        chiaviInserite = 0;
    }

    public void aggiungiChiave(Chiave chiave) {
        if (chiave == null) {
            throw new NullPointerException("La chiave nulla non è ammissibile!");
        }

        // se non ho più posti liberi nel portachiavi non posso più aggiungere una chiave
        if (chiaviInserite >= chiavi.length) {
            throw new IllegalStateException("Il portachiavi è pieno, impossibile aggiungere la chiave!");
        }

        // aggiungo la chiave nella prima posizione valida
        for (int i = 0; i < chiavi.length; i++) {
            if (chiavi[i] == null) {
                chiavi[i] = chiave;
                break;
            }
        }

        chiaviInserite++;
    }

    /*
    Classi Wrapper:
        esempi:
        int -> Integer
        boolean -> Boolean
        float -> Float
        char -> Character

        int può avere valori come: 1, -4, 2, 1000, ecc...
        Integer può avere valori come: 1, -4, 2, 1000, ecc... e null

        boolean può avere valori come: true e false
        Boolean può avere valori come: true, false e null

     */
    public Chiave prendiChiave(Integer numeroCamera, String nominativo) {
        if (chiaviInserite == 0) {
            throw new IllegalStateException("Il portachiavi è vuoto, impossibile prendere la chiave!");
        }
        if (numeroCamera == null && nominativo == null) {
            throw new NullPointerException("Il numero di camera e il nominativo non possono essere nulli!");
        }

        if (numeroCamera != null) {
            return getChiaveByNumeroCamera(numeroCamera);
        }
        else {
            return getChiaveByNominativoCamera(nominativo);
        }
    }

    private Chiave getChiaveByNumeroCamera(int numero) {
        for (int i = 0; i < chiavi.length; i++) {
            if (chiavi[i].getNumeroCamera() == numero) {
                chiaviInserite--;
                Chiave chiave = chiavi[i];
                chiavi[i] = null; // tolgo la chiave dal portachiavi
                return chiave;
            }
        }

        return null; // se non trovo la chiave
    }

    private Chiave getChiaveByNominativoCamera(String nominativo) {
        for (int i = 0; i < chiavi.length; i++) {
            if (chiavi[i].getNominativo().equals(nominativo)) { // in java non si può fare stringa1 == stringa2, ma bisogna usare equals -> stringa1.equals(stringa2)
                chiaviInserite--;
                Chiave chiave = chiavi[i];
                chiavi[i] = null; // tolgo la chiave dal portachiavi
                return chiave;
            }
        }

        return null; // se non trovo la chiave
    }


    public Chiave[] getChiavi() {
        return chiavi;
    }
    public int getChiaviInserite() {
        return chiaviInserite;
    }
}
