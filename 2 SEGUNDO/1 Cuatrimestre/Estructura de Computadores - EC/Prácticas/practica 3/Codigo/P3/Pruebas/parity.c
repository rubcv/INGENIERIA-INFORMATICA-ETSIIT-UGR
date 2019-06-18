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


unsigned parity1(unsigned *array, int len){
  unsigned x;
  unsigned val = 0;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];
    for(unsigned j = 0; j < 8*sizeof(int); j++){
      unsigned mask = 0x1 << j;
      val ^= (x & mask) != 0;
    }
    result += val;
    val = 0;
  }
  return result;
}

unsigned parity2(unsigned *array, int len){
  unsigned x;
  unsigned val = 0;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];
    do{
      val ^= x & 0x1;
    }while(x >>= 1);

    result += val;
    val = 0;
  }
return result;
}

unsigned parity3(unsigned *array, int len){

  unsigned x;
  unsigned val = 0;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];

    while(x){
      val ^= x;
      x >>= 0x1;
    }
    result += (val & 0x1);
    val = 0;
  }
  return result;
}

unsigned parity4(unsigned *array, int len){

  unsigned x;
  unsigned val = 0;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];
    val = 0;
    asm("\n"
    "ini3:						\n\t"		//seguir mientras que x!=0
    "	xor %[x],%[val]			\n\t"		//realmente solo nos interesa LSB
    "	shr %[x]				\n\t"
    "	test %[x],%[x]			\n\t"
    "	jnz ini3				\n\t"
    "	and $1, %[val]			\n\t"
    : [val]"+r" (val)					//e/s: entrada 0, salida paridad elemento
    : [x] "r" (x)						//entrada: valor elemento
    );
    result += val;
  }
  return result;
}

unsigned parity5(unsigned *array, int len){

  unsigned x;
  unsigned result = 0;

  for(int i = 0; i < len; i++){
    x = array[i];
    for(int j = 16; j >= 1; j = j/2){
        x ^= (x>>j);
    }
      result += (x & 0x1);
  }
    return result;
}

unsigned parity6(unsigned *array, int len){

  unsigned x;
  unsigned result = 0;

  for (int i = 0; i < len; i++){
      x = array[i];
      asm("\n"
      "mov %[x], %%edx			\n\t" 	//sacar copia para XOR. Controlar el registro edx
      "shr $16, %[x] 				\n\t"
      "xor %[x], %%edx			\n\t"
      "xor %%dh, %%dl				\n\t"
      "setpo %%dl 				\n\t"
      "movzx %%dl, %[x]			\n\t"
      : [x]"+r" (x)			  		//e/s: entrada valor elemento, salida paridad
      :
      :"edx"						  		//clobber
      );
      result += x;
    }
  return result;
}

void crono(unsigned (*func)(), char* msg){
  unsigned result;
  struct timeval tv1, tv2;  // gettimeofday() secs-usecs
  long           tv_usecs;  // y sus cuentas

  gettimeofday(&tv1, NULL);
  result = func(lista, SIZE);
  gettimeofday(&tv2, NULL);

  tv_usecs = (tv2.tv_sec -tv1.tv_sec)*1E6+
  (tv2.tv_usec-tv1.tv_usec);
  printf("resultado = %d\t", result);
  printf("%s:%9ld us\n", msg, tv_usecs);
}

int main(){
  int i;
  for(i=0; i<SIZE; i++)   // inicializar array
    lista[i]=i; // se queda en cache

  for(int i = 0; i < 10; i++){ // Hacer 10 mediciones
    crono(parity1, "parity1: ");
    crono(parity2, "parity2: ");
    crono(parity3, "parity3: ");
    crono(parity4, "parity4: ");
    crono(parity5, "parity5: ");
    crono(parity6, "parity6: ");
    printf("N*(N+1)/2=%d\n", (SIZE - 1) * (SIZE / 2) );  /*OF*/
  }
  exit(0);
}
