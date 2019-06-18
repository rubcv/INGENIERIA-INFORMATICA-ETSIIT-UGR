#include <librerias.h>


int status;
void handler(int num){
  wait(&status); // Ves el estado de finalizacion del hijo y aseguras que no queden zombis
  printf("Hijo finalizado, estado %d\n", status);
}


int main(){

  int fd[2];
  pid_t pid;
  int numero = 77, numeroleido;

  struct sigaction sa;
  sigaction(SIGCHLD, &sa, NULL);

  if(pipe(fd) < 0){  // Cauce sin nombre
    perror("Error en el pipe\n");
    exit(-1);
  }

  if((pid = fork()) < 0){
    perror("Error en fork");
    exit(-1);
  }

  if(pid != 0){ // Padre
    close(fd[0]); // <- VER DIAGRAMA
    if(write(fd[1], &numero, sizeof(int)) < 0){
      perror("Error en write\n");
      exit(-1);
    }
    wait(NULL);  // Esperar a que el hijo termine
  }

  if(pid == 0){ // Hijo
    close(fd[1]);
    if(read(fd[0], &numeroleido, sizeof(int)) < 0){
      perror("Error en read\n");
      exit(-1);
    }
    printf("Leido %d\n", numeroleido);
  }
}
