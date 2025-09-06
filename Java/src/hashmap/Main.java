package hashmap;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws Exception {
        
        HashMap<String, String> map = new HashMap<String, String>();
        
        // Add Items
        map.put("England", "London");
        map.put("Germany", "Berlin");
        map.put("Norway", "Oslo");
        map.put("USA", "Washington DC");
        System.out.println(map);

        // Access an Item
        map.get("England");

        // Remove an Item
        map.remove("England");
        map.clear();

        // HashMap Size
        map.size();

        // Loop Through a HashMap
        // Print keys
        for (String i : map.keySet()) {
            System.out.println(i);
        }

        // Print values
        for (String i : map.values()) {
            System.out.println(i);
        }
    }
}
