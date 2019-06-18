#include<sys/types.h> //Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>    //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/wait.h>



int main() {
    int num_hijos = 5;
    int i, estado;
    pid_t pid;
    for(i=0; i<num_hijos; i++) {//creamos los 5 hijos
        if((pid = fork())<0) {
            perror("Error en fork\n");
            exit(-1);
        }
        if(pid==0) {//mostramos la pid de los 5 hijos
            printf("Soy el hijo %i\n", getpid());
            exit(0);
        }
    }
	sleep(5);//hacemso sleep para apreciar la ejecucuon de los diferentes hijos
    for(i=num_hijos-1; i>=0; i--) {
        pid = wait(&estado);//espera a todos los hijos
        printf("Acaba de finalizar mi hijo con pid:  %i\n", pid);
        printf("Solo me quedan %i hijos vivos\n", i);
    }
    return 0;
}
