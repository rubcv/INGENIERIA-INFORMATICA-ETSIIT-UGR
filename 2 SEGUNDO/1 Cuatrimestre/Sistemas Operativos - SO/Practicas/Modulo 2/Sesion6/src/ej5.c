#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

/*
  Ejercicio 5 - Práctica 6 - Rubén Calvo Villazán

  Ejercicio 5: Escribir un programa, similar a la orden cp, que utilice
  para su implementación la llamada al sistema mmap() y una función de
  C que nos permite copiar memoria, como por ejemplo memcpy(). Para
  conocer el tamaño del archivo origen podemos utilizar stat() y para
  establecer el tamaño del archivo destino se puede usar ftruncate().
  */

int main(int argc, char* argv[]){

  if(argc < 3){ // cp [arch1] [arch2] -> se piden los archivos, el cp va implicito
    printf("\nEscribe ./ej5 [arch1] [arch2]\n");
    exit(-1);
  }

    struct stat stats; // Atributos de archivo
    int fd1, fd2;
    char* arch1 = argv[1];
    char* arch2 = argv[2];

    umask(0); // Ponemos mask 0

    if((fd1 = open(arch1, O_RDONLY)) < 0){
      perror("\nError en apertura de archivo 1\n");
      exit(-1);
    }

    umask(0);

    if((fd2 = open(arch2, O_WRONLY | O_CREAT | O_TRUNC, 0700)) < 0){
      perror("\nError en apertura/creacion de archivo 2\n");
      exit(-1);
    }


    // Accedemos al stat del primer archivo

    if(stat(arch1, &stats) < 0){
      printf("\nError al acceder a stat del primer archivo\n");
      exit(-1);
    }

    int tam = stats.st_size; // Guardamos el tamaño del archivo

    ftruncate(fd2, tam); // Trunca tamaño

    char* aux1, *aux2;

    if((aux1 = (char*)mmap(0, tam, PROT_READ, MAP_SHARED, fd1, 0)) == MAP_FAILED){
      perror("\nFallo en mmap 1\n");
      exit(-1);
    }

    if((aux2 = (char*)mmap(0, tam, PROT_WRITE, MAP_SHARED, fd2, 0)) == MAP_FAILED){
      perror("\nFallo en mmap 2\n");
      exit(-1);
    }

    // Copiamos archivo

    memcpy(aux2, aux1, tam);

    // Faltan los unmap (Cerrar los mmap)

    if(munmap(aux1, tam) < 0){
      printf("\nError en primer unmap\n");
      exit(-1);
    }

    if(munmap(aux2, tam) < 0){
      printf("\nError en segundo unmap\n");
      exit(-1);
    }




}
