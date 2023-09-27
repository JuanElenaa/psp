#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid_abuelo, pid_padre, pid_nieto;
  
  //SOY EL ABUELO
  pid_padre = fork();
  
  if(pid_padre == -1){
    perror("Error al crear el proceso hijo (padre)");
    exit(1);
  }
  
  if(pid_padre == 0){ // Proceso hijo (padre)
    pid_nieto = fork();
    
    if(pid_nieto == -1){
      perror("Error al crear el proceso nieto");
      exit(1);
    }
    
    if(pid_nieto == 0){ // Proceso nieto
      printf("Soy el proceso nieto. NIETO = %d, PADRE = %d\n", getpid(), getppid());
      exit(0);
    }
    else{
      wait(NULL); // Espera al proceso nieto
      printf("Soy el proceso padre. PADRE = %d, ABUELO = %d\n", getpid(), getppid());
      exit(0);
    }
  }
  else{ // Proceso abuelo
    wait(NULL); // Espera al proceso padre
    printf("Soy el proceso abuelo. ABUELO = %d\n", getpid());
  }
  
  return 0;
}
