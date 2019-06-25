#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif

int main(void)
{
    int z, y, x, i, g, temp, filas, columnas, tam,suma=0;
	double inicio,final,diferencia;

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

	inicio = omp_get_wtime();
    for(i=0; i<filas; i++){
    	#pragma omp parallel private(suma)
    	{
    		suma=0;
    		#pragma omp for
    		for(g=0; g<columnas; g++){
    			suma += matriz[g][i]*v1[i];
      			#pragma omp atomic
      			v2[i] += suma;
    		}
    	}
    }
    final = omp_get_wtime();
    
    diferencia = final - inicio;

    printf("Vector Resultado:\n");
    for(i=0; i<tam; i++)
		printf("%i\t",v2[i]);
	
	printf("\nTiempo(seg) Producto Matriz-Vector:\n");
	printf("%f\t",diferencia);

    printf("\n");
}
