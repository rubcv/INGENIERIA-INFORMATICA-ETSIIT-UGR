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
  int procesos = 4;
  pid_t pid  = getpid();

    for(int i = 0; i < procesos && pid != 0; i++){ // Te quedas con el pid y filtras != 0 para quedarte con los padres y que los hijos \
                                                      salgan y muestren su pid
        pid = fork();
    }

    printf("\nPID hijo: %d PID padre: %d\n", getpid(), getppid()); // 
}
