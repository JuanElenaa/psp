#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t P1, P2, P3, P4;

    // Soy P1
    P1 = getpid();
    
    if (getpid() % 2 == 0) {
        printf("Soy el proceso P1. PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        printf("Soy el proceso P1. PID = %d\n", getpid());
    }
    
    // Crear P2
    P2 = fork();

    if (P2 == -1) {
        perror("Error al crear el proceso P2");
        exit(1);
    }
    
    if (P2 == 0) { // Proceso P2
      	if (getpid() % 2 == 0) {
        	printf("Soy el proceso P2. PID = %d, PPID = %d\n", getpid(), getppid());
    	} else {
        	printf("Soy el proceso P2. PID = %d\n", getpid());
    	}
    	
    } else { // P1 espera a que P2 termine
    
    	wait(NULL);
    	
    	// Crear P3
    	P3 = fork();
    	
    	if (P3 == -1) {
      		perror("Error al crear el proceso P3");
      		exit(1);
    	}
    	
    	if (P3 == 0) { // Proceso P3
      		if (getpid() % 2 == 0) {
        		printf("Soy el proceso P3. PID = %d, PPID = %d\n", getpid(), getppid());
    		} else {
        		printf("Soy el proceso P3. PID = %d\n", getpid());
    		}
    		
    		// Crear P4
    		P4 = fork();
    		
    		if (P4 == -1) {
    			perror("Error al crear el proceso P4");
      			exit(1);
    		}
    		
    		if (P4 == 0) { // Proceso P4
    			if (getpid() % 2 == 0) {
        			printf("Soy el proceso P4. PID = %d, PPID = %d\n", getpid(), getppid());
    			} else {
        			printf("Soy el proceso P4. PID = %d\n", getpid());
    			}
    		
    		} else { // P3 espera a que P4 termine
      			wait(NULL); 
      			exit(0);
    		}
    		
      	exit(0);
      	} else { // P1 espera a que P3 termine
      		wait(NULL); 
      		exit(0);
    	}
    }
    return 0;
}
