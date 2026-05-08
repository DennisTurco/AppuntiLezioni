package CorsoMinecraft.ereditarieta;

public class Zombie extends Enemy{
    private boolean isBaby;

    public Zombie (int hp, int damage, float speed, float height, boolean isBaby) {
        super(hp, damage, speed, height);
        this.isBaby = isBaby;
    }

    @Override
    protected void death() {
        System.out.println("Noooo sono uno zombie morto...");
    }

    @Override
    protected void underAttackMessage() {
        System.out.println("Zombie Under attack, hp: " + getHp());
    }

    public boolean isIsBaby() {
        return isBaby;
    }
}
