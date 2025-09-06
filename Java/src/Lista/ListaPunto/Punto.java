package Lista.ListaPunto;
public class Punto {
    private double x;
    private double y;

    public Punto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    public double DistanzaDalPunto(Punto altro_punto) {
        return Math.sqrt(Math.pow(altro_punto.getX()-this.x,2) + Math.pow(altro_punto.getY()-this.y,2)); //sqrt((x2-x1)^2 - (y2-y1)^2)
    }
}
