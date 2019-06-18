#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // fcntl
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> // strcmp
#include <dirent.h> // PARA DIR*

int main(int argc, char* argv[]){
  if(argc < 2){
    perror("\nEscribe ./ej2 [nombre_dir]\n");
    exit(-1);
  }

  char* dir = argv[1];

  DIR* carpetano;
  struct dirent* entrada;

  if(!(carpetano = opendir(dir))){
    perror("\nError en apretura de directorio\n");
    exit(-1);
  }

  while((entrada = readdir(carpetano)) != NULL){ // Struct dirent apunta a directorio y DIR* va apuntando al contenido
  //  printf("%s", entrada->d_name); // Imprimir nombre de archivo

    char ruta[512]; // Para guardar la ruta

                // dir/archivo      //nombre
    sprintf(ruta, "%s/%s", dir, entrada->d_name); // Carga la ruta en 'ruta'

    struct stat stats; // Struct stat

      stat(ruta, &stats); // Aplica el stat en ruta

      if(S_ISREG(stats.st_mode)){ // Comprueba que sea un archivo regular

        printf("\n%s es archivo regular\n", entrada->d_name); // Imprime el nombre del archivo y si es regular
        printf("Permisos anteriores: %o \n",stats.st_mode);

        int perm;
        if((perm = chmod(ruta, 0777)) == 0){  // Le das los permisos a los archivos de la ruta
          printf("Permisos posteriores: %o \n",stats.st_mode);
        }
      }


  }
}

/* Modificar para que añada (sin quitar) lectura a otros */
