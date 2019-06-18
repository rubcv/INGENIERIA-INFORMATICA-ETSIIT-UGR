#include <librerias.h>

int main(){

    pid_t pid;

    pid = fork();

    if(pid != 0){
      getchar();
      wait(NULL);
      getchar();
    }
    if(pid == 0){
      printf("%s\n","Mensaje del hijo");
      exit(-1);
    }
}
