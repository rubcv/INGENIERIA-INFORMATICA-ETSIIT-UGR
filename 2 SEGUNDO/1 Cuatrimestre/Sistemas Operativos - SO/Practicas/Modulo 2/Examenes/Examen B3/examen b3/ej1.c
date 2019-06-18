/**/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
  if(argc < 2){
    perror("Faltan cosas");
    exit(-1);
  }
  struct stat att;
  int prueba,dif;
  off_t tamactual;
  prueba=stat(argv[1],&att);
  if(prueba < 0){
    perror("Error en stat");
    exit(-1);
  }
  tamactual=att.st_size;
  while(1){
    prueba=stat(argv[1],&att);
    if(prueba < 0){
      perror("Error en stat");
      exit(-1);
    }

    if(tamactual!= att.st_size){
      dif=att.st_size - tamactual;
      printf("DISTINTOS %d\n",dif);
      tamactual=att.st_size;
    }
  }
}
