#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()

int lista[]={1,2,10,  1,2,0b10,  1,2,0x10};
int longlista= sizeof(lista)/sizeof(int);
int resultado=-1;

int suma(int* array, int len)
{
    int  i,   res=0;
    for (i=0; i<len; i++)
//	 res += array[i];
    asm("add (%[a],%[i],4),%[r]	\n"
     :	[r] "+r" (res)		// output-input
     :	[i]  "r" (i),		// input
	[a]  "r" (array)
//   : "cc"			// clobber
    );
    return res;
}

int main()
{
    resultado = suma(lista, longlista);
    printf("resultado = %d = %0x hex\n",
	    resultado,resultado);
    exit(0);
}
