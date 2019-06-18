#include <librerias.h>

int main(){

  int fd;
  if((fd = open("dup.txt", O_WRONLY | O_TRUNC)) < 0){
    perror("Error en open\n");
    exit(-1);
  }

  char* buff = "hola";
  if(write(fd,buff, sizeof(buff)) < 0){
    perror("Error en write\n");
    exit(-1);
  }


}
