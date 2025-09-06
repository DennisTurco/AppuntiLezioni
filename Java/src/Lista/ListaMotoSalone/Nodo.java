package Lista.ListaMotoSalone;
public class Nodo {
	private Nodo link;
	private Moto info;
	
	public Nodo(Moto info) {
		this.link = null;
		this.info = info;
	}

	public Nodo getLink() {
		return link;
	}

	public void setLink(Nodo link) {
		this.link = link;
	}

	public Moto getInfo() {
		return info;
	}

	public void setInfo(Moto info) {
		this.info = info;
	}
}