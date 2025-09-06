package Lista.Coda;
public class Main {
    public static void main(String[] args) {
        Coda coda = new Coda();

        coda.enqueue(1);
        coda.enqueue(2);
        coda.enqueue(3);

        System.out.println("Ottengo valore con peek: ");
        System.out.println(coda.peek());

        coda.enqueue(5);

        // pop di elementi finche' la coda non e' vuota 
        System.out.println("Ottengo valore con pop: ");
        while (!coda.isEmpty()) {
            System.out.println(coda.dequeue());
        }
    }
}
