#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t P1, P2, P3, P4, P5, P6;
    // Proceso P1
    P1 = getpid();
    printf("P1 (PID=%d, PPID=%d)\n", getpid(), getppid());

    // Crear proceso P2
    P2 = fork();

    if (P2 == -1) {
        perror("Error al crear el proceso P2");
        exit(1);
    }
    if (P2 == 0) {
        // Proceso P2
        printf("P2 (PID=%d, PPID=%d)\n", getpid(), getppid());

        // Crear proceso P3
        P3 = fork();

        if (P3 == -1) {
            perror("Error al crear el proceso P3");
            exit(1);
        }
        if (P3 == 0) {
            wait(NULL);
            // Proceso P3
            printf("P3 (PID=%d, PPID=%d)\n", getpid(), getppid());

            // Crear proceso P5
            P5 = fork();

            if (P5 == -1) {
                perror("Error al crear el proceso P5");
                exit(1);
            }
            if (P5 == 0) {
            wait(NULL);
                // Proceso P5
                printf("P5 (PID=%d, PPID=%d)\n", getpid(), getppid());
                exit(0);
            } else {
                wait(NULL); // Espera a que P5 termine antes de continuar
            }

            exit(0);
        } else {
            wait(NULL); // Espera a que P3 termine antes de continuar

            // Crear proceso P4
            P4 = fork();

            if (P4 == -1) {
                perror("Error al crear el proceso P4");
                exit(1);
            }
            if (P4 == 0) {
            	wait(NULL);
                // Proceso P4
                printf("P4 (PID=%d, PPID=%d)\n", getpid(), getppid());

                // Crear proceso P6
                P6 = fork();

                if (P6 == -1) {
                    perror("Error al crear el proceso P6");
                    exit(1);
                }
                if (P6 == 0) {
                	wait(NULL);
                    // Proceso P6
                    printf("P6 (PID=%d, PPID=%d)\n", getpid(), getppid());
                    exit(0);
                } else {
                    wait(NULL); // Espera a que P6 termine antes de continuar
                }

                exit(0);
            } else {
                wait(NULL); // Espera a que P4 termine antes de continuar
            }
            
            exit(0);
        }
    } else {
        wait(NULL); // Espera a que P2 termine antes de continuar
    }

    return 0;
}
