//  según la versión de gcc y opciones de optimización usadas, tal vez haga falta
//  usar gcc –fno-omit-frame-pointer si gcc quitara el marco pila (%ebp)

#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <sys/time.h>	// para gettimeofday(), struct timeval

// Size 2²⁰ = 1048576
#define SIZE (1<<16)	// tamaño suficiente para tiempo apreciable

// int lista[SIZE];
int resultado=0;

 unsigned long long lista[SIZE] = {0x800000000, 0x001000000, 0x000000800, 0x000000001};
// unsigned long long lista[SIZE] = {0x7ffffffff, 0xffeffffff, 0xffffff7ff, 0xfffffffffe, 0x010000224, 0x00356700, 0x8900acc00, 0x00bd000ef};
// unsigned long long lista[SIZE] = {0x0, 0x102040080, 0x3590aac06, 0x70b0dd0e0, 0xfffffffff, 0x12345678, 0x9abcdeef0, 0xcafebbeef};


int suma1(int* array, int len)
{
    int  i,   res=0;
    for (i=0; i<len; i++)
	 res += array[i];
    return res;
}

int suma2(int* array, int len)
{
    int  i,   res=0;
    for (i=0; i<len; i++)
    asm("add (%[a],%[i],4),%[r]"
     :	[r] "+r" (res)		// output-input
     :	[i]  "r" (i),		// input
	      [a]  "r" (array)
        // :"cc" // clobber
    );
    return res;
}

int suma3(int* array, int len)
{
    asm("mov 8(%%ebp), %%ebx	\n"  // array
"	mov 12(%%ebp), %%ecx	\n"  // len
"				\n"
"	mov $0, %%eax		\n"  // retval
"	mov $0, %%edx		\n"  // index
"bucle:				\n"
"	add (%%ebx,%%edx,4),%%eax\n"
"	inc       %%edx		\n"
"	cmp %%edx,%%ecx		\n"
"	jne bucle		\n"
     : 				// output
     : 				// input
     :	"ebx"			// clobber
    );
}

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;	// gettimeofday() secs-usecs
    long           tv_usecs;	// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func(lista, SIZE);
    gettimeofday(&tv2,NULL);

    tv_usecs=(tv2.tv_sec -tv1.tv_sec )*1E6+
             (tv2.tv_usec-tv1.tv_usec);
    printf("resultado = %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);
}

int main()
{
  //   int i;			// inicializar array
  //   for (i=0; i<SIZE; i++)	// se queda en cache
	//  lista[i]=i;

    crono(suma1, "suma1 (en lenguaje C    )");
    crono(suma2, "suma2 (1 instrucción asm)");
    crono(suma3, "suma3 (bloque asm entero)");
    printf("N*(N+1)/2 = %d\n", (SIZE-1)*(SIZE/2)); /*OF*/

    exit(0);
}
