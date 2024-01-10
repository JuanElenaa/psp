class HiloParImpar implements Runnable {
    private int tipo;

    public HiloParImpar(int tipo) {
        this.tipo = tipo;
    }

    @Override
    public void run() {
        if (tipo == 1) {
            for (int i = 2; i <= 100; i = i + 2) {
                System.out.println("HILO " + Thread.currentThread().getName() + " generando número par " + i);
            }
        } else if (tipo == 2) {
            for (int i = 101; i <= 200; i = i + 2) {
                System.out.println("HILO " + Thread.currentThread().getName() + " generando número impar " + i);
            }
        }
    }
}






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
