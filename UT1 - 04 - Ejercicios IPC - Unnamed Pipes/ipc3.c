#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid > 0) {
    
        close(pipefd[1]);

        int num1, num2;
        read(pipefd[0], &num1, sizeof(int));
        read(pipefd[0], &num2, sizeof(int));

        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        printf("%d / %d = %d\n", num1, num2, num1 / num2);

        close(pipefd[0]);
    } else if (pid == 0) {
    
        close(pipefd[0]);

        srand(time(NULL));
        int num1 = rand() % 50 + 1;
        int num2 = rand() % 50 + 1;

        write(pipefd[1], &num1, sizeof(int));
        write(pipefd[1], &num2, sizeof(int));

        close(pipefd[1]);
    }

    return 0;
}
