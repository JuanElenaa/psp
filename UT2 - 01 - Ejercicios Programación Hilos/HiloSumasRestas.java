public class HiloSumasRestas implements Runnable {
    private int numero = 1000;
    private int numveces = 0;
    private String operacion;

    // Constructor de la clase
    public HiloSumasRestas(int numveces, String operacion) {
        this.numveces = numveces;
        this.operacion = operacion;
    }

    // Incrementará numero el numvece indicado
    public int incrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero++;
        }

        return numero;
    }

    // Decrementará numero el numvece indicado
    public int decrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero--;
        }
        return numero;
    }

    public void run() {
        // Si la operación es “+” se invocará al método incrementar
        // Si la operación es “-” se invocará al método decrementar
        if (this.operacion.equals("+")) {
            System.out.println(incrementar(this.numveces));
        } else {
            System.out.println(decrementar(this.numveces));
        }

    }
}
