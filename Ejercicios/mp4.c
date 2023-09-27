a)
1000 (mp4)
   |
   └── 1001 (CCC)
         |
         ├── 1002 (AAA)
         └── 1003 (BBB)


1000 (mp4)
   |
   └── 1001 (CCC)
         |
         ├── 1002 (BBB)
         └── 1003 (AAA)

     

b) Podría producirse otra salida ya que el proceso hijo no espera al padre en ningún momento, por tanto la salida podría cambiar




c) El código modificado para que salga CCC, BBB, AAA es:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {

	printf("CCC \n");
	
	if (fork()!=0){
		wait(NULL);
 		printf("AAA \n");
 		
 	}else{
 		printf("BBB \n");
 	}
 	
 	exit(0);
}
