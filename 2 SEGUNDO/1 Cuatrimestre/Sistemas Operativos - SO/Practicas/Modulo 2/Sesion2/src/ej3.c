/*
  Ejercicio 3

  Rubén Calvo Villazán - 76065313

*/


#include <unistd.h>  /* POSIX Standard: 2.10 Symbolic Constants <unistd.h>		                    */
#include <stdlib.h>
#include <sys/types.h>  /* Primitive system data types for abstraction of implementation-dependent data types.     \
		                      POSIX Standard: 2.6 Primitive System Data Types     <sys/types.h>  */
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>


int funcionAux(char *direct){

    DIR *pDir;
    struct dirent *pDirent;
    int fd;
    int tam = 0;
    struct stat atributos;

    pDir = opendir(direct); // Abrimos el directorio
    char* indice;
    chdir(direct); // Cambiamos al directorio
    pDirent = readdir(pDir); // Leemos el directorio


    while(pDirent != NULL) { // Mientras no sea nulo
      if(stat(pDirent->d_name, &atributos) < 0) { // Guardamos los atributos
        printf("\nFallo al leer los atributos\n");
        exit(-1);
      }

      if(S_ISDIR(atributos.st_mode)){ // Si es un directorio llamamos a la funcion de forma recursiva
        tam += funcionAux(pDirent->d_name);
        chdir(" .."); // Volvemos al directorio anterior
      }else if((atributos.st_mode & S_IXGRP) && (atributos.st_mode & S_IXOTH)){
				printf("%s ", pDirent->d_name);
        printf("%d \n", (int)atributos.st_ino);
        tam += (int)atributos.st_size;
      }
      pDirent = readdir(pDir); // Abrimos el archivo siguiente
    }

    if(closedir(pDir) < 0){ // Cerramos el directorio
      printf("\nFallo al cerrar el directorio\n");
      exit(-1);
    }
    return tam; // Devolvemos tamaño total
}




int main(int argc, char* argv[]){

    if(argc < 2){
      printf("Escribe ./ej3 [directorio]");
      exit(-1);
    }
    printf("%d\n", funcionAux( argv[1] ));
}
