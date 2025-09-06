package Binding;
public class App {
    public static void main(String[] args) throws Exception {
        // Binding statico
        Smartphone smatphone = new Smartphone("Iphone 13", 50000);

        // Binding dinamico
        Device dispositivo1 = new Smartphone("Iphone 14", 100000);
        Device dispositivo2 = new PC("HP", 1000, 64);


        calcolaScontoDevice(smatphone);
        calcolaScontoDevice(dispositivo1);
        calcolaScontoDevice(dispositivo2);
    }


    // perchè il binding dinamico è utile?
    private static void calcolaScontoDevice(Device device) {
        device.calcolaSconto(10);
    }
}
