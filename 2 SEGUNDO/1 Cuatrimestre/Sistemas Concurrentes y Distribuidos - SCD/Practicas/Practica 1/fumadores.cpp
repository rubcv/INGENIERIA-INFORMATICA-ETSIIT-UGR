
// *****************************************************************************
//
//     
//
//
// Prácticas de SCD. Práctica 1.
//
// Programa fumadores.cpp
//
// *****************************************************************************


#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h> // incluye ”time(....)”
#include <unistd.h> // incluye ”sleep(....)”
#include <stdlib.h> // incluye ”rand(...)"

using namespace std;

// Declaracion de fumadas
int fumada1 = 0, fumada2 = 0, fumada3 = 0;

// Declaracion de semaforos (3 fum. + estanco)
sem_t fu1, fu2, fu3, estanco, aux;

// Ingredientes
int ingredientes = -1; // 0 es papel y cerillas, 1 es papel y tabaco, 2 es tabaco y cerillas;

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


//------------------------------------ Resto de funciones -------------------------------------

// ----------------------------------------------------------------------------


// función que simula la acción de fumar, como un retardo aleatorio de la hebra.
// recibe como parámetro el numero de fumador
// el tiempo que tarda en fumar está entre dos y ocho décimas de segundo.

void fumar( int num_fumador, sem_t aux, int& veces){

    sem_wait(&aux); // Espera a que este disponible el semaforo del fumador que sea

    cout << "\nFumador número " << num_fumador << ": comienza a fumar." << endl << flush ;

    veces++; // Se incrementa las veces que fuma

    retraso_aleatorio( 0.1, 0.5 );

    cout << "Fumador número " << num_fumador << ": termina de fumar.\n" << endl << flush ;

    sem_post(&estanco); // Permitimos que el estanquero pueda poner ingrediente
}


// Estanquero

void* estanquero( void* ){
  int fumador;

    for(int i = 0; i < 10; i++){

        sem_wait(&estanco); // Esperamos que el estanquero pueda poner ingrediente.

        ingredientes = rand() % 3; // Creamos una pareja de ingredientes (0 es papel y cerillas, 1 es papel y tabaco, 2 es tabaco y cerillas)

        // Segun el valor, a quien los necesite

        if(ingredientes == 0){
            aux = fu1;
            sem_post( &aux); // Permitimos que fume el fumador1
            fumador = 1;
            fumar(fumador, aux, fumada1);
        }

        if(ingredientes == 1){
            aux = fu2;
            sem_post( &aux); // Permitimos que fume el fumador2
            fumador = 2;
            fumar(fumador, aux, fumada2);

        }

        if(ingredientes == 2){
            aux = fu2;
            sem_post( &aux); // Permitimos que fume el fumador3
            fumador = 3;
            fumar(fumador, aux, fumada3);

        }
    }
}



int main(){

    srand( time(NULL) ); // inicializa semilla aleatoria para selección aleatoria de fumador

    sem_init( &fu1, 0, 0); // Inicialmente no puede fumar
    sem_init( &fu2,0, 0); // Inicialmente no puede fumar
    sem_init( &fu3,0, 0); // Inicialmente no puede fumar
    sem_init( &estanco,0,1); // Inicialmente el estanquero puede poner ingrediente

    // Declaracion de las hebras
    pthread_t est;

	  // Creamos las hebras
    pthread_create( &est, NULL, estanquero, NULL);

	  // Lanzamos las hebras
    pthread_join(est, NULL);

	  // Destruimos los semaforos
    sem_destroy( &fu1);
    sem_destroy( &fu2);
    sem_destroy( &fu3);
    sem_destroy( &estanco);

	  // Mostramos las fumadas totales
    cout<<endl<<endl<<"Total de fumadas: " << fumada1 + fumada2 + fumada3 <<endl;
}
