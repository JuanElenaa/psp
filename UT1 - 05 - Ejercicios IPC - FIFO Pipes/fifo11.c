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
    
    int fd1 = open("FIFO1", O_WRONLY);

    // Generar un número aleatorio entre 0 y 10
    srand(time(NULL));
    int num = rand() % 11;

    printf("fifo11: Número aleatorio generado: %d\n", num);

    // Escribir el número en el pipe FIFO1
    write(fd1, &num, sizeof(int));
    
    int fact;
    
    // Abro el segundo FIFO en modo escritura
    int fd2 = open("FIFO2", O_RDONLY);

    // Escribir el resultado en el pipe FIFO2
    read(fd2, &fact, sizeof(int));
    printf("fifo12: Factorial de %d es %d\n", num, fact);
    

    // Cerrar el descriptor
    close(fd1);
    close(fd2);
    

    return 0;
}
