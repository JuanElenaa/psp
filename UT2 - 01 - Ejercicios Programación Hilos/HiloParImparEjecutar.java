public class HiloParImparEjecutar {
    public static void main(String[] args) {
        HiloParImpar hiloPar = new HiloParImpar(1);
        HiloParImpar hiloImpar = new HiloParImpar(2);

        Thread thread1 = new Thread(hiloPar, "xx");
        Thread thread2 = new Thread(hiloImpar, "yy");

        thread2.setPriority(Thread.MAX_PRIORITY);    
        thread1.setPriority(Thread.MIN_PRIORITY); 

        thread2.start();
        thread1.start();
    }
}
