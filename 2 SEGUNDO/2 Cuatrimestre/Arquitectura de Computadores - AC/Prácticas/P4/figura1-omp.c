#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
	int a;
 	int b;
} s[5000];

main()
{
	double inicio,final,diferencia;
	int ii, R[40000];
	
	inicio = omp_get_wtime();
	#pragma omp parallel for
 	for (ii=1; ii<=40000;ii++) 
 	{
 		int X1=0,X2=0,i;
 		#pragma omp parallel for
 		for(i=0; i<5000;i++){
 			X1+=2*s[i].a+ii;
 			X2+=3*s[i].b-ii;
 		}
 
 		if (X1<X2) 
 			R[ii]=X1;
 		else 
 			R[ii]=X2;
 	}
 	final = omp_get_wtime();
	
	diferencia = final - inicio;
 	
 	printf("Tiempo(seg):%12.9f\n",diferencia);
 	printf("1º componente: %d, 2º componente: %d",R[0],R[39999]);
 	printf("\n");
}
