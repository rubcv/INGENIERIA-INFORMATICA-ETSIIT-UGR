#include <mpi.h>
#include <iostream>
#include <math.h>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"


#define Buffer       8
#define ITERS       30 // 30 iteraciones
#define TAM          4
#define Productor    0
#define Consumidor   1

using namespace std;





/*
CAMBIAR ITERACIONES DEL BUCLE:

  Buffer -> 30 * 2 = 60;
  3 Prod -> 30/3 = 15;
  5 Cons -> 30/5 = 6;


*/

// ---------------------------------------------------------------------

void productor()
{
   int value ;

   for ( unsigned int i = 0; i < ITERS/3; i++ ) // ITERS/3 para que cada productor haga 15
   {
      value = i ;
      cout << " - Productor produce valor " << value << endl << flush ;

      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );

      // enviar 'value'
      MPI_Ssend( &value, 1, MPI_INT, Buffer, Productor, MPI_COMM_WORLD );
   }
}
// ---------------------------------------------------------------------

void buffer()
{
   int        value[TAM] ,
              peticion ,
              pos  =  0,
              depositados = 0,
              rama ;
              bool vaciar = false;
   MPI_Status status ;

   for( unsigned int i = 0 ; i < ITERS*2 ; i++ )
   {


     // calcular la rama en función del origen del mensaje
     if(pos == 0){
       rama = 0;
       depositados = 0;
     }else if(pos == TAM || vaciar){
      rama = 1;
    }else{     // leer 'status' del siguiente mensaje (esperando si no hay)
      MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
    }

    switch (rama) {
      case 0:
        MPI_Recv( &value[pos], 1, MPI_INT, MPI_ANY_SOURCE, Productor, MPI_COMM_WORLD, &status );
        cout << " * Buffer recibe " << value[pos] << " de Productor " << endl << flush;
        depositados++;
        if(depositados == 10){
          vaciar = true;
          depositados = 0;
          cout<< " ->> Depositados = 10, vaciamos el buffer" << endl;
        }
        pos++;
        break;
      case 1:
        MPI_Recv( &peticion, 1, MPI_INT, MPI_ANY_SOURCE, Consumidor, MPI_COMM_WORLD, &status );
        MPI_Ssend( &value[pos-1], 1, MPI_INT, status.MPI_SOURCE, Consumidor, MPI_COMM_WORLD);

        cout << " * Buffer envía " << value[pos-1] << " a Consumidor " << endl << flush;
        pos--;
        break;
    }
  }
}




// ---------------------------------------------------------------------

void consumidor()
{
   int         value,
               peticion = 1 ;
   float       raiz ;
   MPI_Status  status ;

   for (unsigned int i = 0; i < ITERS/5; i++)
   {
      MPI_Ssend( &peticion, 1, MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD );
      MPI_Recv ( &value, 1,    MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD,&status );
      cout << " + Consumidor recibe valor " << value << " de Buffer " << endl << flush ;

      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );

      raiz = sqrt(value) ;
   }
}
// ---------------------------------------------------------------------

int main(int argc, char *argv[])
{
   int rank,size;

   // inicializar MPI, leer identif. de proceso y número de procesos
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );

   // inicializa la semilla aleatoria:
   srand ( time(NULL) );

   // comprobar el número de procesos con el que el programa
   // ha sido puesto en marcha (debe ser 10)
   if ( size != 9 )
   {
     if(rank == 0)
      cout<< "El numero de procesos debe ser 9 "<<endl;
      MPI_Finalize( ); // Para que no aparezcan -np mensajes, terminamos MPI antes de la salida
      return 0;
   }

   // verificar el identificador de proceso (rank), y ejecutar la
   // operación apropiada a dicho identificador
   if ( rank < 5)
      consumidor();
   else if ( rank == Buffer )
      buffer();
   else if(rank < 8 && rank > 4)
      productor();

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}
