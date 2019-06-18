

#include <sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include <unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){

  printf("\nComienzo del programa\n");

  pid_t pid;
  int num_pro = 5;
  int estado;

  if(setvbuf(stdout,NULL,_IONBF,0)) { // Desactivamos el buffer para que la salida salga por pantalla y no se comparta el buffer \
                                        con los procesos hijos
  	perror("\nError en setvbuf");
  }

  printf("\nPid del proceso padre = %d\n\n", getpid());

  for(int i = 0; i < num_pro; i++){ // Se crean los 5 procesos hijos
    if((pid = fork()) < 0){
      printf("\nError en la creacion de fork\n");
      exit(-1);
    }
    if(pid == 0){
      printf("\nProceso hijo creado con pid: %d\n", getpid());
      exit(0);
    }
  }

  sleep(5); // Se esperan 5 segundos
  printf("\n\n");

  for(int i = 0; i < num_pro; i++){ // Van finalizando los procesos hijos
      pid = wait(&estado);//espera a todos los hijos
      printf("\nProceso hijo finalizado con pid: %d\n", pid);
      printf("\nMe quedan %d\n", (num_pro - 1 - i));
    }
  }
