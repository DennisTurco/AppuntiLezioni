package Lista.ListaMotoSalone;
public class Moto {

	private double cilindrata;
	private String marca;
	private String modello;
	
	public Moto(double cilindrata, String marca, String modello) {
		this.cilindrata = cilindrata;
		this.marca = marca;
		this.modello = modello;
	}

	public double getCilindrata() {
		return cilindrata;
	}

	public String getMarca() {
		return marca;
	}

	public String getModello() {
		return modello;
	}

	@Override
	public String toString() {
		return "Moto [cilindrata=" + cilindrata + ", marca=" + marca + ", modello=" + modello + "]";
	}
}
