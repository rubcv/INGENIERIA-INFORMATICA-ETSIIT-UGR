//consumidorFIFO.c
//Consumidor que usa mecanismo de comunicacion FIFO.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#define ARCHIVO_FIFO "Prueba.txt"

int main(void)
{
int fd;
int tam = 80;
char buffer[tam];// Almacenamiento del mensaje del cliente.
int leidos;

//Crear el cauce con nombre (FIFO) si no existe
umask(0);
mknod(ARCHIVO_FIFO,S_IFIFO|0666,0);
//tambi�n vale: mkfifo(ARCHIVO_FIFO,0666);

//Abrir el cauce para lectura-escritura
if ( (fd=open(ARCHIVO_FIFO,O_RDWR)) <0) {
perror("open");
exit(-1);
}

//Aceptar datos a consumir hasta que se env�e la cadena fin
bool res;
while(1) {
  leidos=read(fd,buffer,tam);
  res = strstr(buffer,"fin");
  printf("\nMensaje recibido: %s\n", buffer);
  if(res) {
  close(fd);
  return 0;
  }

}

return 0;
}
