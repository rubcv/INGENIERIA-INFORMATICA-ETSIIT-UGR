#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int z, y, x, i, g, temp, filascolumnas, auxfilascolumnas=0;
	struct timespec cgt1,cgt2; 
    double ncgt;

    printf ("Introduzca el numero de filas y columnas y tamaño del vector: ");
    scanf ("%i",&filascolumnas);

    int matriz[filascolumnas][filascolumnas];
    temp = filascolumnas*filascolumnas;

    for(i=0; i<filascolumnas; i++){
    	for(g=0; g<filascolumnas; g++)
      		matriz[i][g] = 0;
    }

    for(i=auxfilascolumnas; i<filascolumnas; i++){
    	for(g=auxfilascolumnas; g<filascolumnas; g++)
      		matriz[i][g] = rand() % temp;
      	auxfilascolumnas++;
    }
    
    printf("Matriz:\n");
    for (i=0; i<filascolumnas; i++){
		for(g=0; g<filascolumnas; g++)
			printf("%12i",matriz[i][g]);
		printf("\n");
    }

    int v1[filascolumnas],v2[filascolumnas];

    for(i=0; i<filascolumnas; i++)
      		v1[i] = 0;

    for(i=0; i<filascolumnas; i++)
      		v2[i] = 0;

    for(i=1; i<=filascolumnas; i++){
    	do{
      		z = rand() % filascolumnas;

     	}while(v1[z]);

		v1[z] = i;
    }
    
    printf("Vector:\n");
    for(i=0; i<filascolumnas; i++)
		printf("%12i",v1[i]);
		
	printf("\n");

	clock_gettime(CLOCK_REALTIME,&cgt1);
    for(i=0; i<filascolumnas; i++){
    	for(g=0; g<filascolumnas; g++)
      		v2[i]+=matriz[i][g]*v1[g];
    }
    clock_gettime(CLOCK_REALTIME,&cgt2);
    
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

    printf("Vector Resultado:\n");
    for(i=0; i<filascolumnas; i++)
		printf("%12i",v2[i]);
	
	printf("\nTiempo(seg) Producto Matriz-Vector:\n");
	printf("%11.9f\t",ncgt);

    printf("\n");
}
