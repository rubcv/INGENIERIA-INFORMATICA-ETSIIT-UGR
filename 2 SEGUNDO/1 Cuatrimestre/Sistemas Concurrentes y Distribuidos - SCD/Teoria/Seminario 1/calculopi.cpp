// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Plantilla para el ejercicio de cálculo de PI
// *********************************************************************

#include <iostream>
#include <pthread.h>

using namespace std ;

// ---------------------------------------------------------------------
// constante y variables globales (compartidas entre hebras)

const unsigned long m = long(1024)*long(1024) ;  // número de muestras (un millón)
const unsigned n      = 2 ;                      // número de hebras

double resultado_parcial[n] ; // tabla de sumas parciales (una por hebra)

// ---------------------------------------------------------------------
// implementa función $f$

double f( double x )
{
   return 4.0/(1+x*x) ;     // $~~~~f(x)\,=\,4/(1+x^2)$
}
// ---------------------------------------------------------------------
// cálculo secuencial

double calcular_integral_secuencial( )
{
   double suma = 0.0 ;                      // inicializar suma
   for( unsigned long i = 0 ; i < m ; i++ ) // para cada $i$ entre $0$ y $m-1$
      suma += f( (i+0.5)/m );               // $~~~~~$ añadir $f(x_i)$ a la suma actual
   return suma/m ;                          // devolver valor promedio de $f$
}
// ---------------------------------------------------------------------
// función que ejecuta cada hebra


// ---------------------------------------------------------------------
// cálculo concurrente

void* funcion_concurrente(void* ih_void) {//calcule los resultados parcuales dependiendo de n(identificador de la hebra).
    int ih=(unsigned long) ih_void;
    double sumap=0;
    for(unsigned long i=ih; i<m; i+=n) {
        sumap +=f((i+0.5)/m);
    }
    resultado_parcial[ih]=sumap;
}

double calcular_integral_concurrente( )
{
   // crear y lanzar $n$ hebras, cada una ejecuta "funcion\_concurrente"
   //.....
   // esperar (join) a que termine cada hebra, sumar su resultado
   //.....
   // devolver resultado completo
   // .....

   pthread_t id_hebras[n];//declaramos un vector de hebras
   double resultado=0;
   for(unsigned i=0; i<n; i++) {//creamos las hebras
       pthread_create(&(id_hebras[i]),NULL,funcion_concurrente,(void*) i);
   }

   for(unsigned i=0; i<n; i++) {//lanzamos las hebras
       pthread_join(id_hebras[i],NULL);
   }
   for(int i=0; i<n; i++) resultado+=resultado_parcial[i];//sumamos los diferentes resultados
   return resultado/m;
}

// ---------------------------------------------------------------------

int main()
{

   cout << "Ejemplo 4 (cálculo de PI)" << endl ;
   double pi_sec = 0.0, pi_conc = 0.0 ;

   pi_sec  = calcular_integral_secuencial() ;
   pi_conc = calcular_integral_concurrente() ;

   cout << "valor de PI (calculado secuencialmente)  == " << pi_sec  << endl
        << "valor de PI (calculado concurrentemente) == " << pi_conc << endl ;

   return 0 ;
}
// ---------------------------------------------------------------------



// ----------------------------------------------------------------------------
