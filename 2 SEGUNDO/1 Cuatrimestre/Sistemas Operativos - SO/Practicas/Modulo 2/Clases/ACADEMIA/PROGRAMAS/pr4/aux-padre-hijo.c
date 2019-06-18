#include <librerias.h>

int main(){
  int valor = 5;
  int fd = open("datos.bin", O_CREAT | O_WRONLY, 0666);
  write(fd, &valor, sizeof(int));
}
