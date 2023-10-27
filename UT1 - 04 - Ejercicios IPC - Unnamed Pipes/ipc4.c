#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    
    pipe(pipe2);    
    pipe(pipe1);

    pid_t pid = fork();

    if (pid == 0) { // Proceso hijo
        close(pipe1[1]);
        close(pipe2[0]);
        
        int num;
        read(pipe1[0], &num, sizeof(int));
        
        int fact = 1;
        for(int i = 1; i <= num; i++){
            fact *= i;
        }
        
        write(pipe2[1], &fact, sizeof(int));
        close(pipe2[1]);

    } else if (pid > 0) { // Proceso padre
        srand(time(NULL));
        int num = rand() % 10 + 1; // Genera un número entre 1 y 10

        printf("El proceso padre genera el número %d en el pipe1\n", num);
        write(pipe1[1], &num, sizeof(int));
        close(pipe1[1]);

        wait(NULL); // Espera a que el proceso hijo termine

        int fact;
        read(pipe2[0], &fact, sizeof(int));
        
        printf("El factorial es: %d\n", fact);
    }

    return 0;
}
