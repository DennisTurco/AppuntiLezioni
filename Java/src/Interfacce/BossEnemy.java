package Interfacce;
// implements si usa per implementare un interfaccia
public class BossEnemy implements InterfaceEnemy {
    private float health = 900;
    private float damage = 10.5f;

    @Override
    public void takeDamage(float damage) {
        health -= damage;

        if (health <= 0) {
            System.out.println("I'm dead!");
        }
        else {
            System.out.println("I'm still alive because i'm the boss!");
        }
    }

    @Override
    public void increaseDamage(float damage) {
        this.damage = damage;
    }
}

