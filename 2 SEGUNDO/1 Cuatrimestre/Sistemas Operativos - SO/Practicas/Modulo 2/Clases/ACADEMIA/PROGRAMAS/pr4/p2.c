#include <librerias.h>

int main(){
  int fd = open("cosas.txt", O_WRONLY | O_CREAT, 0644);

  dup2(fd, STDOUT_FILENO); // La salida estandar se convierte en el fichero

  printf("%s\n", "Donde está?");
}
