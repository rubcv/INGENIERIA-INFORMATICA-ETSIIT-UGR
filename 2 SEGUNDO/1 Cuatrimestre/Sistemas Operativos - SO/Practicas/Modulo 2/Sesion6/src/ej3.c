#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

/*
  Ejercicio 3 - Sesion 6 - Rubén Calvo Villazán

Ejercicio 3. Construir un programa que verifique que,
efectivamente, el kernel comprueba que puede
darse una situación de interbloqueo en el bloqueo de archivos.
*/



int main(int argc, char* argv[]){

  struct flock cerrojo; // Declaracion del cerrojo
  int fd;

  if(argc < 2){
    printf("\nEscribe ./ej3 [nombre_archivo]\n");
    exit(-1);
  }

  char* arch = argv[1];
  char* tecla;

  if((fd = open(arch, O_RDWR)) < 0){ // De lectura y escritura
    perror("\nError en apertura de archivo\n");
    exit(-1);
  }

  /* Creacion del struct cerrojo */

  cerrojo.l_type = F_WRLCK; // De escritura
  cerrojo.l_whence = SEEK_SET; // De donde
  cerrojo.l_start = 0;
  cerrojo.l_len = 0;


  if((fcntl(fd, F_SETLKW, &cerrojo)) < 0){
    perror("\nInterbloqueo detectado\n");
    //exit(-1);
  }

  printf("\nCerrojo puesto, pulse una tecla\n");
  scanf("%s", tecla);


  sleep(1);

  // Desbloqueo
  cerrojo.l_type=F_UNLCK;
  cerrojo.l_whence=SEEK_SET;
  cerrojo.l_start=0;
  cerrojo.l_len=0;

  if(fcntl(fd, F_SETLKW, &cerrojo) < 0){
     perror ("\nDesbloqueo\n");
   }

}
