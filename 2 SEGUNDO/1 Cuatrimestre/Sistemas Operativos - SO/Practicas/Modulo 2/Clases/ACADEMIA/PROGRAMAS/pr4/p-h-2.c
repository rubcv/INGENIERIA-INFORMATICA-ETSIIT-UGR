#include <librerias.h>

/*
  - Hijo recibe como argumento argv[1] ruta de directorio
  - Escribe por salida el inodo de todos los archivos regulares

  - padre recibe en argv[1] la ruta del directorio
  - le dice al hijo la ruta y lee todos los inodos que escribe el hijo y muestra por pantalla

*/

int main(int argc, char** argv){
  int n, fd[2], pid;

  if(argc != 2){...}
  n = atoi(argv[1]);
  if(pipe(fd) < 0){...}
  if((pid = fork())) < 0){...}
  else if(pid == 0){
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    execl("./eje1", "./eje1", NULL);
    perror("..");
    exit(1);
  }

  close(fd[0]);
  if(write(fd[1], &n, sizeof(int)) < 0){
    ...
  }
  close(fd[1]);


}
