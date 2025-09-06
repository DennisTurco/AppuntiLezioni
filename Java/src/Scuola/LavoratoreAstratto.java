package Scuola;
// classe non utilizzata, rappresenta un esempio di classe astratta.

public abstract class LavoratoreAstratto {
    // metodi astratti, il comportamento verrà definito nelle classi derivate
    // questi metodi sono astratti perchè hanno un'implementazione completamente diversa da tutte le
    // classi derivate
    public abstract float CalcolaStipendio(float ore_mensili, float paga_oraria);
    public abstract String CompitoSvolto();
}


// possibili classi derivate
/*
public class Segretaria extends LavoratoreAstratto {
    @Override
    public float CalcolaStipendio(float ore_mensili, float paga_oraria) {
        return ore_mensili * paga_oraria;
    }
    @Override
    public String CompitoSvolto() {
        return "Faccio la segretaria";
    }    
}

public class Insegnate extends LavoratoreAstratto {
    @Override
    public float CalcolaStipendio(float ore_mensili, float paga_oraria) {
        return ore_mensili * paga_oraria * (float)1.2;
    }
    @Override
    public String CompitoSvolto() {
        return "Insegno agli studenti";
    }
}
 */