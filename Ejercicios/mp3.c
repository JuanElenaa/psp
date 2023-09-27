#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	pid_t pid, pid2;
	
	//Creo un proceso hijo
	pid = fork();
	
	if(pid == 0){
	
		sleep(30);
		printf("Despierto");
		
  	} else {
  	
  		wait(NULL);
  		pid2 = fork();
  		
  		if(pid2 == 0){
  			printf("Soy el proceso P3. mi pid es = %d, el pid de mi padre es = %d\n", getpid(), getppid()); 		
  		}else{
  			wait(NULL);
  		}
  	}
	return 0;
}
