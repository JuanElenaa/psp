a) 1000 (mp4)
   |
   └── 1001 (AAA)
         |
         ├── 1002 (BBB)
         └── 1003 (CCC)
         └── 1004 (CCC)
    
   1000 (mp4)
   |
   └── 1001 (AAA)
         |
         └── 1002 (BBB)
              └── 1003 (CCC)







b)  Podría producirse otra salida ya que el proceso hijo no espera al padre en ningún momento, por tanto la salida podría cambiar






c) 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0) {
 	printf("BBB \n");
 }
 else {
 	wait(NULL);
 	pid2 = fork();
 	if(pid2 == 0){
 		printf("CCC \n");
 	}else{
 		wait(NULL);
 	}
 	
 }
 exit(0);
}
