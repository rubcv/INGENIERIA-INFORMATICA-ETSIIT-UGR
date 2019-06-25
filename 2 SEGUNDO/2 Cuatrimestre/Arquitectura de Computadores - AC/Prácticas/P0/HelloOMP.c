#include <stdio.h>
#include <omp.h>

int main(void) {

#pragma omp parallel
  printf("(%d:!!!Hello world!!!)\n", omp_get_thread_num());

return(0);

}
