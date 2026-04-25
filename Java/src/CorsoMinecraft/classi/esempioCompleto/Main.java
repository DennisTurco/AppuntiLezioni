package CorsoMinecraft.classi.esempioCompleto;

public class Main {
    public static void main(String[] args) {
        Point p1 = new Point(5, 9);
        Point p2 = new Point(-1, 8);

        Line l = new Line(p1, p2);
        System.out.println("distanza = " + l.calcolaDistanzaTraDuePunti());
    }
}
