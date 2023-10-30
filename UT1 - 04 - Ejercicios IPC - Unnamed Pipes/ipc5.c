#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    char letra[2];
    char buffer[2];
    
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();

    if (pid == 0) { // Proceso hijo P2
        close(pipe1[0]);
        close(pipe2[1]);

        int dni;
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);

        write(pipe1[1], &dni, sizeof(int));
        
        
        read(pipe2[0], buffer, sizeof(char));

        printf("La letra del NIF es %s\n", buffer);

    } else if (pid > 0) { // Proceso padre P1
    	int dni;
        close(pipe1[1]);
        close(pipe2[0]);

        
        read(pipe1[0], &dni, sizeof(int));
        
        dni %= 23;

        letra[0] = letras[dni];
        
        write(pipe2[1], &letra, sizeof(char));

        wait(NULL); // Espera a que el proceso hijo termine
    }
    return 0;
}
