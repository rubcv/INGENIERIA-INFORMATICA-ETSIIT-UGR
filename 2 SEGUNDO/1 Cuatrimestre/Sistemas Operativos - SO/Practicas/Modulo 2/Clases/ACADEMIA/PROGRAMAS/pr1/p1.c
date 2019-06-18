#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){
  int fdRead, fdWrite, leidos; // leidos: Compruebas que solo escribas el numero que lees
  int TAM = 10;
  char bloque[TAM];
  if((fdRead = open("a.txt", O_RDONLY)) < 0){ // COMPROBAR CON OPEN < 0 -> C/C++ 0 ES FALSO OTRO VALOR ES VERDADERO
    printf("Fallo en open de a \n");
    exit(-1);
  }

  if((fdWrite = open("b.txt", O_WRONLY | O_TRUNC | O_CREAT, 00700)) < 0){ // PRIMERO PARA LO QUE QUIERAS USARLO Y LUEGO LOS PERMISOS QUE QUIERAS DARLE
    printf("Fallo en open de b \n");
    exit(-1);
  }

    while( (leidos = read(fdRead, bloque, sizeof(char)*TAM)) > 0){ // READ -> -1 SI ERROR Y 0 SI FIN DE FICHERO
      if((write(fdWrite, bloque, sizeof(char)*leidos)) < 0){ // multiplicas por leidos para que solo escribas los que lees
        printf("Fallo en write\n");
        exit(-1);
      }
    }

    // Cierras los ficheros
    close(fdRead);
    close(fdWrite);
}
