/*
Ejercicio2.c Rubén Calvo Villazán
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
*/

#include <unistd.h>  /* POSIX Standard: 2.10 Symbolic Constants <unistd.h>		                    */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  /* Primitive system data types for abstraction of implementation-dependent data types.     \
		                      POSIX Standard: 2.6 Primitive System Data Types     <sys/types.h>  */
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

bool LecturaYEscritura(char* nombre){
  bool exito = true;
  int fd;
  int salida;
  const int TAM = 80;
  int tam = 10;
  int tamNumBloques = 27;
  char lectura[TAM];
  int i = 1;
  char numbloques[tamNumBloques];

  if((fd = open(nombre,O_RDWR | O_CREAT, 0700))<0) { //  Abrimos el archivo de la ruta "nombre"
      printf("\nError en apertura del archivo\n");
      exit(-1);
  }
  if((salida = open("salida.txt",O_RDWR | O_CREAT, 0700))<0) { // Abrimos o creamos el archivo salida en caso de que no exista
      printf("\nError en apertura del archivo de salida\n");
      exit(-1);
  }

  //---------------------------------------------------------------------------------------------
  while(read(fd, lectura, TAM) > 0) { // Leemos el archivo en bloques de 80 bytes y lo almacenamos en el vector de char lectura
      char bloques[tam];
      sprintf(bloques, "\nBloque %i\n", i); //Guardamos en bloques el texto con el numero de bloque
      if(write(salida,bloques,tam) == -1) { // Escribimos el numero de bloque en salida.txt
          printf("\nError en write");
          exit(-1);
      }
      if(write(salida, lectura, TAM) == -1) { // Escribimos la lectura en salida.txt
          printf("\nError en write");
          exit(-1);
      }

      if(i >= 10 && i < 100){ // Modificamos tam para que quepan mas numeros de bloque
        tam = 11;
      }
      if(i >= 100){
        tam = 12;
      }
      i++; //Contamos los bloques
  }

if(lseek(salida, 0, SEEK_SET)<0){ // Movemos la escritura al principio de salida.txt para poner el numero de bloques
  printf("\nError en lseek");
  exit(-1);
  }

  sprintf(numbloques, "\nEl numerode bloques es %i\n", (i - 1)); // En numbloques guardamos el numero de bloques
  if(write(salida, numbloques, tamNumBloques) <0) { // Escribimos el numero de bloques al principio de salida.txt
    perror("\nError en write");
      exit(-1);
  }
    close(fd); // Cerramos los archivos
    close(salida);
  return exito;
}

int main(int argc, char* argv[]){

  char* nombre;

    if(argc < 2){
      if(isatty(fileno(stdin))){ // Usamos esta funcion para comprobar si se lee por tuberia o por terminal
        fprintf(stdout, "\nLeyendo de terminal, introduce la ruta del archivo\n");
        char aux[999];
        scanf("%s", aux);
        nombre = aux;

        if(LecturaYEscritura(nombre)){
          printf("\nExito\n");
        }else{
          printf("\nError en la operacion\n");
        }
      }else{
        fprintf(stdout, "\nLeido de tuberia\n");
        int pos = 0;
        char estado[1];
        int salida;
        const int TAM = 80;
        int tam = 10;
        int tamNumBloques = 27;
        char lectura[TAM];
        int i = 1;
        char numbloques[tamNumBloques];

        if((salida = open("salida.txt",O_RDWR | O_CREAT, 0700))<0) { // Abrimos o creamos el archivo salida en caso de que no exista
            printf("\nError en apertura del archivo de salida\n");
            exit(-1);
        }

        while((estado[0] = getchar()) != -1){
          while((pos < TAM) && ((lectura[pos] = getchar()) != -1)){ // Hacemos la lectura
            pos++;
          }
            char bloques[tam];
            sprintf(bloques, "\nBloque %i\n", i); //Guardamos en bloques el texto con el numero de bloque
            if(write(salida,bloques,tam) == -1) { // Escribimos el numero de bloque en salida.txt
                printf("\nError en write");
                exit(-1);
            }
            if(write(salida, lectura, TAM) == -1) { // Escribimos la lectura en salida.txt
                printf("\nError en write");
                exit(-1);
            }

            if(i >= 10 && i < 100){ // Modificamos tam para que quepan mas numeros de bloque
              tam = 11;
            }
            if(i >= 100){
              tam = 12;
            }
            i++; //Contamos los bloques
            pos = 0; // Volvemos a leer
        }

        if(lseek(salida, 0, SEEK_SET)<0){ // Movemos la escritura al principio de salida.txt para poner el numero de bloques
          printf("\nError en lseek");
          exit(-1);
          }

          sprintf(numbloques, "\nEl numerode bloques es %i\n", (i - 1)); // En numbloques guardamos el numero de bloques
          if(write(salida, numbloques, tamNumBloques) <0) { // Escribimos el numero de bloques al principio de salida.txt
            perror("\nError en write");
              exit(-1);
          }
            // Cerramos los archivos
            close(salida);
              printf("\nExito\n");

      }

    }else{
      for(int i = 1; i < argc; i++){
        nombre = argv[i];
        if(LecturaYEscritura(nombre)){
          printf("Exito\n");
        }else{
          printf("Error en la operacion\n");
        }
      }
    }
}
