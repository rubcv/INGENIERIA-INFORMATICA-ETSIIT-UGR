#include <librerias.h>

int main(int argc, char** argv){

  if(argc != 2){
    printf("Escribe %s [ruta-archivo]\n", argv[0]);
    exit(-1);
  }
  char* ruta = argv[1];

  struct stat stats; // Para ver el tamaño
  if(stat(ruta, &stats) < 0){
    perror("Error en stat");
    exit(-1);
  }

  off_t tam = stats.st_size;

  while(1){
    if(stat(ruta, &stats) < 0){
      perror("Error en stat");
      exit(-1);
    }

    if(tam != stats.st_size){
      off_t diferencia = (stats.st_size - tam);
      printf("%10d\n", diferencia);
      tam = stats.st_size;
    }
  }


}
