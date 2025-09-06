public class App {
    public static void main(String[] args) throws Exception {

        Chiave c1 = new Chiave(1, null);
        Chiave c2 = new Chiave(2, null);
        Chiave c3 = new Chiave(3, null);

        Portachiavi portachiavi = new Portachiavi(3);

        portachiavi.aggiungiChiave(c1);
        portachiavi.aggiungiChiave(c2);
        portachiavi.aggiungiChiave(c3);
    }
}
