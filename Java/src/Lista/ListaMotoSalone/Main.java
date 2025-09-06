package Lista.ListaMotoSalone;
public class Main {

	public static void main(String[] args) {

		Motosalone motosalone = new Motosalone();
		
		Moto b1 = new Moto(1200,"Bmw","Gs");
		Moto b2 = new Moto(450,"Honda","Crf");
		Moto b3 = new Moto(250,"Yamaha","Yzf");
		
		motosalone.inserisciInCoda(b1);
		motosalone.inserisciInCoda(b2);
		motosalone.inserisciInCoda(b3);
		
		System.out.println("prima dell'eliminazione: ");
		motosalone.VisitaLista();
		
		System.out.println("\ndopo l'eliminazione: ");
		motosalone.eliminaInTesta();
		motosalone.VisitaLista();
		
		System.out.println("\ncilindrata totale: " + motosalone.CilindrataTotale());
	}

}
