package Interfacce;
public class App {
    public static void main(String[] args) throws Exception {

        /* Gestione come se non avessimo le interfacce
        SimpleEnemy simpleEnemy = new SimpleEnemy();
        BossEnemy bossEnemy = new BossEnemy();

        simpleEnemy.takeDamage(10);
        bossEnemy.takeDamage(10);

        EnemyManager.incrementEnemyDamage(simpleEnemy, 40);
        EnemyManager.incrementEnemyDamage(bossEnemy, 40);
        */

        // Gestione sfruttando le interfacce
        InterfaceEnemy simpleEnemy = new SimpleEnemy();
        InterfaceEnemy bossEnemy = new BossEnemy();

        simpleEnemy.takeDamage(10);
        bossEnemy.takeDamage(10);

        EnemyManager.incrementEnemyDamage(simpleEnemy, 40);
        EnemyManager.incrementEnemyDamage(bossEnemy, 40);
    }
}
