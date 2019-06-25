#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	if(argc < 3)     {
          fprintf(stderr,"Falta valor N y/o valor a\n");
          exit(-1);
     }
     
    int i,N,a;
	struct timespec cgt1,cgt2; 
    double ncgt;
     
	N = atoi(argv[1]);
	a = atoi(argv[2]);
	
	int x[N],y[N];
	
	for(i=0; i<N; i++){
		x[i] = rand() % N;
		y[i] = rand() % N;
    }
    
    clock_gettime(CLOCK_REALTIME,&cgt1);
	for (i=0;i<N;i++) y[i]= a*x[i] + y[i];
	clock_gettime(CLOCK_REALTIME,&cgt2);
	
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	
	printf("Primera componente: %d Última componente: %d",y[0],y[N-1]);
	printf("\nTiempo(seg) DAXPY: %11.9f\t\n",ncgt);
}
