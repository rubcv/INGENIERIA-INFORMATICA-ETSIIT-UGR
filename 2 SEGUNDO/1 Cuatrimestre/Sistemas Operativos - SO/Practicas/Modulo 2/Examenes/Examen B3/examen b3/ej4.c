#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

if(argc < 3 ){
  perror("Faltan argumentos");
  exit(-1);
}
int fd;
  if(mkfifo(datos,S_IUSR|S_IWUSR)<0){
    perror("ERROR al crear el fifo");
    exit(-1);
  }
  fd=open("datos",O_RDONLY);
  if ((pid=fork())<0){
    perror("ERROR al crear el hijo");
    exit(-1);
  }
  char cad[11];
  else{
    if(pid == 0){ //un hijo
      dup2(fd,STDOUT_FILENO);
      execl("./ej1.c","./ej1.c",argv[1],NULL);
      perror("Fallo en exec");
      exit(-1);
    }
  }
  if((pid=fork())<0){
    perror("Error al crear el hijo");
    exit(-1);
  }
  else{
    if(pid == 0){
      dup2(fd,STDOU_FILENO);
      execl("./ej1","./ej1",argv[2],NULL);
      perror("sd");
      exit(-1);
    }
    while(read(fd,cad,sizeof(char)*11 >0))
        printf("leido %s \n" ,cad )
  }
  kill(pid,SIGKILL); //matariamos a ambos hijos.
  close(fd); //cerramo fifo
  //ej5:evitemos que queden zombis: (wait siempre despues que close (creo))
  wait(NULL);
  wait(NULL);
  

}
