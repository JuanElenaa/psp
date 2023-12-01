#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Función para manejar la señal SIGINT
void sigint_handler(int signum) {

    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y %H:%M:%S", tm);
    
    printf("Fin del proceso %d : %s\n", getpid(), fechayhora);
    exit(EXIT_SUCCESS);
}

int main(void) {
    signal(SIGINT, sigint_handler);

    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y %H:%M:%S", tm);

    printf("Inicio del proceso %d: %s\n",getpid(), fechayhora);

    // Bucle infinito para mantener el programa en ejecución
    while (1) {
        // Haciendo que el programa espere por señales
        sleep(1);
    }

    return 0;
}
