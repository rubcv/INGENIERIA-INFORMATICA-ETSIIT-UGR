#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif

int main(int argc, char **argv)
{
    int z, y, x, i, g, temp, filascolumnas, auxfilascolumnas=0, chunk;
	double inicio,final,diferencia;
	
	if(argc < 3)     {
          fprintf(stderr,"\nFalta filas-columnas-tam y/o chunk\n");
          exit(-1);
     }
    filascolumnas= atoi(argv[1]);
   	chunk = atoi(argv[2]);

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
    
    printf("Matriz inicial:\n");
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
    
    printf("Vector inicial:\n");
    for(i=0; i<filascolumnas; i++)
		printf("%12i",v1[i]);
	
    printf("\n");
	
	inicio = omp_get_wtime();
	#pragma omp parallel
	{
		
		#pragma omp sections
		{
			printf("Dentro de 'parallel':\n");
			printf("\tValor variable dyn-var:%d\n",omp_get_dynamic());
			printf("\tValor variable omp_get_num_threads:%d\n",omp_get_num_threads());
    	}
    	
    	#pragma omp for schedule(guided,chunk)
    	for(i=0; i<filascolumnas; i++){
    		for(g=0; g<filascolumnas; g++)
      			v2[i]+=matriz[i][g]*v1[g];
    	}
    }
    final = omp_get_wtime();
    
    diferencia = final - inicio;
	
    printf("Vector Resultado:\n");
    for(i=0; i<filascolumnas; i++)
		printf("%12i",v2[i]);
		
	printf("\n");
	
	printf("Tiempo(seg) Producto Matriz-Vector:\n");
	printf("%21.9f\t",diferencia);

    printf("\n");
}
