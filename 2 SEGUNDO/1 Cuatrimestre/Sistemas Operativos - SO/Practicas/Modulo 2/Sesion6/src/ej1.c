#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h> // PARA STRCMP

/*
  Ejercicio 1 - Practica 6 - Rubén Calvo Villazán

  Ejercicio 1. Implementa un programa que admita t argumentos.
  El primer argumento será una orden de Linux;
  el segundo, uno de los siguientes caracteres “<” o “>”,
  y el tercero el nombre de un archivo (que puede existir o no).
  El programa ejecutará la orden que se especifica como argumento primero
  e implementará la redirección especificada por el segundo argumento hacia
  el archivo indicado en el tercer argumento.
  Por ejemplo, si deseamos redireccionar la entrada estándar
  de sort desde un archivo temporal, ejecutaríamos:

  $> ./mi_programa sort “<” temporal

  Nota. El carácter redirección (<) aparece entre comillas dobles
  para que no los interprete el shell sino que sea aceptado
  como un argumento del programa mi_programa.

*/

int main(int argc, char* argv[]){

  if(argc < 4){
    printf("\nEscribe: ./ej1.c [orden] [< o >] [archivo_temp]\n");
    exit(-1);
  }

  int fd, direccion;
  char* orden = argv[1];
  char* dir = argv[2];
  char* arch = argv[3];
  char* v1 = "<";
  char* v2 = ">";


  /* Comprobamos para seleccionar la direccion correspondiente */

  if(strcmp(dir, v1) == 0){ // Comprobar si es '<'
    direccion = 0;

    if((fd = open(arch, O_RDONLY)) < 0){ // Si es '<' es para leer de archivo, luego se abre con opcion solo de lectura
        perror("\nError en open de archivo\n");
        exit(-1);

    }
  }

  if(strcmp(dir, v2) == 0){ // Comprobar si es '>'
    direccion = 1;

    if((fd = open(arch, O_WRONLY | O_TRUNC | O_CREAT, 0700)) < 0){ // Si es '>' se abre archivo para escritura, si no existe se crea. La opcion '>' borra el contenido -> O_TRUNC
      perror("\nError en open de archivo\n");
      exit(-1);
    }
  }

  close(direccion); 

  if(fcntl(fd, F_DUPFD, direccion) < 0){
    perror("\nFallo en fcntl\n");
    exit(-1);
  }

  if(execlp(orden, orden, NULL) < 0){
    perror("\nError en execpl\n");
    exit(-1);
  }

}
