

#include <sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include <unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
  if(argc != 2){
    printf("\nEscribe ./ej1 [num entero])\n");
    exit(-1);
  }

  int num = *argv[1];
  pid_t pid;

  if(setvbuf(stdout,NULL,_IONBF,0)) {
  	perror("\nError en setvbuf");
  }

  if((pid = fork()) < 0){
    printf("\nError en el fork\n");
    exit(-1);
  }

  if(pid == 0){
    printf("\nComprobacion del proceso hijo\n");
    if(num % 2 == 0){
      printf("\nNumero par\n");
    }else{
      printf("\nNumero impar\n");
    }
  }else{
    printf("\nComprobacion del proceso padre\n");
    if(num % 4 == 0){
      printf("\nNumero divisible por 4\n");
    }else{
      printf("\nNumero no divisible por 4\n");
    }
  }
}
