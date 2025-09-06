public class Chiave {
    private int numeroCamera;
    private String nominativo;

    public Chiave(int numeroCamera, String nominativo) {
        this.numeroCamera = numeroCamera;
        this.nominativo = nominativo;
    }

    public int getNumeroCamera() {
        return numeroCamera;
    }
    public String getNominativo() {
        return nominativo;
    }
}
