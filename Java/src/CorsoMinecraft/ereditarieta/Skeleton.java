package CorsoMinecraft.ereditarieta;

public class Skeleton extends Enemy {

    public Skeleton (int hp, int damage, float speed, float height) {
        super(hp, damage, speed, height);
    }

    // override perche' ridefinisco il metodo della classe base
    @Override
    protected void death() {
        System.out.println("Noooo sono uno scheletro morto...");
    }

    @Override
    protected void underAttackMessage() {
        System.out.println("Skeleleton Under attack, hp: " + getHp());
    }
}
