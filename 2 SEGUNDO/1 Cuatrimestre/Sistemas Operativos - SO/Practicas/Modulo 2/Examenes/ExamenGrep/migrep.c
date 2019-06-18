#include <librerias.h>

int suma = 0;
const char* salidaErrores = "ErrorMiGrep.txt";
int estado;

void handler(int num){
  printf("El valor de la suma actual: %d\n", suma);
  wait(&estado); // Finaliza al hijo
  printf("Finaliza el hijo con estado: %d\n", estado);
  exit(EXIT_SUCCESS); // El programa finaliza correctamente
}


int main(int argc, char** argv){


  if(argc != 3){
    printf("Escribe ./migrep [caracter] [ruta-dir]\n");
    exit(1);
  }

  int fd;
  int fdpipe[2];
  char* error;

  if((fd = open(salidaErrores, O_WRONLY | O_TRUNC | O_CREAT, 0700)) < 0){
    perror("Error en la creacion del archivo de errores\n");
    exit(1);
  }

  if(dup2(fd, STDERR_FILENO) < 0){
    perror("Error estableciendo archivo errores\n");
    exit(1);
  }

  // perror("El dup2 de perror funciona\n");


  if(pipe(fdpipe) < 0){
    perror("Error en la creacion del pipe\n");
    exit(1);
  }

  // Establecer señal para Ctrl+c
  struct sigaction sa;
  sa.sa_handler = handler;
  if(sigaction(SIGINT, &sa, NULL) < 0){
    perror("Error en el sigaction\n");
    exit(1);
  }

  // Recorrer el directorio
  char* literal = argv[1];
  char* dir = argv[2];
  DIR* carpeta;
  struct dirent* entrada;
  struct stat stats;

  if(!(carpeta = opendir(dir))){
    perror("Error en lectura de directorio\n");
    exit(1);
  }

  while((entrada = readdir(carpeta)) != NULL){
    char ruta[512]; // La ruta debe tener ese tamaño
    sprintf(ruta, "%s/%s", dir, entrada->d_name);
    stat(ruta, &stats);
    // printf("ruta: %s\n", ruta);
    if(S_ISREG(stats.st_mode)){

      //Creacion de hijo
      pid_t pid;

      if((pid = fork()) < 0){
        perror("Error en creacion de hijo\n");
        exit(1);
      }else if(pid == 0){
        close(fdpipe[0]);
        if(dup2(fdpipe[1], STDOUT_FILENO) < 0){
          perror("Error en el dup2\n");
          exit(1);
        }
        execlp("grep", "grep", "-c", literal, ruta, NULL); // Acabado en NULL
        perror("Error en execlp\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  close(fdpipe[1]);
  dup2(fdpipe[0], STDIN_FILENO);
  char dato[10];
  while(read(fdpipe[0], &dato, sizeof(int)*10) > 0){
    suma += atoi(dato);
    printf("Dato: %s\n", dato);
  }
  printf("\nLa suma total es: %d\n", suma); // No muestra la suma correcta
}
