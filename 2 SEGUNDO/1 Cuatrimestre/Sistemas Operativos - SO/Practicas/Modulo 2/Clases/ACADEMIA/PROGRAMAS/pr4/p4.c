#include <librerias.h>

// grep root /etc/passwd | cut -d: -f3
int main(){


  int fd[2]; // Variables del pipe
  pid_t pid;

  if(pipe(fd) < 0){
    perror("Error en pipe");
    exit(-1);
  }



  if((pid = fork()) < 0){
    perror("Error en fork");
    exit(-1);
  }

  // Hijo 1
  if(pid == 0){
    close(fd[0]); // Cierras entrada del hijo (salida del pipe)
    if(dup2(fd[1], STDOUT_FILENO) < 0){ // La salida del hijo es la salida estandar
      perror("Error en dup2 2");
      exit(-1);
    }
    execlp("grep", "grep", "root", "/etc/passwd", NULL); // Si no hay error acaba la ejecucion del programa
    perror("Error en execlp"); // Si hay error no lo hace, pasa al perror y sale con el exit
    exit(-1);
  }else{
    // Nuevo pid para el 2º hijo, no reutilizas pid porque si te importa el valor que tiene
    pid_t pid2;
    if((pid2 = fork()) < 0){
      perror("Error en fork");
      exit(-1);
    }

    // Hijo 2
    if(pid2 == 0){
      close(fd[1]); // Cierras salida del hijo (entrada del pipe)
      if(dup2(fd[0], STDIN_FILENO) < 0){ // La entrada (salida del pipe) es la estandar
        perror("Error en dup2 2");
        exit(-1);
      }
      execlp("cut", "cut", "-d:", "-f3", NULL);
      perror("Error en el execlp 2");
      exit(-1);
    }

  }

  close(fd[0]);
  close(fd[1]);
  wait(NULL);
  wait(NULL);




}
