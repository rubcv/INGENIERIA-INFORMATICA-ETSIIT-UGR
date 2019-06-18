// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Ejemplo 4:
// ---------- 
// Uso de un semáforo POSIX para exclusión mutua
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std ;

sem_t mutex ; // semaforo en memoria compartida

// ---------------------------------------------------------------------
void* proc( void* p )
{
   sem_wait( &mutex );
      cout << "hebra numero: " << ((unsigned long) p) << ". " << endl ;
   sem_post( &mutex );
   return NULL ;
}

// ---------------------------------------------------------------------
int main()
{
   const unsigned num_hebras = 50 ;
   pthread_t id_hebra[num_hebras] ;

   sem_init( &mutex, 0, 1 );

   for( unsigned i = 0 ; i < num_hebras ; i++ )
       pthread_create( &(id_hebra[i]), NULL, proc, (void *)i );

   for( unsigned i = 0 ; i < num_hebras ; i++ )
       pthread_join( id_hebra[i], NULL );

   sem_destroy( &mutex );
}
// ---------------------------------------------------------------------
