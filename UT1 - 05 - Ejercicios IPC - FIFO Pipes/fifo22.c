#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int num;

    // Leer el número del pipe FIFO1
    int fdr = open("FIFO1", O_RDONLY);
    read(fdr, &num, sizeof(int));

    // Calcular el factorial
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    // Cerrar el descriptor de lectura
    close(fdr);

    // Abro el FIFO1 en modo escritura
    int fdw = open("FIFO1", O_WRONLY);

    // Escribir el resultado en el pipe FIFO1
    write(fdw, &fact, sizeof(int));

    // Cerrar el descriptor
    close(fdw);
    unlink("FIFO1"); 
    return 0;
}
