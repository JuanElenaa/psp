#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    static int segundos = 5;
    printf("Han transcurrido %d segundos\n", segundos);
    segundos += 5;
    alarm(5); 
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    alarm(5); // Configura la primera alarma para que suene en 5 segundos

    // Bucle infinito para mantener el programa en ejecución
    while (1) {
        // Espera por señales
        sleep(1);
    }

    return 0;
}
