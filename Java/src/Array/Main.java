import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(5);
        list.add(1);
        list.add(3);
        list.add(8);
        list.add(2);

        // in tutte le seguenti operazioni non usiamo mai cicli, se le dovessimo fare con un array, sarebbero necessari

        // a differenza di un array classico posso stampare il contenuto direttamente senza ciclo
        System.out.println("List: " + list);

        // array list ha una dimensione dinamica
        System.out.println("Size: " + list.size());
        list.remove(0);
        System.out.println("Size: " + list.size());

        // array list permette di eseguire alcune operazioni complicate in modo semplice grazie a delle funzioni di libreria
        list.sort(null);
        System.out.println("Sorted list: " + list);

        // puoi sostituisci elementi nel mezzo
        list.set(2, 10);
        System.out.println("List: " + list);

        // puoi aggiungere elementi nel mezzo
        list.add(2, -1);
        System.out.println("List: " + list);

        // verifica se contiene un elemento
        System.out.println("Contains 3: " + list.contains(3));

        

        // le liste in generale non sono meglio in tutto e per tutto!
    }
}
