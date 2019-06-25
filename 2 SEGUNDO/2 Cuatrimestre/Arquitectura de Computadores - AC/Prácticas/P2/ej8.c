#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int z, y, x, i, g, temp, filas, columnas, tam;
	struct timespec cgt1,cgt2; 
    double ncgt;

    printf ("Introduzca el numero de filas: ");
    scanf ("%i",&filas);
    printf ("Introduzca el numero de columnas: ");
    scanf ("%i",&columnas);

    double matriz[filas][columnas];
    temp = filas*columnas;

    for(i=0; i<filas; i++){
    	for(g=0; g<columnas; g++)
      		matriz[i][g] = 0;
    }

    for(i=1; i<=temp; i++){
    	do{
      		y = rand() % filas;
      		x = rand() % columnas;
     	}while(matriz[y][x]);

	matriz[y][x] = i;
    }
    
    printf("Matriz:\n");
    for (i=0; i<filas; i++){
		for(g=0; g<columnas; g++)
			printf("%12.2f",matriz[i][g]);
		printf("\n");
    }

    printf ("Introduzca tamaño del vector: ");
    scanf ("%i",&tam);

    int v1[tam],v2[tam];

    for(i=0; i<tam; i++)
      		v1[i] = 0;

    for(i=0; i<tam; i++)
      		v2[i] = 0;

    for(i=1; i<=tam; i++){
    	do{
      		z = rand() % tam;

     	}while(v1[z]);

		v1[z] = i;
    }
    
    printf("Vector:\n");
    for(i=0; i<tam; i++)
		printf("%i\t",v1[i]);
	
    printf("\n");

	clock_gettime(CLOCK_REALTIME,&cgt1);
    for(i=0; i<filas; i++){
    	for(g=0; g<columnas; g++)
      		v2[i]+=matriz[g][i]*v1[i];
    }
    clock_gettime(CLOCK_REALTIME,&cgt2);
    
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

    printf("Vector Resultado:\n");
    for(i=0; i<tam; i++)
		printf("%i\t",v2[i]);
	
	printf("\nTiempo(seg) Producto Matriz-Vector:\n");
	printf("%11.9f\t",ncgt);

    printf("\n");
}
