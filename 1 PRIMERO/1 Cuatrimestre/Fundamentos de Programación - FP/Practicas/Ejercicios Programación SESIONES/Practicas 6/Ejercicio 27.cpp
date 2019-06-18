#include <iostream>
#include <cstdio>
#define N 1000
 
int main() {

   int i, n;
   char digitos[N];
   printf( "Escribe un numero cualquiera: ");
   scanf ("%s",digitos);
  
   /*cuento los digitos*/
   for (n=0;digitos[n]!='\0' /*digitos distintos del caracter nulo*/ ;n++);
  /*los imprimo*/
   for (i=0;i<n;i++)
    printf ("%3c"/* Espacios que deja */,digitos[i]);

   printf ("\n");
   
	system ("pause");
	return 0;
}
