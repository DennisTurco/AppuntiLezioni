package casting;

public class Main {
    public static void main(String[] args) {
        int x1 = 5;
        int x2 = 6;

        float s1 = somma(x1/x2, x2);
        System.out.println(s1);

        float s2 = somma((float)x1/x2, x2);
        System.out.println(s2);
    }

    public static float somma(float f1, float f2) {
        return f1 + f2;
    }
}
