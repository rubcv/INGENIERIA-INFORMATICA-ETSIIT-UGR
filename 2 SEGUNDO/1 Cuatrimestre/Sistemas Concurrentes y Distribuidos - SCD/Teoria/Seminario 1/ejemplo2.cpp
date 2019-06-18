// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Ejemplo 2:
// ---------- 
// Creación de dos hebras desde la principal y espera con 'join'
// *********************************************************************

#include <iostream>
#include <pthread.h>

using namespace std ;

// ----------------------------------------------------------------------------

void* proc1( void* arg )
{  
   for( unsigned long i = 0 ; i < 10 ; i++ )
      cout << "hebra 1, i == " << i << endl ;
   return NULL ;
}
// ----------------------------------------------------------------------------

void* proc2( void* arg )
{  
   for( unsigned long i = 0 ; i < 10 ; i++ )
      cout << "hebra 2, i == " << i << endl ;
   return NULL ;
}
// ----------------------------------------------------------------------------

int main()
{
   cout << "Ejemplo 1 : creación de dos hebras desde la principal" << endl ;
   
   // declaración de variables de tipo hebra
   pthread_t hebra1, hebra2 ;

   // pone en marcha la ejecución de las hebras
   pthread_create(&hebra1,NULL,proc1,NULL);
   pthread_create(&hebra2,NULL,proc2,NULL);

   // esperar a que finalizen las dos hebras:
   pthread_join(hebra1,NULL);
   pthread_join(hebra2,NULL);
   cout << "hebras terminadas." << endl ;

   // cálculo posterior a la finalizacion de las hebras
   // ......

   // finaliza hebra principal de forma correcta 
   pthread_exit(NULL); 

   return 0 ;
}
// ----------------------------------------------------------------------------
