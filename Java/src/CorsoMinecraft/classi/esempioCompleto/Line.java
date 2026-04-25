package CorsoMinecraft.classi.esempioCompleto;

// rappresenta una linea nel piano cartesiano
public class Line {
    private Point p1;
    private Point p2;

    public Line(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public double calcolaDistanzaTraDuePunti() {
        return Math.sqrt(Math.pow(p1.getX() + p2.getX(), 2) + Math.pow(p1.getY() + p2.getY(), 2));
    }
}
