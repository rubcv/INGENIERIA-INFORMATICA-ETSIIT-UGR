// --------------------------------------------------
//   Practica 7 - Rubén Calvo Villazán
//                proxy.c
// --------------------------------------------------


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <librerias.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define TAM 1024
#define longnombre 50

void opcionBloqueo (int bloqueo, int op) {
  struct flock cerrojo;
    cerrojo.l_type = op;
    cerrojo.l_whence = SEEK_SET;
    cerrojo.l_start = 0;
    cerrojo.l_len = 0;

   if(fcntl(bloqueo, F_SETLKW, &cerrojo) < 0){ // Duerme si ya esta bloqueado
      perror ("PROXY: Fallo al bloquear");
      exit(1);
    }
}

int main(int argc, char** argv){
  char buffer[TAM];
  int nBytes, bloqueo;
  FILE* tmp = tmpfile();
  char proxyfifo[256];


  while((nBytes = read(STDIN_FILENO, buffer, TAM)) > 0){
    fwrite(buffer, sizeof(char), nBytes, tmp);
  }

  if ((bloqueo = open("bloqueo", O_RDWR)) < 0){
    printf("Error al abrir el archivo de bloqueo\n");
    exit(-1);
  }

  opcionBloqueo(bloqueo, F_WRLCK);

  while(!feof(tmp)){
    fread(buffer, sizeof(char), TAM, tmp);
    write(STDOUT_FILENO, buffer, TAM);
  }

  opcionBloqueo(bloqueo, F_UNLCK);
  sprintf(proxyfifo, "fifo.%d", getpid());
  unlink(proxyfifo);
  exit(0);
}
