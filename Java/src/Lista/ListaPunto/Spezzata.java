package Lista.ListaPunto;
import java.util.ArrayList;

public class Spezzata {
    private ArrayList<Punto> punti;

    public Spezzata() {
        punti = new ArrayList<>();
    }

    public void AggiungiPunto(Punto punto) {
        punti.add(punto);
    }

    public void StampaCoordinate() {
        for(int i = 0; i < punti.size(); i++) {
            System.out.println("Coordinata "+(i+1) +": ("+punti.get(i).getX()+", "+punti.get(i).getY()+")");
        }
    }

    public void EliminaCoordinata(int posizione) {
        if (posizione >= 0 && posizione < punti.size())
            punti.remove(posizione);
    }

    public double CalcolaLunghezzaTotale() {
        double res = 0;

        // ho almeno 2 elementi
        if (punti.size() > 1) { 
            for (int i = 0; i < punti.size()-1; i++) {
                res = res + punti.get(i).DistanzaDalPunto(punti.get(i+1)); 
            }
        }
            
        return res;
    }
}
