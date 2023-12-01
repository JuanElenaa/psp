#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

FILE *archivo;

// Función para manejar la señal SIGQUIT
void sigquit_handler(int signum) {
    fclose(archivo);
    exit(EXIT_SUCCESS);
}

// Función para manejar la señal SIGINT
void sigint_handler(int signum) {
    time_t rawtime;
    struct tm *timeinfo;
    char timestamp[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%T", timeinfo);

    fprintf(archivo, "Señal SIGINT recibida a las %s\n", timestamp);
}

int main(void) {
    archivo = fopen("salidas.txt", "a");

    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);

    printf("Presiona Ctrl + C para escribir en el fichero cuando se generó la señal\n");
    printf("Para terminar el programa, usa 'Ctrl + \\'\n");

    // Bucle infinito para mantener el programa en ejecución
    while (1) {
        // Bucle infinito para mantener el programa en ejecución
        sleep(1);
    }

    return EXIT_SUCCESS;
}
