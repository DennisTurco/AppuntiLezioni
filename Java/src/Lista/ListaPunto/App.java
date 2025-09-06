package Lista.ListaPunto;
public class App {
    public static void main(String[] args)  {
        Punto p1 = new Punto(2, 3);
        Punto p2 = new Punto(5, 7);
        Punto p3 = new Punto(10, 4);

        Spezzata spezzata = new Spezzata();
        spezzata.AggiungiPunto(p1);
        spezzata.AggiungiPunto(p2);
        spezzata.AggiungiPunto(p3);
        
        spezzata.StampaCoordinate();

        System.out.println("Lunghezza totale: " + spezzata.CalcolaLunghezzaTotale());
    }
}
