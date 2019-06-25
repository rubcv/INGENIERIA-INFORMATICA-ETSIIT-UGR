#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, k, N;
	struct timespec cgt1,cgt2; 
    double ncgt;

	printf("Introduzca el numero de filas y columnas matrices:\n");
	scanf("%d",&N);
	
	int mat1[N][N],mat2[N][N],mul[N][N],tam=N*N;

	// Inicializar y Almacenar los valores de las matrices
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			mat1[i][j]=0;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			mat2[i][j]=0;

	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			mat1[i][j] = rand() % tam;
		}

	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			mat2[i][j] = rand() % tam;
		}

	//Imprimir los valores de las matrices en forma de filas y columas

	printf("Matriz 1:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%12i",mat1[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("Matriz 2:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%12i",mat2[i][j]);
		printf("\n");
	}
	printf("\n");

	//Realiza la multiplicación e imprime el resultado
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			mul[i][j]=0;	
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				mul[i][j]+=(mat1[i][k]*mat2[k][j]);
	clock_gettime(CLOCK_REALTIME,&cgt2);
	
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	
	printf("Matriz resultante:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%12i",mul[i][j]);
		printf("\n");
	}
	
	printf("\nTiempo(seg) Producto Matriz-Matriz:\n");
	printf("%11.9f\t",ncgt);

    printf("\n");
	
}
