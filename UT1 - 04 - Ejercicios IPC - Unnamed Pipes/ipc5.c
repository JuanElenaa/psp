#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();

    if (pid == 0) { // Proceso hijo P2
        close(pipe1[1]);
        close(pipe2[0]);

        int dni;
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);

        write(pipe1[0], &dni, sizeof(int));
        
        char letra;
        read(pipe2[0], &letra, sizeof(char));

        printf("La letra del NIF es %c\n", letra);

    } else if (pid > 0) { // Proceso padre P1
        close(pipe1[0]);
        close(pipe2[1]);

        int dni;
        read(pipe1[1], &dni, sizeof(int));

        char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letra = letras[dni % 23];
        
        write(pipe2[0], &letra, sizeof(char));

        wait(NULL); // Espera a que el proceso hijo termine
    }

    return 0;
}
