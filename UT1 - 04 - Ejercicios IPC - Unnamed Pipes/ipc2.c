#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid > 0) {
        close(pipefd[0]);

        char input[10];
        while (scanf("%s", input) == 1) {
            if (strcmp(input, "+") == 0) {
                break;
            }
            int numero = atoi(input);
            write(pipefd[1], &numero, sizeof(int));
        }

        close(pipefd[1]);
        exit(0);
    } else if (pid == 0) {
        close(pipefd[1]);

        int numero, suma = 0;
        while (read(pipefd[0], &numero, sizeof(int)) > 0) {
            suma += numero;
        }

        printf("La suma total es igual a: %d\n", suma);
        close(pipefd[0]);
    }

    return 0;
}
