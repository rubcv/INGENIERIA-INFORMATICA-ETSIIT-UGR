#include <stdlib.h>
#include <time.h>

#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
	#define omp_get_num_threads() 1
#endif

main() {

	int tid;
	time_t t1,t2;

	#pragma omp parallel private(tid,t1,t2)
	{
		tid = omp_get_thread_num();
		if (tid < omp_get_num_threads()/2 ) system("sleep 3");
		t1= time(NULL);
		
		#pragma omp barrier
		t2= time(NULL)-t1;
		printf("Hebra %d Tiempo=%d seg.\n",tid,t2);
	}
}
