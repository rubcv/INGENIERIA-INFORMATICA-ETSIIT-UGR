//  usar gcc –fno-omit-frame-pointer si gcc quitara el marco pila (%ebp)
#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()

int lista[]={1,2,10,  1,2,0b10,  1,2,0x10};
int longlista= sizeof(lista)/sizeof(int);
int resultado=-1;

int suma(int* array, int len)
{
//  int  i,   res=0;
//  for (i=0; i<len; i++)
//	 res += array[i];
//  return res;
    asm("push	      %ebx	\n" // clobber
"	mov  8(%ebp), %ebx	\n"
"	mov 12(%ebp), %ecx	\n"
"				\n"
"	mov $0, %eax		\n"
"	mov $0, %edx		\n"
"bucle:				\n"
"	add (%ebx,%edx,4), %eax	\n"
"	inc       %edx		\n"
"	cmp  %edx,%ecx		\n"
"	jne bucle		\n"
"				\n"
"	pop  %ebx		\n"
//   : 				// output
//   : 				// input
//   : "cc",			// clobber
//     "eax","ebx","ecx","edx"
    );
}

int main()
{
    resultado = suma(lista, longlista);
    printf("resultado = %d = %0x hex\n",
	    resultado,resultado);
    exit(0);
}
