#include <librerias.h>

int main(int argc, char** argv){
  if(argc != 2){
    printf("Escribe: %s [ruta-archivoregular]\n", argv[0]);
    exit(1);
  }

  char* ruta = argv[1];
  struct stat stats;

  if(stat(ruta, &stats) < 0){
    perror("Error aplicando stats\n");
    exit(1);
  }


  off_t tam = stats.st_size;

  while(1){
    if(stat(ruta, &stats) < 0){
      perror("Error aplicando stats\n");
      exit(1);
    }

    off_t tamNuevo = stats.st_size;
    if(tam != tamNuevo){
      off_t diferencia = tamNuevo - tam;
      printf("%10d\n", diferencia);
      tam = tamNuevo;
    }
  }
}
