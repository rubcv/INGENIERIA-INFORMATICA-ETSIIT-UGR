// --------------------------------------------------
//   Practica 7 - Rubén Calvo Villazán
//             servidor.c
// --------------------------------------------------


#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define tamano 1024
#define longnombre 50

static void funcion(int sigNum){ // Al handler se le debe pasar un entero aunque no se use
  char fProxy[longnombre];

  pid_t pid;
  pid = wait(NULL);
}


int main(int argc, char** argv){

  char fifoc[longnombre];
  char fifos[longnombre];
  char fProxy[longnombre];
  int fdCliente, fdServidor, fdBloq, lectura, tmp, pidproxy, fifo;
  pid_t pid;


   if(argc != 2) {
     printf("Escribe: %s [%s]\n", argv[0], "nombre fifo");
     exit(-1);
   }


  signal(SIGCHLD, funcion);

  sprintf(fifos, "%ss", argv[1]);
  sprintf(fifoc, "%se", argv[1]);
  umask(0);

  mkfifo(fifoc, 0666);
  mkfifo(fifos, 0666);


  if((fdServidor = open(fifos, O_RDWR)) < 0){
    perror("\nError abriendo fifo del servidor.");
    exit(-1);
  }


  if((fdCliente = open(fifoc, O_RDWR)) < 0){
    perror("\nError abriendo fifo del cliente.");
    exit(-1);
  }


  umask(0); // Hacemos umask
  if((fdBloq = open("bloqueo", O_CREAT, 0666)) < 0){
    printf("\nError al crear el archivo de bloqueo.");
    exit(-1);
  }

   while((lectura = read(fdCliente, &tmp, sizeof(int))) != 0){
     pid = fork(); // Creamos el hijo

     if(pid == 0){ // El hijo
       pidproxy = getpid();
       sprintf(fProxy, "fifo.%d", pidproxy);

       umask(0); // Volvemos a hacer umask
       mkfifo(fProxy, 0666); // Crear fifo
       write(fdServidor, &pidproxy, sizeof(int)); // Escribir
       fifo = open(fProxy, O_RDONLY);
       dup2(fifo, STDIN_FILENO); // fifo == STDIN_FILENO
       execlp("./proxy", "proxy", NULL); // exec proxy
       exit(0);
     }
   }
}
