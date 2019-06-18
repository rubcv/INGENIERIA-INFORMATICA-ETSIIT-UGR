#include <librerias.h>

int suma = 0;
int estado;

void noZombis(int n){
  wait(&estado);
  printf("Hijo finalizado con estado: %d, suma: %d\n", estado, suma);
}

int main(int argc, char** argv){


  if(argc != 2){
    printf("Escribe: %s [ruta-dir]\n", argv[0]);
    exit(1);
  }

  struct sigaction sa;
  sa.sa_handler = noZombis;

  if(sigaction(SIGCHLD, &sa, NULL) < 0){
    perror("Error estableciendo el sigaction\n");
    exit(1);
  }

  // printf("LLEGA");
  char* dir = argv[1];
  DIR* carpeta;
  struct dirent* entrada;
  int fd;
  char* fifo = "archivoFIFO";

  remove(fifo); // No pongo error si falla para que continue la ejecucion
  if(mkfifo(fifo, 0777) < 0){
    perror("Error en mkfifo\n");
    exit(1);
  }

  printf("Abre para escribir\n");
  if((fd = open(fifo, O_RDWR)) < 0){
    perror("Error en fdr");
    exit(1);
  }




  if(!(carpeta = opendir(dir))){
    perror("Error abriendo el directorio\n");
    exit(1);
  }

  char salida[11];
  int num = 1;
  while((entrada = readdir(carpeta)) != NULL){
    char ruta[512]; // Tamaño de la ruta
    sprintf(ruta, "%s/%s", dir, entrada->d_name);
    //printf(ruta, "\n");

    pid_t pid;
    if((pid = fork()) < 0){
      perror("Error en el fork\n");
      exit(1);
    }else if(pid == 0){
      // printf("Ejecuta hijo: %d\n", num);
      // num++;
      if(dup2(STDOUT_FILENO, fd) < 0){
        printf("Error en dup2\n");
        exit(1);
      }
      execl("./chequeoarchivo", "./chequeoarchivo", ruta, NULL);
      perror("Error en el execl\n");
      exit(1);
    }
  }
  //  if(setvbuf(stdout,NULL,_IONBF,0)) {
  //    perror("\nError en setvbuf");
  //  }
  dup2(STDIN_FILENO, fd);
  while(read(fd, &salida, sizeof(char)*11) > 0){ // Bucle de lectura fuera, para que el padre lea de cualquier hijo
    suma += atoi(salida);
    printf("Salida: %s, Suma: %d\n", salida, suma);
  }
  close(fd);


}
