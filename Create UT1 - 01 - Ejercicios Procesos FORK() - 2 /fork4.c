#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t P1, P2, P3, P4, P5;

    P1 = getpid();
    int acumulado = P1;
    int acumulado1; // Variable local para el proceso P2
    printf("P1 PID=%d\n", P1);

    P2 = fork();

    if (P2 == -1) {
        perror("Error al crear el proceso P2");
        exit(1);
    }

    if (P2 == 0) {
        // Proceso P2
        printf("P2 (PID=%d, PPID=%d)\n", getpid(), getppid());
        if (getpid() % 2 == 0) {
            acumulado += 10;
        } else {
            acumulado -= 100;
        }
        printf("acumulado = %d\n", acumulado);

        P5 = fork();

        if (P5 == -1) {
            perror("Error al crear el proceso P5");
            exit(1);
        }

        if (P5 == 0) {
            // Proceso P5
            printf("P5 (PID=%d, PPID=%d)\n", getpid(), getppid());
            if (getpid() % 2 == 0) {
                acumulado += 10;
            } else {
                acumulado -= 100;
            }
            printf("acumulado = %d\n", acumulado);
            
        } else {
            wait(NULL);
        }
        
        
    } else {
        wait(NULL);
        P3 = fork();

        if (P3 == -1) {
            perror("Error al crear el proceso P3");
            exit(1);
        }

        if (P3 == 0) {
            // Proceso P3
            printf("P3 (PID=%d, PPID=%d)\n", getpid(), getppid());
            if (getpid() % 2 == 0) {
                acumulado += 10;
            } else {
                acumulado -= 100;
            }
            printf("acumulado = %d\n", acumulado);

            P4 = fork();

            if (P4 == -1) {
                perror("Error al crear el proceso P4");
                exit(1);
            }

            if (P4 == 0) {
                // Proceso P4
                printf("P4 (PID=%d, PPID=%d)\n", getpid(), getppid());
                if (getpid() % 2 == 0) {
                    acumulado += 10;
                } else {
                    acumulado -= 100;
                }
                printf("acumulado = %d\n", acumulado);
            } else {
                wait(NULL);
            }
        } else {
            wait(NULL);
        }
    }

    return 0;
}

