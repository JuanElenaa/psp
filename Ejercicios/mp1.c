#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid == 0) { // Proceso hijo
        printf("Juan Elena Sánchez\n");
    } else { // Proceso padre
        wait(NULL); // Espera al proceso hijo
        printf("Soy el proceso padre. PADRE = %d, HIJO = %d\n", 		getpid(), pid);
    }
	return(0);
}
