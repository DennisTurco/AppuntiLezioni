package Interfacce;
public class SimpleEnemy implements InterfaceEnemy {
    private float health = 50;
    private float damage = 4.5f;

    @Override
    public void takeDamage(float damage) {
        health -= damage;

        if (health <= 0) {
            System.out.println("I'm dead!");
        }
        else {
            System.out.println("I took some damage, but i'm still alive");
        }
    }

    @Override
    public void increaseDamage(float damage) {
        this.damage = damage;
    }
}

