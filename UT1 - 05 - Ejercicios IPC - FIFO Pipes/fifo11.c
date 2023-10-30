#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main() {
    // Crear el pipe FIFO1 (si no existe)
    mkfifo(FIFO1, 0666);
    
    int fd1 = open("/tmp/mififo", O_WRONLY);

    // Generar un número aleatorio entre 0 y 10
    srand(time(NULL));
    int num = rand() % 11;

    printf("fifo11: Número aleatorio generado: %d\n", num);

    // Escribir el número en el pipe FIFO1
    write(fd1, &num, sizeof(int));

    // Cerrar el descriptor y eliminar el pipe
    close(fd1);
    unlink(FIFO1);

    return 0;
}
