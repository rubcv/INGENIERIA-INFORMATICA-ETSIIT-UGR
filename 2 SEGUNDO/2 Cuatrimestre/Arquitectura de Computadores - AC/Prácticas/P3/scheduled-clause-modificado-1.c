#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) { 
  int i, n=200, chunk, a[n], suma=0, modifier;
  omp_sched_t kind;
   if(argc < 3)     {
      fprintf(stderr,"Falta iteraciones o chunk\n");
      exit(-1);
     }
   n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]); 

   for (i=0; i<n; i++)	a[i] = i;
 
   #pragma omp parallel
   {
   		#pragma omp sections
   		{
   			printf("Dentro de 'parallel':\n");
   			printf("Valor variable dyn-var:%d\n",omp_get_dynamic());
   			printf("Valor variable nthreads-var:%d\n",omp_get_max_threads());
   			printf("Valor variable thread-limit-var:%d\n",omp_get_thread_limit());
   			omp_get_schedule(&kind, &modifier);
   			printf("Valor variable run-sched-var:1ºparámetro:%d,2ºparámetro:%d\n",(int) kind,modifier);
   		}
   		#pragma omp for firstprivate(suma) \
            lastprivate(suma) schedule(dynamic,chunk)
   		for (i=0; i<n; i++) {   
   			suma = suma + a[i];
     		printf(" thread %d suma a[%d]=%d suma=%d \n",omp_get_thread_num(),i,a[i],suma);
   		}  
   }
   
   printf("Fuera de 'parallel':\n");
   printf("Valor variable suma:%d\n",suma);
   printf("Valor variable dyn-var:%d\n",omp_get_dynamic());
   printf("Valor variable nthreads-var:%d\n",omp_get_max_threads());
   printf("Valor variable thread-limit-var:%d\n",omp_get_thread_limit());
   omp_get_schedule(&kind, &modifier);
   printf("Valor variable run-sched-var:1ºparámetro:%d,2ºparámetro:%d\n",(int) kind,modifier);

   return(0);
}
