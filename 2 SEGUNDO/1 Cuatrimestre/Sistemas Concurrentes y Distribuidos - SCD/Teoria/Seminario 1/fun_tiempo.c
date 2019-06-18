// funciones auxiliares de interfaz con las funciones en <time.h>
// Carlos Ureña, Septiembre de 2013.

#include <math.h>
#include <stdlib.h> 
#include <assert.h>
#include <pthread.h>
#include "fun_tiempo.h"



//----------------------------------------------------------------------

const long 
   nnss = (long)1000000000L ;   // numero de nanosegundos en un segundo 
                              // (mil millones)
const clockid_t 
   id_reloj = CLOCK_REALTIME ; // identificador del reloj en uso 
                               // (se usa reloj de tiempo real).

//----------------------------------------------------------------------
// escribe en "transcurrido" el intervalo de tiempo entre "inicio" y "fin"
// ("inicio" debe ser anterior o igual a "fin")

void tiempo_transcurrido( struct timespec       * transcurrido, 
                          const struct timespec * inicio, 
                          const struct timespec * fin
                        ) 
{  
   assert( transcurrido != NULL && inicio != NULL && fin != NULL );
   assert( inicio->tv_sec <= fin->tv_sec ) ;
   
   transcurrido->tv_sec = fin->tv_sec - inicio->tv_sec ;
   if ( inicio->tv_nsec <= fin->tv_nsec )
      transcurrido->tv_nsec = fin->tv_nsec - inicio->tv_nsec  ;
   else
   {  transcurrido->tv_nsec = nnss - ( inicio->tv_nsec - fin->tv_nsec );
      assert( transcurrido->tv_sec > 0 ) ;
      transcurrido->tv_sec -- ;
   }
}

//----------------------------------------------------------------------
// devuelve el número de nanosegundos en una estructura de tiempo

long tiempo_nanosegundos( const struct timespec * tiempo )
{
   return  nnss*tiempo->tv_sec + tiempo->tv_nsec  ;
}

//**********************************************************************
//
// funciones "publicas"

//----------------------------------------------------------------------
// devuelve el instante de tiempo de la llamada

struct timespec ahora() 
{
   struct timespec t ;
   clock_gettime( id_reloj, &t );
   return t ;
}


//----------------------------------------------------------------------
// devuelve la duración en segundos del intervalo de tiempo transcurrido 
// entre 'inicio' y 'fin'

double duracion( const struct timespec * inicio, const struct timespec * fin ) 
{
   struct timespec duracion ;
   long nanosegundos ;
   
   assert( inicio != NULL );
   assert( fin != NULL );

   tiempo_transcurrido( &duracion, inicio, fin ) ;
   nanosegundos = tiempo_nanosegundos( &duracion ); 
   
   return (double)nanosegundos/(double)nnss;
}




   
