// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Ejemplo 3:
// ---------- 
// Creación y join de N hebras idénticas usando un vector de 
// identificadores de hebras.
// *********************************************************************

#include <iostream>
#include <pthread.h>

using namespace std ;

// declara una constante con el número de hebras:
const unsigned num_hebras = 10 ; 

// ---------------------------------------------------------------------
// función que ejecuta cada hebra
// (realiza un cálculo arbitrario y devuelve el resultado como un puntero)

void* fun_hebra( void* arg_ptr ) 
{ 
  unsigned long arg_ent = (unsigned long)arg_ptr ; // convertir puntero en entero
  unsigned long res_ent ;                          // resultado (entero)
  void *        res_ptr ;                          // resultado (puntero)
  
  // aquí se incluye cualquier cálculo que le asigne 
  // un valor a res\_ent usando el valor de arg\_ent, por ejemplo este:
  res_ent = arg_ent*arg_ent + 5*arg_ent + 2 ;
  
  // valor ya calculado: devolver resultado como un puntero
  res_ptr = (void *) res_ent ;  // convertir entero en puntero
  return res_ptr ;              // devolver resultado (puntero)                                     
}
// ---------------------------------------------------------------------

int main()
{
   pthread_t id_hebra[num_hebras] ; // vector de identificadores de hebra
   
   // lanzar hebras
   for( unsigned long i = 0 ; i < num_hebras ; i++ )
   {   void * arg_ptr = (void *) i ; // convertir entero a puntero
       pthread_create( &(id_hebra[i]), NULL, fun_hebra, arg_ptr );
   }
   
   unsigned long res_ent ;  // guardará el resultado de cada hebra
   void ** ptr_res_ent = (void **) &res_ent; // puntero a var. con result.
       
   // esperar hebras e imprimir resultados
   for( unsigned i = 0 ; i < num_hebras ; i++ )
   {  pthread_join( id_hebra[i], ptr_res_ent );
      cout << "func(" <<  i << ") == " << res_ent << endl  ;
   }
}
// ----------------------------------------------------------------------------
