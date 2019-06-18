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
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){
  printf("Ups!\n");
    //ejecutable, argv[0], argv[1] (Por eso se repite el "ls" (argv[0] nombre del programa) || argc = 2 (argv[0] + argv[1]) )
  execlp("lso", "ls", "-l", NULL); // Una vez ejecuta el exec, el programa solo hace ls
  perror("Error en exec\n"); // NULL indica que hemos terminado
  exit(1);


  char* args[3];
  args[0] = "ls";
  args[1] = "-l";
  args[2] = NULL;

  execv("ls", args); // Si es como vector

  printf("Ups!\n");
}
