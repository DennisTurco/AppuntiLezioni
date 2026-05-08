package CorsoMinecraft.ereditarieta;

public class Main {
    public static void main(String[] args) {

        // spawno qualche enemy
        Zombie z1 = new Zombie(20, 2, 3.3f, 2f, false);
        Skeleton s1 = new Skeleton(10, 1, 1.3f, 2f);
        Zombie z2 = new Zombie(10, 3, 5.2f, 0.5f, true);
        Skeleton s2 = new Skeleton(20, 1, 1.3f, 2f);

        s1.underAttack(12);
        z2.underAttack(1);
        z1.underAttack(3);
        z1.underAttack(7);
        z1.underAttack(10);
        s2.underAttack(8);

        Enemy e = new Enemy(0, 0, 0, 0);

        System.out.println(z1 instanceof Enemy);
        System.out.println(s1 instanceof Enemy);
        System.out.println(s1 instanceof Skeleton);
        // System.out.println(s1 instanceof Zombie);
        System.out.println(s1 instanceof Object);
        System.out.println(z1 instanceof Object);
        System.out.println(e instanceof Object);
    }
}
