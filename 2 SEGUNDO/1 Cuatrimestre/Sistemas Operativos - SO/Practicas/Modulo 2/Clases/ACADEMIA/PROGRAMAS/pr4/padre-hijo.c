#include <librerias.h>
/*
    - Crear hijo
    - Comunicar padre-hijo
    - Padre escribe numero en pipe
    - Hijo lee el pipe, multiplica el numero*2 y lo pasa al padre, el padre lo muestra por pantalla
*/

// Saca el nombre de la entrada numero pasada por el aux-padre-hijo

int main(){
  DIR* d;
  struct dirent* ent;
  int valor;

  if(read(STDIN_FILENO, &valor, sizeof(int)) < 0){
    perror("error1");
    exit(-1);
  }

  if((d = opendir(".")) == NULL){
    perror("error2");
    exit(-1);
  }

  while(valor && (ent = readdir(d)) ){
    valor--;
  }

  if(valor){
    perror("error3");
    exit(-1);
  }
  printf("%s\n", ent->d_name);

}
