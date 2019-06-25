#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int i, j, k, N;
	struct timespec cgt1,cgt2; 
    double ncgt;
	
	N = atoi(argv[1]);
	int mat1[N][N],mat2[N][N],mul[N][N],tam=N*N;

	// Inicializar y Almacenar los valores de las matrices
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++) {
			mul[i][j]=0;
		}
		
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			mat1[i][j] = rand() % tam;
			mat2[j][i] = rand() % tam;
		}
	
	//Realiza la multiplicación e imprime el resultado
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				mul[i][j]+=(mat1[i][k]*mat2[j][k]);
	clock_gettime(CLOCK_REALTIME,&cgt2);
	
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	
	printf("Primera componente: %d, Última componente: %d",mul[0][0],mul[N-1][N-1]);
	printf("\nTiempo(seg) Producto Matriz-Matriz:\n");
	printf("%11.9f\t",ncgt);

    printf("\n");
	
}
