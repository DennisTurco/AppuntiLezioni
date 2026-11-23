package Ereditarieta2;

public class AnimaleHelper {
    public static void stampaAnimali(Animale[] animali) {
        for (int i = 0; i < animali.length; i++) {
            System.out.println(animali[i].toString());
        }
    }

    public static void stampaSuoni(Animale[] animali) {
        for (int i = 0; i < animali.length; i++) {
            animali[i].suono();
        }
    }
}
