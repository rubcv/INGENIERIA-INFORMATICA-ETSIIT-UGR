#include <librerias.h>

int main(int argc, char** argv){

  if(argc < 2 || argc > 3){
    printf("Escribe: %s [comando] [bg(opcional)]", argv[0]);
    exit(-1);
  }
  char* bg;
  int opcion = 0;
  if(argc == 3){
    char* bg = argv[2];
    opcion = 1;
  }
  char* comando = argv[1];

  pid_t pid;

  if((pid = fork()) < 0){
    perror("Error en pid");
    exit(-1);
  }

  if(pid == 0){
    sleep(1);
    if(opcion == 1){
      execlp(comando, comando, bg, NULL);
      perror("Error en exec");
      exit(-1);
    }

    if(opcion == 0){
      execlp(comando, comando, NULL);
      perror("Error en exec");
      exit(-1);
    }
  }

  if(opcion == 1){
    wait(NULL);
  }
  printf("%s\n", "PADRE TERMINADO");
}
