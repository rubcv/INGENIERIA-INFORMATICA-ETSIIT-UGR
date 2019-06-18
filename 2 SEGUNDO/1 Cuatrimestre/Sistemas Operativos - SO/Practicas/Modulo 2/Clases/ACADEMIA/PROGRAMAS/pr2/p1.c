#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h> // DIR*

// ------- Sesion 3 -------
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>



int main(){
  printf("Hola\n");
  fork(); // A partir de aqui se hace una copia del proceso
  printf("%s\n", "Dos veces");
}
