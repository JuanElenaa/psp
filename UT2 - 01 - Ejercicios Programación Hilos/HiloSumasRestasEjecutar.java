public class HiloSumasRestasEjecutar {
    public static void main(String[] args) {
        Thread hiloSuma1 = new Thread(new HiloSumasRestas(100, "+"));
        Thread hiloResta2 = new Thread(new HiloSumasRestas(100, "-"));
        Thread hiloSuma3 = new Thread(new HiloSumasRestas(1, "+"));
        Thread hiloResta4 = new Thread(new HiloSumasRestas(1, "-"));

        hiloSuma1.start();
        hiloResta2.start();
        hiloSuma3.start();
        hiloResta4.start();
    }
}
