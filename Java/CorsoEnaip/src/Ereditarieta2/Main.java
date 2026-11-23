package Ereditarieta2;

public class Main {
    public void main() {
        Animale[] animali = new Animale[5];

        Animale a1 = new Cane("Patrik", "Marrone", 30.12, 'm', false);
        Animale a2 = new Gatto("Mario", "Rosso", 3.32, 'm');
        Animale a3 = new Gatto("Pippo", "Nero", 4.52, 'm');
        Animale a4 = new Cane("Franca", "Blu", 5.21, 'f', false);
        Animale a5 = new Cane("Lilli", "Bianco", 7.98, 'f', true);

        animali[0] = a1;
        animali[1] = a2;
        animali[2] = a3;
        animali[3] = a4;
        animali[4] = a5;

        AnimaleHelper.stampaAnimali(animali);
        AnimaleHelper.stampaSuoni(animali);
    }
}
