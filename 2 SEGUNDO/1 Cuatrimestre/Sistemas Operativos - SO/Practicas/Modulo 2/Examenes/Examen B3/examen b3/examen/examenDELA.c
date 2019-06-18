/**/

void Avisa(){
  printf("Pipe roto :( ");
}

int main(int argc; char* argv[]){
  if(argc < 2 ){  //suponemos que le pasamos el dir actual como argumento
    perror("Error tiene que poner el directorio actual");
    exit(-1);
  }
  //creamos un cauce
  int fd[];

  if(pipe(fd[])<0){
    perror("Error al crear el cauce");
    exit(-1);
  }
  //creammos el hijo
  pid_t pid;
  struct stat att;
  DIR *directorio;
  struct dirent entrada;
  char *ruta[512];
  char * mensaje;

  if((carpeta=opendir(argv[1]))!= NULL){
    perror("Error al abrir el directorio");
    exit(-1);
  }
  if((pid=fork())<0){
    perror("Error al crear el proceso");
    exit(-1);
  }
  if(pid == 0){ //el hijo
    close(fd[1]);
    read(fd[0],&mensaje,sizeof(char));
    printf("El mensaje %s",mensaje);

  }
  struct sigaction sa;
  else{ //padre
    //manejamos la señal SIGPIPE:
    sa.sa_handler=Avisa();
    if((sigaction(SIGPIPE,&sa,NULL)<0){
      perror("No funciono el manejador de señal");
      exit(-1);
    }
    
    close(fd[0]); //cerramos lectura
    while((entrada=readdir(carpeta))!=NULL){
      sprintf(ruta,"%s/%s",argv[1],entrada->d_name);  //metemos en ruta el nombre el path completo por donde vamos
      stat(ruta,&att);
      if(S_ISREG(att.st_mode)){
        mensaje=entrada->d_name;
        if(att.st_mode != S_IRUSR)//no permiso de lectura
          chmod(ruta,S_IRUSR);  //no lo tiene,añadimos permiso de lectura

        if(write(fd[1],&mensaje,sizeof(char)) < 0){
            perror("Error al escribir el mensaje en el pipe");
            exit(-1);
        }
        printf("El inodo es %d , el uid es %d\n" att.st_ino,att.st_uid);  //escribimos por pantalla
      }
    }

  }
  close(fd);
  wait(NULL);
}
