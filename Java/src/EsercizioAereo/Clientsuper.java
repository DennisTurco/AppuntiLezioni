package EsercizioAereo;

public class Clientsuper {
	protected String tessera;
	protected int oreVolo;
	public Clientsuper(String tessera,int oreVolo) {
		this.tessera=tessera;
		this.oreVolo=oreVolo;
	}
	public String getTessera() {
		return tessera;
	}
	public void setTessera(String tessera) {
		this.tessera = tessera;
	}
	public int getOreVolo() {
		return oreVolo;
	}
	public void setOreVolo(int oreVolo) {
		this.oreVolo = oreVolo;
	}

	@Override
	public String toString() {
		return "Clientsuper [tessera=" + tessera + ", oreVolo=" + oreVolo + "]";
	}
}