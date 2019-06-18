#include <librerias.h>



int suma = 0; // Para que la suma la conozca el handler a la hora de
// finalizar

void noZombis(int n){ // Nos aseguramos de que no quedan zombis
  wait(NULL);
  printf("Hijo terminado, total de la suma: %d\n", suma);
}

int main(int argc, char** argv){
  if(argc < 3){
    printf("Escribe: %s [ruta1] [ruta2]\n", argv[0]);
    exit(1);
  }

  struct sigaction sa;
  sa.sa_handler = noZombis;

  if(sigaction(SIGCHLD, &sa, NULL) < 0){
    perror("Error en sigaction\n");
    exit(1);
  }

  char cad[11];
  int fd, fdr;
  pid_t pid;
  const char* fifo = "datos";

  remove(fifo); // Lo borro al principio porque si esta creado y se hace el mkfifo, da error
  if(mkfifo(fifo, 0777) < 0){
    perror("Error en mkfifo\n");
    exit(1);
  }
  if((fdr = open(fifo, O_RDWR)) < 0){
    perror("Error en fdrr");
    exit(1);
  }

  printf("Abre para escribir\n");
  if((fd = open(fifo, O_WRONLY)) < 0){
    perror("Error en fd");
    exit(1);
  }

  printf("Crea el fifo\n");

  printf("Crea el 1º hijo\n");

  if((pid = fork()) < 0){
    perror("Error en fork\n");
    exit(1);
  }

  if(pid == 0){
    printf("LLega 1º exec\n");
    if(dup2(STDOUT_FILENO, fd) < 0){
      printf("Error en 1º dup2\n");
      exit(1);
    }
    execl("./chequeoarchivo", "./chequeoarchivo", argv[1], NULL);
    perror("Error en exec");
    exit(1);
  }

  if((pid = fork()) < 0){
    perror("Error en fork\n");
    exit(1);
  }

  if(pid == 0){
    printf("LLega 2º exec\n");
    if(dup2(STDOUT_FILENO, fd) < 0){
      printf("Error en 2º dup2\n");
      exit(1);
    }
    execl("./chequeoarchivo", "./chequeoarchivo", argv[2], NULL);
    perror("Error en exec");
    exit(1);
  }

  while(read(fdr, cad, sizeof(char)*11) > 0){
    printf("Leido: %s\n", cad);
    suma += atoi(cad);
    printf("Suma: %d\n", suma);
  }
  printf("yeah\n");

  close(fd);

  if(remove(fifo) < 0){
    perror("Error borrando el archivo fifo\n"); // Lo borro tambien al final para que sea el mismo programa el que lo borra
    exit(1);
  }

}
