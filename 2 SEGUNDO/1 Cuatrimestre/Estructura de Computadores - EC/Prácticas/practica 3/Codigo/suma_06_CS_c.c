#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()

int lista[]={1,2,10,  1,2,0b10,  1,2,0x10};
int longlista= sizeof(lista)/sizeof(int);
int resultado=-1;

//extern 
int suma(int* array, int len);

int main()
{
    resultado = suma(lista, longlista);
    printf("resultado = %d = %0x hex\n",
	    resultado,resultado);
    exit(0);
}
