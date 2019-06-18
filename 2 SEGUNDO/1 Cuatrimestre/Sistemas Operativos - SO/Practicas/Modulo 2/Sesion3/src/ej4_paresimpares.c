#include<sys/types.h> //Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>    //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int main() {
    int num_hijos = 5;
    int i, estado,h_vivos=5;
    pid_t pid[num_hijos];//creamos un vector de pid
    pid_t pid2;
    for(i=0; i<num_hijos; i++) {//creamos los 5 hijos
        if((pid[i] = fork())<0) {//almacensmos la pid en el vector para conocer el orden
            perror("Error en fork\n");
            exit(-1);
        }
        if(pid[i]==0) {//mostramos la pid de los 5 hijos
            printf("Soy el hijo %i\n", getpid());
            exit(0);
        }
    }
    sleep(1);//hacemso sleep para apreciar la ejecucuon de los diferentes hijos
    for(i=0; i<num_hijos;i+=2) {//este for actua para los procesos impares
        printf("esperamos a los procesos impares, como el: %i\n", pid[i]);
        pid2= waitpid(pid[i],&estado);
        printf("Acaba de finalizar mi hijo con %i\n", pid[i]);
        h_vivos--;
        printf("Solo me quedan %i hijos vivos\n", h_vivos);
    }
    for(i=1; i<num_hijos-1; i+=2) {//este for actua para los procesos pares
	printf("esperamos a los procesos pares, como el: %i\n", pid[i]);
        pid2= waitpid(pid[i],&estado);
        printf("Acaba de finalizar mi hijo con %i\n", pid[i]);
        h_vivos--;
        printf("Solo me quedan %i hijos vivos\n", h_vivos);
    }
    return 0;
}
