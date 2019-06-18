// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Ejemplo 5:
// ----------
// Ejemplo del productor-consumidor con una única variable intermedia
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include <semaphore.h>


using namespace std ;

sem_t
   puede_escribir, // inicializado a 1
   puede_leer,     // inicializado a 0
   mutex ;         // inicializado a 1

unsigned long
   valor_compartido ; // valor para escribir o leer

const unsigned long
   num_iter = 10 ; // numero de iteraciones

// ---------------------------------------------------------------------

void* escribir( void* p )
{
   unsigned long contador = 0 ;

   for( unsigned long i = 0 ; i < num_iter ; i++ )
   {
      contador = contador + 1 ; // genera un nuevo valor
      sem_wait( &puede_escribir ) ;
      valor_compartido = contador ; // escribe el valor
      sem_wait( &mutex ) ;
      cout << "valor escrito == " << contador << endl << flush ;
      sem_post( &mutex ) ;
      sem_post( &puede_leer ) ;


   }
   return NULL ;
}
// ---------------------------------------------------------------------

void* leer( void* p )
{
   unsigned long  valor_leido ;

   for( unsigned long i = 0 ; i < num_iter ; i++ )
   {
      sem_wait( &puede_leer ) ;
      valor_leido = valor_compartido ; // lee el valor generado
      sem_wait( &mutex ) ;
      cout << "valor leido   ==                " << valor_leido << endl << flush ;
      sem_post( &mutex ) ;
      sem_post( &puede_escribir ) ;
   }
   return NULL ;
}
// ---------------------------------------------------------------------

int main()
{
   pthread_t hebra_escritora, hebra_lectora ;

   sem_init( &mutex,          0, 1 ); // semaforo para EM: inicializado a 1
   sem_init( &puede_escribir, 0, 1 ); // inicialmente se puede escribir
   sem_init( &puede_leer,     0, 0 ); // inicialmente no se puede leer

   pthread_create( &hebra_escritora, NULL, escribir, NULL );
   pthread_create( &hebra_lectora,   NULL, leer,     NULL );

   pthread_join( hebra_escritora, NULL ) ;
   pthread_join( hebra_lectora,   NULL ) ;

   sem_destroy( &puede_escribir );
   sem_destroy( &puede_leer );
   sem_destroy( &mutex );
}
// ---------------------------------------------------------------------
