package Java.src.ereditarieta_esempio_completo;

// classe derivata
public class Quadrato extends Rettangolo{
    // in questo caso questa classe non ha attributi
    // perchè già tutti contenuti nella classe base
    
    // costruttore senza parametri
    public Quadrato() {
        super();
    }

    // costruttore con un parametro 
    public Quadrato(int lato){
        super(lato, lato);
    }

    // metodo
    public double circonferenza() {
        return getAltezza()*3.14;
    }

    // metodo
    public int perimetro() {
        // invoca il metodo perimetro della classe base
        return super.perimetro();
    }
}
