/**/

int main(int argc,char* argv){
  if(argc < 3 ){
    perror("Error en el numero de argumentos");
    exit(-1);
  }

  if(mkfifo(cauce,S_IRUSR|S_IWUSR)<0){
    perror("ERROR con el fifo");
    exit(-1);
  }
  int fd;
  fd=open("cauce",O_RDONLY|O_WRONLY); //lo abrimos como para poder escribir y leer de él
pid_t pid;
  if((pid==fork())<0){
    perror("ERROR AL CREAR EL FIFO");
    exit(-1);
  }
  else{
    if(pid == 0){ //hijo
      //redirigimos la salida estandar al fifo
      dup2(fd,OUT_FILENO);
      //cada hijo ejecuta al explorador
      execlp("explorador",argv[1],NULL);
      perror("Error en el exec");
      exit(-1);
    }
  }
  pid_t pid;
    if((pid==fork())<0){
      perror("ERROR AL CREAR EL FIFO");
      exit(-1);
    }
    else{
      if(pid == 0){ //hijo
        //redirigimos la salida estandar al fifo
        dup2(fd,OUT_FILENO);
        //ejecutamos el explorador
        execlp("explorador",argv[2],NULL);
        perror("Error en el exec");
        exit(-1);
      }
    }


}
