package Lista.Pila;
public class Main {
    public static void main(String[] args) {
        Pila pila = new Pila();

        pila.push(1);
        pila.push(2);
        pila.push(3);

        System.out.println("Ottengo valore con peek: ");
        System.out.println(pila.peek());

        pila.push(5);

        // pop di elementi finche' la pila non e' vuota 
        System.out.println("Ottengo valore con pop: ");
        while (!pila.isEmpty()) {
            System.out.println(pila.pop());
        }
    }
}