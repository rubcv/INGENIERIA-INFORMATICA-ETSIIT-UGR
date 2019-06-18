#include <librerias.h>

int main(int argc, char** argv){
  pid_t pid = atoi(argv[1]);

  if(kill(pid, SIGINT) < 0){
    printf("%s\n", "Error en kill");
    exit(-1);
  }
}
