#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main() {
    // Crear el pipe FIFO2 (si no existe)
    mkfifo(FIFO2, 0666);
    
    int fd2 = open("/tmp/mififo", O_WRONLY);

    int num;

    // Leer el número del pipe FIFO1
    int fd1 = open(FIFO1, O_RDONLY);

    read(fd1, &num, sizeof(int));

    // Calcular el factorial
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    // Escribir el resultado en el pipe FIFO2
    write(fd2, &fact, sizeof(int));

    printf("fifo12: Factorial de %d es %d\n", num, fact);

    // Cerrar los descriptores y eliminar los pipes
    close(fd1);
    close(fd2);
    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}
