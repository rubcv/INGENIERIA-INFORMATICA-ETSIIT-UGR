#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MMAPSIZE 1

int main (int argc, char *argv[])
{
    off_t len;
    char bufer='a';
    char *cnt;
    int fd;

    umask(0);
    fd = open("Archivo", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd == -1) {
    	perror("El archivo existe");
    	exit(1);
    }
    write(fd, &bufer, sizeof(char));
    
    cnt = (char *) mmap (0, MMAPSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (cnt == MAP_FAILED) {
       printf("Fallo el mapeo\n");
       return 1;
    }
    if (close (fd) == -1) {
      printf("Error al cerrar el archivo\n");
      return 1;   }

  if (fork() == 0) { /* hijo */
  sleep(2);
  printf("El valor de cnt es: %s\n", cnt);
  exit(0);
  }
  /* padre */
  strcpy(cnt, "b");  
  exit(0);
}
					  
