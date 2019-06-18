#include <librerias.h>

// ./miGrep [opcion] [literal] [ruta-directorio] -> ./miGrep -c a /dir
// grep -> [opcion] [literal] [archivo]
//                  -c PARA CONTAR LITERALES

int main(int argc, char** argv){
  if(argc < 3){
    printf("Escribe %s [opcion] [literal] [ruta-directorio]\n\n");
    exit(-1);
  }

  int fd;
  const char* name = "ErrorMiGrep.txt";
  int contador = 0;

if((fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0700)) < 0){
  perror("\nError en la apertura del archivo\n");
}

char* literal = argv[1]; // Literal a buscar
char* opcion = argv[2]; // Opcion para el grep
char* dir = argv[3]; // Directorio para hacer la busqueda
DIR* carpetano;
struct dirent* entrada;


pid_t pid;
if(!(carpetano = opendir(dir))){
  char* buff = "\nError en la apertura de directorio\n";
  write(fd, buff, 37); // 37 -> Tamaño del mensaje
  exit(-1);
}


  while((entrada = readdir(carpetano)) != NULL){
    if((pid = fork()) < 0){
      perror("\nError en el fork\n");
      exit(-1);
    }
    if(pid == 0){
      char rutaActual[512];

      sprintf(rutaActual, "%s/%s", dir, entrada->d_name);

      struct stat stats;
      stat(rutaActual, &stats);

      if(S_ISREG(stats.st_mode)){
        //printf("\n%s es un archivo regular\n", entrada->d_name);

        execlp("grep", "grep", opcion, literal, entrada->d_name, NULL);
        char* buff = "\nError en la ejecucion\n";
        write(fd, buff, 23); // 23 -> Tamaño del mensaje
        // char* count = itoa(contador);
        // write(fd, count, contador);
        exit(0);
      }
    }
    // Proceso  recibe fd
  }


}
