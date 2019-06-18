#include <stdio.h>
#include <signal.h>

static int contadores[31];
static void handler (int i){
    contadores[i]++;
}


int main(){
  struct sigaction sa;
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);

  sa.sa_flags = SA_RESTART;
  int contadores[31];

  for (int j = 1 ; j <= 31 ; j++){
     contadores[j] = 0;
   }
  for (int i = 1; i <= 60; i++){
     if(sigaction(i, &sa, NULL) == -1){
       printf("Error en manejador");
     }
   }while(1);
}
