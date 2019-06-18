#include <librerias.h>
#include <unistd.h> // write
/* TABLA DE DESCRIPTORES DE FICHEROS:
    stdin -> STDIN_FILENO -> 0
    stdout -> STDOUT_FILENO -> 1
    stderr -> STDERR_FILENO -> 2
*/
int main(){
  write(STDOUT_FILENO, "mola\n", 5*sizeof(char));
}
