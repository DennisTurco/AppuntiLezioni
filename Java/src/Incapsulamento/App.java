package Incapsulamento;
public class App {
    public static void main(String[] args) throws Exception {
        // Persona persona = new Persona("Carlo", 2);

        // persona.setEta(8); // != persona.eta = 8
        // persona.setNome("Carlino"); // != persona.nome = "Carlino"

        // persona.setNome(""); // != persona.nome = "" 


        System.out.println(Persona.getRazza());
        
        Persona pers = new Persona("das", 23);
        System.out.println(pers.getPianeta());
    }
}
