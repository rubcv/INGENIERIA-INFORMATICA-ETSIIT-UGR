#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
 
int main(int argc, char** argv){ 
  
  int i; 
  double inicio,final,diferencia; //para tiempo de ejecución

  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){	
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }
  
  unsigned int N = atoi(argv[1]);   // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)
  double v1[N], v2[N], v3[N];   // Tamaño variable local en tiempo de ejecución ...
							                            
  //Inicializar vectores
  #pragma omp parallel sections 
  {
    #pragma omp section 
  	for(i=0; i<N; i++){ 
      v1[i] = N*0.1+i*0.1; 
      v2[i] = N*0.1-i*0.1; //los valores dependen de N
    } 
  }
  
  inicio = omp_get_wtime();
  
  //Calcular suma de vectores
  #pragma omp parallel sections 
  {
    #pragma omp section
    for(i=0; i<N; i++) 
      v3[i] = v1[i] + v2[i]; 
  }
  
  final = omp_get_wtime();
  diferencia = final - inicio;

  //Imprimir resultado de la suma y el tiempo de ejecución
  printf("Tiempo(seg.):%f\t / Tamaño Vectores:%u\t / V1[0]+V2[0]=V3[0](%f+%f=%f) V1[%d]+V2[%d]=V3[%d](%f+%f=%f) /\n",diferencia,N,v1[0],     v2[0],v3[0],N-1,N-1,N-1,v1[N-1],v2[N-1],v3[N-1]); 
  
  return 0; 
}
