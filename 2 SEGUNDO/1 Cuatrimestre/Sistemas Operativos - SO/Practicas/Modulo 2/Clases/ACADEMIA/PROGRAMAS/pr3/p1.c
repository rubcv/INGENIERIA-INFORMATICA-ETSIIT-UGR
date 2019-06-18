#include <librerias.h>

int n = 1;

void Funcion(int num){ // Fuera del main
  n = 0;
}


int main(){

  pid_t pid;

  pid = fork();

  if(pid == 0){
    getchar();
    exit(-1); // Para terminar el hijo
  }

  struct sigaction sa;

  sa.sa_handler = Funcion;
                    //Quieres actualizar el valor
  sigaction(SIGCHLD, &sa, NULL);

  while(n == 1){ // Si pones distinto se sale, vale distinto
    sleep(1);
  }

}
