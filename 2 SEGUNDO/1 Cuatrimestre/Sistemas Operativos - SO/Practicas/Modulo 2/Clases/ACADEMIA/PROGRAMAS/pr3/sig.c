#include <librerias.h>

int main(){
  struct sigaction sa;

  void FuncionChula(int n){
    printf("%s\n","Como molo :)");
  }

  sa.sa_handler = FuncionChula;

  sigaction(SIGINT, &sa, NULL);

  while(1){
    sleep(1);
  }
}
