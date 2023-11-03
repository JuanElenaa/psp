#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    // Crear el pipe FIFO1 (si no existe)
    mkfifo("FIFO1", 0666);

    int fdw = open("FIFO1", O_WRONLY);

    // Generar un número aleatorio entre 0 y 10
    srand(time(NULL));
    int num = rand() % 11;

    printf("Número aleatorio generado: %d\n", num);

    // Escribir el número en el pipe FIFO1
    write(fdw, &num, sizeof(int));

    // Cerrar el descriptor de escritura
    close(fdw);

    // Abro el FIFO1 en modo lectura
    int fdr = open("FIFO1", O_RDONLY);

    int fact;
    // Leer el resultado del pipe FIFO1
    read(fdr, &fact, sizeof(int));
    printf("Factorial de %d es %d\n", num, fact);

    // Cerrar el descriptor
    close(fdr);
    unlink("FIFO1"); 
    
    return 0;
}
