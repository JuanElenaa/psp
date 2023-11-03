#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Crear el pipe FIFO2 (si no existe)
    mkfifo("FIFO2", 0666);

    int num;

    // Leer el número del pipe FIFO1
    int fd1 = open("FIFO1", O_RDONLY);
    
    read(fd1, &num, sizeof(int));
    
    // Calcular el factorial
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    
    // Abro el segundo FIFO en modo escritura
    int fd2 = open("FIFO2", O_WRONLY);

    // Escribir el resultado en el pipe FIFO2
    write(fd2, &fact, sizeof(int));

    

    // Cerrar los descriptores
    close(fd1);
    close(fd2);
    unlink("FIFO1");
    unlink("FIFO2");

    return 0;
}
