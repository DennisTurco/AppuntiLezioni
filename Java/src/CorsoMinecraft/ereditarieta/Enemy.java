package CorsoMinecraft.ereditarieta;

public class Enemy {
    private int hp;
    private int damage;
    private float speed;
    private float height;
    private boolean alive;

    public Enemy (int hp, int damage, float speed, float height) {
        this.hp = hp;
        this.damage = damage;
        this.speed = speed;
        this.height = height;
        this.alive = true;
    }

    // METODI
    public void underAttack(int damage) {
        hp = hp - damage;
        underAttackMessage();
        if (hp <= 0) {
            alive = false;
            death();
        }
    }

    // metodo non chiamabile esternamente perche' private
    protected void death() {
        System.out.println("Noooo sono un nemico morto...");
    }

    protected void underAttackMessage() {
        System.out.println("Enemy Under attack, hp: " + hp);
    }

    public int getHp() {
        return hp;
    }
}
