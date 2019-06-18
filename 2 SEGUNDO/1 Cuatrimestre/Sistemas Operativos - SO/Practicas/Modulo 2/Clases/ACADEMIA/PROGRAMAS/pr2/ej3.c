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

pid_t pid;
  pid = fork(); // EL FORK DEVUELVE 0

  if(pid == 0){
    execlp("ls", "ls", "-l", NULL);
    perror("\nError en el exec \n");
    exit(-1);
  }
  printf("\n %s \n", "\nHecho\n");



}
