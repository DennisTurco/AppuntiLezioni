package Lista.lista2;
package Lista.lista2.src;

public class App {
    public static void main(String[] args) throws Exception {
        Lista list = new Lista();

        list.aggiungiInTesta(0);
        list.aggiungiInTesta(1);
        list.aggiungiInTesta(2);

        System.out.println(list.toString());

        list.aggiungiInTesta(3);

        System.out.println(list.toString());

        list.aggiungiInCoda(4);
        list.aggiungiInCoda(5);

        System.out.println(list.toString());

        System.out.println("Dimensione lista: " + list.getDim());

        int val = list.eliminaInCoda();
        System.out.println("Elemento rimosso: " + val);
        System.out.println(list.toString());

        int val2 = list.eliminaInTesta();
        System.out.println("Elemento rimosso: " + val2);
        System.out.println(list.toString());

        list.aggiungiInPosizione(10, 0);
        System.out.println(list.toString());

        for (int i = 0; i < 10; i++) {
            list.eliminaInCoda();
        }
        System.out.println(list.toString());
    }
}
