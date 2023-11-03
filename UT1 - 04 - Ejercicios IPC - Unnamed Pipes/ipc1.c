#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[30];
     pid_t pid;

     // Crep el pipe
     pipe(fd); 

     //Se crea un proceso hijo
     pid = fork();

     if (pid==0) {
                close(fd[1]); // Cierra el descriptor de escritura
                printf("Soy el proceso hijo con pid %d \n",getpid());
                read(fd[0], buffer, 40);

                printf("\t Mensaje leido del pipe: %s \n", buffer);

     } else {
                close(fd[0]); // Cierra el descriptor de lectura
                write(fd[1], "Fecha/hora: Mon Oct 10 18:38:39 2022", 40);
                wait(NULL);
     }
}
