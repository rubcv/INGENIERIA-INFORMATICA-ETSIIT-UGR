#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) { 
  int i, n=200, chunk, a[n], suma=0, dyn, nthreads, modifier;
  omp_sched_t kind;
   if(argc < 3)     {
      fprintf(stderr,"Falta iteraciones o chunk\n");
      exit(-1);
     }
   n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]); 

   for (i=0; i<n; i++)	a[i] = i;
   
   printf("Antes de la modificación:\n");
   printf("Valor variable dyn-var:%d\n",omp_get_dynamic());
   printf("Valor variable nthreads-var:%d\n",omp_get_max_threads());
   omp_get_schedule(&kind, &modifier);
   printf("Valor variable run-sched-var:1ºparámetro:%d,2ºparámetro:%d\n",(int) kind,modifier);
 
   #pragma omp parallel
   {
   
   		#pragma omp single
		{ 
			printf("Introduzca valor dyn-var:\n");
			scanf("%d", &dyn );
			if( dyn == 0 || dyn == 1 ) omp_set_dynamic(dyn);
			else { fprintf(stderr,"El valor de dyn debe ser 0 o 1\n"); exit(-1); }
			
			printf("Introduzca valor nthreads-var:\n");
			scanf("%d", &nthreads );
			if( nthreads > 1 && nthreads < omp_get_thread_limit() ) omp_set_num_threads(nthreads);
			else { fprintf(stderr,"El valor de nthreads debe ser mayor que 0\n"); exit(-1); }
			
			printf("Introduzca valor 1º parámetro run-sched-var:\n");
			scanf("%d", (int *) &kind );
			printf("Introduzca valor 2º parámetro run-sched-var:\n");
			scanf("%d", &modifier );
			if( (int) kind >= 0 || modifier > 0 ) omp_set_schedule(kind, modifier);
			else { fprintf(stderr,"El valor de kind debe ser mayor o igual que 0 y el valor de modifier mayor que 0\n"); exit(-1); }
			
		}
		
		#pragma omp sections
   		{
   			printf("Después de la modificación:\n");
   			printf("Valor variable dyn-var:%d\n",omp_get_dynamic());
   			printf("Valor variable nthreads-var:%d\n",omp_get_max_threads());
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

   return(0);
}
