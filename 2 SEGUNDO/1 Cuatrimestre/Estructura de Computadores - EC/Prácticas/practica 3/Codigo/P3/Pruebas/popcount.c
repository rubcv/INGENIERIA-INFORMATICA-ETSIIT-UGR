
#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <sys/time.h>	// para gettimeofday(), struct timeval

// Size 2²⁰ = 1048576
#define SIZE (1<<16)	// tamaño suficiente para tiempo apreciable

// int lista[SIZE];
int resultado=0;

// unsigned long long lista[SIZE] = {0x800000000, 0x001000000, 0x000000800, 0x000000001};
// unsigned long long lista[SIZE] = {0x7ffffffff, 0xffeffffff, 0xffffff7ff, 0xfffffffffe, 0x010000224, 0x00356700, 0x8900acc00, 0x00bd000ef};
// unsigned long long lista[SIZE] = {0x0, 0x102040080, 0x3590aac06, 0x70b0dd0e0, 0xfffffffff, 0x12345678, 0x9abcdeef0, 0xcafebbeef};

unsigned lista[SIZE];

unsigned popcount1(unsigned *array, int len){
  unsigned x;
  unsigned result = 0;
  for(int i = 0; i < len; i++){
    x = array[i];
    for(int j = 0; j < 8*sizeof(int); j++){
      unsigned mask = 1 << j;
      result += (x & mask) != 0;
    }
  }
  return result;
}

unsigned popcount2(unsigned *array, int len){
  unsigned x;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];

    do{
      result += x & 0x1;
      x >>= 1;
    }while(x);
  }
  return result;
}

unsigned popcount3(unsigned *array, int len){
  unsigned x;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];
    asm("\n"
"ini3:								\n\t"	// seguir mientras que x!=0
"		shr %[x]					\n\t"	// LSB en CF
"		adc $0, %[result]				\n\t"	// acarreo
"		test %[x],%[x]				\n\t"	// miramos si x=0
"		jnz ini3					\n\t"	// saltamos de nuevo si quedan bits a uno
      : [result]"+r" (result)					// E/S: añadir lo acumulado por el momento
      : [x] "r" (x)						// entrada: valor elemento
      );
    }

  return result;
}

unsigned popcount4(unsigned *array, int len){
  unsigned x;
  unsigned val = 0;
  unsigned result = 0;

  for(int j = 0; j < len; j++){
    x = array[j];
    for(int i = 0; i < 8; i++){
      val += x & 0x01010101;
      x >> 1;
    }
    val += (val >> 16);
    val += (val >> 8);
    result += (val & 0xFF);
    val = 0;
  }
  return result;
}

unsigned popcount5 (unsigned *array, int len)
{
  int i;
  unsigned val, result=0;
  int SSE_mask[] = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
  int SSE_LUTb[] = {0x02010100, 0x03020201, 0x03020201, 0x04030302};
  //	3 2 1 0 	7 6 5 4 	1110 9 8	15141312

  if (len & 0x3)
    printf("leyendo 128b pero len no multiplo de 4?\n");

    for (i=0;i<len;i+=4)
      {
        asm("movdqu 	%[x], %%xmm0 	\n\t"
        "movdqa		%%xmm0, %%xmm1	\n\t"	// dos copias de x
        "movdqu 	%[m], %%xmm6	\n\t"	// mascara
        "psrlw		$4, %%xmm1 		\n\t"
        "pand 		%%xmm6, %%xmm0	\n\t"	//; xmm0 - nibbles inferiores
        "pand		%%xmm6, %%xmm1	\n\t"	//; xmm1 - nibbles superiores

        "movdqu		%[l], %%xmm2	\n\t"	//; ...como pshufb sobrescribe LUT
        "movdqa		%%xmm2, %%xmm3	\n\t"	//; ...queremos 2 copias
        "pshufb		%%xmm0,	%%xmm2	\n\t"	//; xmm2 = vector popcount inferiores
        "pshufb		%%xmm1,	%%xmm3	\n\t"	//; xmm3 = vector popcount superiores

        "paddb		%%xmm2, %%xmm3	\n\t"	//; xmm2 += xmm3 - vector popcount bytes
        "pxor		%%xmm0, %%xmm0	\n\t"	//; xmm0 = 0,0,0,0
        "psadbw		%%xmm0, %%xmm3	\n\t"	//; xmm3 = [pcnt bytes0..7|pcnt bytes8..15]
        "movhlps	%%xmm3,	%%xmm0	\n\t"	//; xmm0 = [	0 		  |pcnt bytes0..7]
        "paddd		%%xmm3,	%%xmm0	\n\t"	//; xmm0 = [	no usado  |pcnt bytes0..15]
        "movd 		%%xmm0, %[val]	\n\t"
        : [val]"=r" (val)
        : [x]  "m"	(array[i]),
        [m]  "m"	(SSE_mask[0]),
        [l]  "m"	(SSE_LUTb[0])
        );
        result += val;
      }

      return result;
    }


// Versión SSE4.2 (popcount)
unsigned popcount6(unsigned* array, int len){
  int i;
  unsigned x;
  int val, result=0;

  for (i=0; i<len; i++){
     x = array[i];
     asm("popcnt %[x], %[val]"
      : [val] "=r" (val)
      :   [x] "r" (x)
     );
    result += val;
  }
 return result;
}

// popcount 64bit 6 p/mejorar prestaciones
unsigned popcount7(unsigned* array, int len){
  int i;
  unsigned x1,x2;
  int val,result=0;

  if (len & 0x1)
    printf("leer 64b y len impar?\n");
  for (i=0; i<len; i+=2) {
    x1 = array[i];
    x2 = array[i+1];
    asm("popcnt %[x1], %[val] \n\t"
        "popcnt %[x2], %%edi  \n\t"
        "add    %%edi, %[val] \n\t"
        : [val] "=&r" (val)
        : [x1] "r" (x1),
          [x2] "r" (x2)
        : "edi");
    result += val; }
  return result;
}


    //
    // int suma1(int* array, int len)
    // {
    //     int  i,   res=0;
    //     for (i=0; i<len; i++)
    // 	 res += array[i];
    //     return res;
    // }
    //
    // int suma2(int* array, int len)
    // {
    //     int  i,   res=0;
    //     for (i=0; i<len; i++)
    //     asm("add (%[a],%[i],4),%[r]"
    //      :	[r] "+r" (res)		// output-input
    //      :	[i]  "r" (i),		// input
    // 	      [a]  "r" (array)
    //         // :"cc" // clobber
    //     );
    //     return res;
    // }
    //
    // int suma3(int* array, int len)
    // {
    //     asm("mov 8(%%ebp), %%ebx	\n"  // array
    // "	mov 12(%%ebp), %%ecx	\n"  // len
    // "				\n"
    // "	mov $0, %%eax		\n"  // retval
    // "	mov $0, %%edx		\n"  // index
    // "bucle:				\n"
    // "	add (%%ebx,%%edx,4),%%eax\n"
    // "	inc       %%edx		\n"
    // "	cmp %%edx,%%ecx		\n"
    // "	jne bucle		\n"
    //      : 				// output
    //      : 				// input
    //      :	"ebx"			// clobber
    //     );
    // }

void crono(unsigned (*func)(), char* msg){
  unsigned result;
  struct timeval tv1,tv2; // gettimeofday() secs-usecs
  long           tv_usecs;  // y sus cuentas

  gettimeofday(&tv1, NULL);
  result = func(lista, SIZE);
  gettimeofday(&tv2, NULL);

  tv_usecs = (tv2.tv_sec -tv1.tv_sec)*1E6+
  (tv2.tv_usec-tv1.tv_usec);
  printf("resultultado = %d\t", result);
  printf("%s:%9ld us\n", msg, tv_usecs);
}

int main(){
    int i;			// inicializar array
    for (i=0; i<SIZE; i++)	// se queda en cache
	 lista[i]=i;

  for(int i = 0; i < 10; i++){ // Hacer 10 mediciones
    crono(popcount1, "popcount1: ");
    crono(popcount2, "popcount2: ");
    crono(popcount3, "popcount3: ");
    crono(popcount4, "popcount4: ");
    crono(popcount5, "popcount5: ");
    crono(popcount6, "popcount6: ");
    crono(popcount7, "popcount7: ");

    printf("N*(N+1)/2 = %d\n", (SIZE - 1) * (SIZE / 2) );  /*OF*/
  }
  exit(0);
}
