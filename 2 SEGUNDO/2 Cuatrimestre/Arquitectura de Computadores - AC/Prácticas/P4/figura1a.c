#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
	int a;
 	int b;
} s[5000];

int main(int argc, char **argv)
{
	if(argc < 2)     {
          fprintf(stderr,"Falta valor N\n");
          exit(-1);
    }
    
	struct timespec cgt1,cgt2; 
    double ncgt;
	int ii, R[40000],N, resto;
	N=atoi(argv[1]);
	resto = N%4;
	struct {
		int a;
 		int b;
	} s[N];
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
 	for (ii=1; ii<=40000;ii++) 
 	{
 		int X1=0,X2=0,X3=0,X4=0,X5=0,X6=0,X7=0,X8=0,X9=0,X10=0,i;
 		
 		for(i=0; i<(N-resto);i+=4){
 			X1+=2*s[i].a+ii;
 			X3+=2*s[i+1].a+ii;
 			X5+=2*s[i+2].a+ii;
 			X7+=2*s[i+3].a+ii;
 			
 			X2+=3*s[i].b-ii;
 			X4+=3*s[i+1].b-ii;
 			X6+=3*s[i+2].b-ii;
 			X8+=3*s[i+3].b-ii;
 		}
 		
 		for(i;i<N;i++){
 			X9+=2*s[i].a+ii;
 			X10+=3*s[i].b-ii;
 		}
 		
 		X1 += X3+X5+X7+X9;
 		X2 += X4+X6+X8+X10;
 
 		if (X1<X2) 
 			R[ii]=X1;
 		else 
 			R[ii]=X2;
 	}
 	clock_gettime(CLOCK_REALTIME,&cgt2);
 	
 	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
 	
 	printf("Tiempo(seg):%11.9f\t\n",ncgt);
 	printf("Primera componente: %d, Última componente: %d",R[0],R[39999]);
 	printf("\n");
}
