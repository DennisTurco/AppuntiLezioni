package Lista.ListaMotoSalone;
public class Motosalone {
	private Nodo head;
	private int elementi;
	
	public Motosalone() {
		this.head = null;
		this.elementi = 0;
	}
	
	public void VisitaLista() {
		Nodo p = head;
		
		while(p != null) {
			System.out.println(p.getInfo().toString());
			p = p.getLink();
		}
	}
	
	public void inserisciInTesta(Moto info) {
		Nodo n = new Nodo(info);
		n.setLink(head);
	
		head = n;
		elementi++;
	}
	
	public void inserisciInCoda(Moto info) {
		Nodo p = head;
		Nodo n = new Nodo(info);
		
		if(p == null)
			inserisciInTesta(info);
		else {
			while(p.getLink()!= null)
				p = p.getLink();
			
			p.setLink(n);
			elementi++;
		}
	}
	
	public void eliminaInTesta() {
		if(head == null)
			throw new IllegalStateException("errore, lista già vuota");
		head = head.getLink();
		
		elementi--;
	}
	
	public void eliminaInCoda() {
		if(head == null)
			throw new IllegalStateException("errore, lista già vuota");
		if(head.getLink() == null)
			eliminaInTesta();
		else {
			Nodo p = head;
			while (p.getLink().getLink() != null) {
				p = p.getLink();
			}
			elementi--;
		}
	}
	
	public double CilindrataTotale() {
		double durata = 0;
		Nodo c = head; 
		while(c != null) {
			durata = durata + c.getInfo().getCilindrata();
			c = c.getLink();
		}
		return durata;
	}

	public int getElementi() {
		return elementi;
	}
}