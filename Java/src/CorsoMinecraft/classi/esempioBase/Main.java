package CorsoMinecraft.classi.esempioBase;

// per ogni classe facciamo un file a parte

public class Main {
    public static void main(String[] args) {

        // creazione dell'oggetto Rettangolo
        Rettangolo rettangolo = new Rettangolo();
        float perimetro = rettangolo.calcolaPerimetro();
        float area = rettangolo.calcolaArea();
        System.out.println("Perimetro = " + perimetro + ", Area = " + area);

        System.out.println("Base = " + rettangolo.getBase());

        rettangolo.setBase(6);
        rettangolo.setAltezza(10);

        perimetro = rettangolo.calcolaPerimetro();
        area = rettangolo.calcolaArea();
        System.out.println("Perimetro = " + perimetro + ", Area = " + area);
    }
}
