// funciones auxiliares de interfaz con las funciones en <time.h>
// Carlos Ureña, Septiembre de 2013.

#ifndef FUN_TIEMPO_HPP
#define FUN_TIEMPO_HPP
#include <time.h>
#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------------------------
// devuelve el instante de tiempo actual

struct timespec ahora() ;

//----------------------------------------------------------------------
// devuelve la duración en segundos del intervalo de tiempo real transcurrido 
// entre 'inicio' y 'fin'

double duracion( const struct timespec * inicio, const struct timespec * fin ) ;

//----------------------------------------------------------------------

#ifdef __cplusplus
}   // fin de "extern C ...."
#endif
#endif // FUN_TIEMPO_HPP



   
