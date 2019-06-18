#include <librerias.h>


int estado;
void noZombis(int n){
  wait(&estado);
  printf("Hijo finalizado con estado: %d\n", estado);
}

int main(int argc, char** argv){
  if(argc != 2){
    printf("Escribe: %s [archivo-salida-errores]\n", argv[0]);
    exit(1);
  }

  struct sigaction sa;
  sa.sa_handler = noZombis;
  sigaction(SIGCHLD, &sa, NULL);

  char* errores = argv[1];
  char* error;
  int fd;
  int fdp[2];

  pipe(fdp); // Comunicamos padre-hijo con pipe

  if((fd = open(errores, O_RDONLY | O_TRUNC | O_CREAT, 0700)) < 0){
    printf("Error creando archivo de errores\n");
    exit(1);
  }

  pid_t pid;
  if((pid = fork()) < 0){
    printf("Error en el fork\n");
    exit(1);
  }else if(pid == 0){
    close(fdp[0]); // Cierras input hijo
    dup2(fdp[1], STDOUT_FILENO); // Output lo pasas por pipe

    execlp("cut", "cut", "-d:", "-f6", "/etc/passwd", NULL);
    error = "Error en execlp\n";
    if(write(fd, error, sizeof(char)*17) < 0){
      printf("Error escribiendo en el archivo\n");
    }
    exit(1);
  }

  char lectura[6];
  while(read(fd, lectura, sizeof(char)*6) > 0){
    struct stat stats;
    stat(lectura, &stats);

    if(S_ISDIR(stats.st_mode)){
      printf("%s existe y es de tipo directorio\n", lectura);

      mode_t perm = stats.st_mode;
      perm |= 0700;
      if(chmod(lectura, perm) < 0){
        printf("Error cambiando permisos\n");
        exit(1);
      }

      char* bashrc = ".bashrc";
      char* dir = lectura;
      DIR* carpeta;
      struct dirent* entrada;

      if(!(carpeta = opendir(dir))){
        perror("Error abriendo el directorio\n");
        exit(1);
      }

      while((entrada = readdir(carpeta)) != NULL){
        char ruta[512];
        sprintf(ruta, "%s/%s", dir, entrada->d_name);
        if(ruta == bashrc){
          printf("El directorio %s tiene el archivo %s\n", ruta, bashrc);

          execlp("cat", "cat", ruta, NULL);
          printf("Error mostrando el contenido\n");
          exit(1);
        }
      }
    }else{
      printf("%s NO existe o NO es de tipo directorio\n", lectura);
    }
  }
}
