#include <librerias.h>

int suma = 0;
int estado;
void noZombis(int n){
  wait(&estado);
  printf("Hijo terminado, estado: %d\n", estado);
  printf("Valor de la suma: %d\n", suma);
}

int main(int argc, char** argv){
  if(argc != 2){
    printf("Escribe %s [ruta-dir]\n", argv[0]);
    exit(1);
  }

  char* dir = argv[1];
  DIR* carpeta;
  struct dirent* entrada;
  int fd[2];
  pipe(fd);


  if(!(carpeta = opendir(dir))){
    perror("Error abriendo el directorio\n");
    exit(1);
  }

  while((entrada = readdir(carpeta)) != NULL){
    char ruta[512];
    sprintf(ruta, "%s/%s", dir, entrada->d_name);

    struct stat stats;
    stat(ruta, &stats);
    if(S_ISREG(stats.st_mode)){ // Para cada archivo regular

      pid_t pid;
      if((pid = fork()) < 0){
        perror("Error en el fork\n");
        exit(1);
      }else if(pid == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);

        execl("./chequeoarchivoPIPE", "./chequeoarchivoPIPE", ruta, NULL);
        perror("Error en el execl\n");
        exit(1);
      }
    }
  }

}
