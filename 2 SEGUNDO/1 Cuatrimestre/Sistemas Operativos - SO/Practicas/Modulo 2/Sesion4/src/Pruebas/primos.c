#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
int es_primo(int x) {
    int b=1;
    int c;
    for(c=2; c<x && b==1; c+=2) {
        if(x%c==0) b=0;
    }
    return b;
}


int main(int argc, char *argv[]) {
    int min,max;
    if(argc>1) {//si los argumentos son correctos
        int i;
        min=strtol(argv[1],NULL,10);//min es el primer argumento
        max=strtol(argv[2],NULL,10);//max es el segundo argumento

        for(i=min; i<=max; i++) {//devuelve los numeros primos entre el intervalo de [min,max]
            if(es_primo(i)==1) {
                printf("%d\n",i);
            }
        }
    }
    else{//si los argumentos no son correctos
		printf("faltan argumentos");
	    exit(0);
	}
	return 0;
}
