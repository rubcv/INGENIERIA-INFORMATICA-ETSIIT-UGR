#include <librerias.h>
// #include <signal.h>



int veces = 0;

void handler(int num){
  printf("Se ha pulsado crtl+c, veces contadas %d\n", veces);
  wait(NULL);
  printf("Hijo finalizado\n"); // Imprime veces, termina los hijos y sale
  exit(-1);
}


int main(){

  pid_t pid;
  struct sigaction sa;
  sa.sa_handler = handler;

  sigaction(SIGINT, &sa, NULL);

  if((pid = fork()) < 0){
    perror("Error en la creacion del hijo\n");
    exit(-1);
  }

  if(pid == 0){
    while(1){
      sleep(3);
      veces++;
    }
  }else{
   while(1){
     sleep(3);
   }
 }

}
