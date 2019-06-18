
// *****************************************************************************
//
//    
//
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio del productor-consumidor con
// fer intermedio.
//
// *****************************************************************************

// sem_wait(s)
//   if s > 0
//     s = s - 1
//   else
//     bloquear_proceso
//
// sem_post(s)
//   if (proceso_bloqueado == true)
//     desbloquear_alguno
//   else
//     s = s + 1
//
//

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // necesario para {\ttbf usleep()}
#include <stdlib.h> // necesario para {\ttbf random()}, {\ttbf srandom()}
#include <time.h>   // necesario para {\ttbf time()}

using namespace std ;

// ---------------------------------------------------------------------
// constantes configurables:

const unsigned
  num_items  = 40,    // numero total de items que se producen o consumen
  tam_vector = 10;    // tamaño del vector, debe ser menor que el número de items
  int buffer[num_items]; // Vector de buffer compartido
  int poslec = 0, posesc = 0; // indices de lectura, escritura
  sem_t puede_producir, puede_consumir, acceder_buffer; // Dos semaforos, uno para comprobar la produccion(inic. a 1) y otro la consumicion (inic. a 0),\
                                                  añadido otro para exclusion mutua que solo acceda uno a buffer
// ---------------------------------------------------------------------

// introduce un retraso aleatorio de duración comprendida entre
// 'smin' y 'smax' (dados en segundos)

void retraso_aleatorio( const float smin, const float smax )
{
  static bool primera = true ;
  if ( primera )        // si es la primera vez:
  {  srand(time(NULL)); //   inicializar la semilla del generador
     primera = false ;  //   no repetir la inicialización
  }
  // calcular un número de segundos aleatorio, entre {\ttbf smin} y {\ttbf smax}
  const float tsec = smin+(smax-smin)*((float)random()/(float)RAND_MAX);
  // dormir la hebra (los segundos se pasan a microsegundos, multiplicándos por 1 millón)
  usleep( (useconds_t) (tsec*1000000.0)  );
}


// ---------------------------------------------------------------------
// función que simula la producción de un dato

unsigned producir_dato()
{
  static int contador = 0 ;
  contador = contador + 1 ;
  retraso_aleatorio( 0.1, 0.5 );
  cout << "Productor : dato producido: " << contador << endl << flush ;
  return contador ;
}

// ---------------------------------------------------------------------
// función que simula la consumición de un dato

void consumir_dato( int dato )
{
   retraso_aleatorio( 0.1, 0.5 );
   cout << "Consumidor:                              dato consumido: " << dato << endl << flush ;
}


// ---------------------------------------------------------------------
// función que ejecuta la hebra del productor



// Hebra de funcion productor

void* funcion_productor(void* ){

    for(unsigned i = 0; i < num_items; i++){
        sem_wait(&puede_producir); // Esperamos que pueda escribir
        sem_wait(&acceder_buffer); // Esperamos para que pueda acceder al buffer (Exclusion mutua)

        int dato = producir_dato(); // Asignamos el dato aleatorio

        buffer[posesc] = dato; // Guardamos el dato en la posicion de escritura
        cout << "Productor : dato insertado: " << dato << endl << flush ;

        //cout<<"La posicion write es: "<<posesc<<endl;

        posesc++; // Variable que se incrementa al escribir

        if(posesc >= 10){ //incrementamos posicion escritura si es mayor que 10
            posesc = posesc % 10;
        }

        sem_post(&acceder_buffer); // Permitimos que pueda acceder al buffer
        sem_post(&puede_consumir); // Permitimos que pueda leer
    }
    return NULL;
}

// Hebra de funcion consumidor

void* funcion_consumidor(void* ){

    for(unsigned i = 0; i < num_items; i++){

        int dato;

        sem_wait( &puede_consumir); // Esperamos que pueda leer
        sem_wait( &acceder_buffer); // Esperamos a que pueda acceder al buffer

        dato = buffer[poslec]; // Sacamos el dato del buffer de la posicion de lectura

        //cout<<"La posicion read es: "<<poslec<<endl;

        poslec++; // Variable que se incrementa al leer

        if(poslec >= 10){
            poslec = poslec % 10; // Decrementamos posicion lectura
        }

        sem_post( &acceder_buffer); // Permimitimos que pueda acceder al buffer
        sem_post( &puede_producir); // Permitimos que pueda escribir

        cout << "Consumidor:                              dato extraído : " << dato << endl << flush ;

        consumir_dato(dato); // Consume el dato
    }

    return NULL;
}



int main(){

    // Inicializar semaforos
    sem_init( &puede_producir, 0, 1);   // Inicialmente se puede escribir/producir
    sem_init( &puede_consumir,0, 0);  // Inicialmente NO se puede leer/consumir
    sem_init( &acceder_buffer,0,1); // Inicialmente se puede acceder al buffer

    // Declaracion de hebras
    pthread_t hebra_escritora, hebra_lectora;  // Creamos una hebra para leer y otra para escribir


	  //Creamos las hebras
    pthread_create( &hebra_escritora, NULL, funcion_productor, NULL);
    pthread_create( &hebra_lectora, NULL, funcion_consumidor, NULL);

	  // Lanzamos las hebras
    pthread_join(hebra_escritora, NULL);
    pthread_join(hebra_lectora, NULL);

	  // Destruimos los semaforos
    sem_destroy(&puede_producir);
    sem_destroy(&puede_consumir);
    sem_destroy(&acceder_buffer);

    cout<< "\nFin" << endl << flush;
}
