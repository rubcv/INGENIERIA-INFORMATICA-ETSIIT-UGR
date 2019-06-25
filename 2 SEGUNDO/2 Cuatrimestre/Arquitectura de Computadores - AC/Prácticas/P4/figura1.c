#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
	int a;
 	int b;
} s[5000];

main()
{
	struct timespec cgt1,cgt2; 
    double ncgt;
	int ii, R[40000];
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
 	for (ii=1; ii<=40000;ii++) 
 	{
 		int X1=0,X2=0,i;
 		
 		for(i=0; i<5000;i++){
 			X1+=2*s[i].a+ii;
 			X2+=3*s[i].b-ii;
 		}
 
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
