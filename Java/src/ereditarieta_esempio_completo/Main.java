package Java.src.ereditarieta_esempio_completo;

public class Main {
    public static void main(String[] args) {
        Rettangolo r1 = new Rettangolo(5, 7);
        Quadrato q1 = new Quadrato(4);

        System.out.println(r1.area());  // area del rettangolo
        System.out.println(q1.area());  // area del quadrato

        System.out.println(r1 instanceof Rettangolo); // -> true
        System.out.println(q1 instanceof Quadrato); // -> true
        System.out.println(q1 instanceof Rettangolo); // -> true
        System.out.println(r1 instanceof Quadrato); // -> false
        System.out.println(q1 instanceof Object); // -> true
    }
}