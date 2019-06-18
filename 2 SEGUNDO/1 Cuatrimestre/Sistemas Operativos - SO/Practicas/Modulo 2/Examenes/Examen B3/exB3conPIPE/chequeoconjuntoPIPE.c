#include <librerias.h>


int estado;
int sumaLeidos = 0;
void noZombis(int n){
  wait(&estado);
  printf("Hijo finalizado, estado: %d\n", estado);
  printf("Suma de valores leidos: %d\n", sumaLeidos);
}

int main(int argc, char** argv){
    if(argc != 3){
      printf("Escribe: %s [ruta-archivoregular1] [ruta-archivoregular2]\n", argv[0]);
      exit(1);
    }

    char* ar1 = argv[1];
    char* ar2 = argv[2];

    struct sigaction sa;
    sa.sa_handler = noZombis;
    if(sigaction(SIGCHLD, &sa, NULL) < 0){
      perror("Error estableciendo el sigaction\n");
      exit(1);
    }


    char lectura[11];
    int fd[2];
    pipe(fd);

    pid_t pid;

    if((pid = fork()) < 0){
      perror("Error en el fork\n");
      exit(1);
    }else if(pid == 0){
      close(fd[0]);
      dup2(fd[1], STDOUT_FILENO);

      execl("./chequeoarchivoPIPE", "./chequeoarchivoPIPE", ar1, NULL);
      perror("Error en execl del 1º hijo\n");
      exit(1);
    }else{
      if((pid = fork()) < 0){
        perror("Error en el 2º fork\n");
        exit(1);
      }else if(pid == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);

        execl("./chequeoarchivoPIPE", "./chequeoarchivoPIPE", ar2, NULL);
        perror("Error en el execl del 2º hijo\n");
        exit(1);
      }

      close(fd[1]);
      dup2(fd[0], STDIN_FILENO);

      while(read(fd[0], lectura, sizeof(char)*11) > 0){
        printf("Valor leido: %s\n", lectura);
        int num = atoi(lectura);
        sumaLeidos += num;
      }
    }




}
