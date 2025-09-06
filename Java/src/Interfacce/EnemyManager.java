package Interfacce;
public class EnemyManager {

    /* SENZA INTERFACCIA
    public static void incrementEnemyDamage(SimpleEnemy enemy, float damage) {
        enemy.increaseDamage(damage);
        System.out.println("Damage incremented to: " + damage);
    }
    public static void incrementEnemyDamage(BossEnemy enemy, float damage) {
        enemy.increaseDamage(damage);
        System.out.println("Damage incremented to: " + damage);
    }
    */

    // CON INTERFACCIA
    public static void incrementEnemyDamage(InterfaceEnemy enemy, float damage) {
        enemy.increaseDamage(damage);
        System.out.println("Damage incremented to: " + damage);
    }
}
