package EsercizioClassi2;

public class Triangolo {
    private double altezza;
    private double base;
    private double area;

    public Triangolo(double altezza, double base, double area) {
        this.altezza = altezza;
        this.base = base;
        this.area = area;
    }

    public double calcolaArea() {
        return base * altezza / 2;
    }

    public double calcolaAltezza() {
        return area * 2 / base;
    }

    public double calcolaBase() {
        return area * 2 / altezza;
    }

    // getter
    public double getArea() {
        return area;
    }
    public double getAltezza() {
        return altezza;
    }
    public double getBase() {
        return base;
    }
}
