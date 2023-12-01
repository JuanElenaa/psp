#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_cont = 0; // Contador de veces que ha sonado la alarma
int alarm_limit = 0; // Variable para almacenar el límite de la alarma
int alarm_interval = 0; // Variable para almacenar el intervalo entre alarmas

void sigalrm_handler(int signum) {
    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y %H:%M:%S", tm);

    printf("Señal de alarma recibida a las %s\n", fechayhora);
    alarm_cont++;

    if (alarm_cont < alarm_limit) {
        alarm(alarm_interval);
    } else {
        printf("Alarma desactivada\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    printf("¿Cuántas veces sonará la alarma?: ");
    scanf("%d", &alarm_limit);

    printf("¿Cada cuántos segundos se repetirá la alarma?: ");
    scanf("%d", &alarm_interval);

    signal(SIGALRM, sigalrm_handler);

    printf("Alarma activada\n");
    alarm(alarm_interval);

    while (1) {
        // Bucle infinito para mantener el programa en ejecución
        sleep(1);
    }

    return 0;
}
