#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif
int main(int argc, char **argv)
{
	int i, j, k, N,tam;
	double inicio,final,diferencia;

	if(argc < 3)     {
          fprintf(stderr,"\nFalta tamaño matriz y/o Numero hebras\n");
          exit(-1);
     }
     
    N = atoi(argv[1]);
    omp_set_num_threads(atoi(argv[2]));
    tam=N*N;
	double **mat1,**mat2,**mul;
	
	mat1 = (double**) malloc(N*sizeof(double));
  	mat2 = (double**) malloc(N*sizeof(double));
  	mul = (double**) malloc(N*sizeof(double));
  	
  	for(i=0;i<N;i++){
  		mat1[i] = (double*) malloc(N*sizeof(double));
  		mat2[i] = (double*) malloc(N*sizeof(double));
  		mul[i] = (double*) malloc(N*sizeof(double));
  	}
	
	printf("Valor variable omp_get_num_threads:%d\n",omp_get_num_threads());

	// Inicializar y Almacenar los valores de las matrices
	
	#pragma omp parallel for private(j)
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			mat1[i][j] = rand() % tam;
		}

	#pragma omp parallel for private(j)
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			mat2[i][j] = rand() % tam;
		}

	//Imprimir los valores de las matrices en forma de filas y columas
	/*
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
	*/
	//Realiza la multiplicación e imprime el resultado
	#pragma omp parallel for private(j)
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			mul[i][j]=0;	
	
	inicio = omp_get_wtime();
	#pragma omp parallel for default(none) shared(N,mul,mat1,mat2) private(i,j,k)
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				mul[i][j]+=(mat1[i][k]*mat2[k][j]);
	final = omp_get_wtime();
	
	diferencia = final - inicio;
	/*
	printf("Matriz resultante:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%12i",mul[i][j]);
		printf("\n");
	}
	*/
	printf("Tiempo(seg) Producto Matriz-Matriz: %12.9f\n",diferencia);
	printf("Primera componente: %f Última componente: %f",mul[0][0],mul[N-1][N-1]);
	for(i=0;i<N;i++){
		free(mat1[i]);
		free(mat2[i]);
		free(mul[i]);
	}
	free(mat1);
  	free(mat2);
  	free(mul);
    printf("\n");
	
}
