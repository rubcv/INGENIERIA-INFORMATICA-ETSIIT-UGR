#include <mpi.h>
#include <iostream>
#include <math.h>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"


#define Buffer       5
#define ITERS       20
#define TAM          5
#define Productor    4
#define Consumidor   6
#define permiso     1
#define fin          -1

using namespace std;





/*
CAMBIAR ITERACIONES DEL BUCLE:

  Buffer -> 20 * 10 = 200;
  5 Prod -> 20 * 5 = 100;
  4 Cons -> 20 * 4 = 80;

  -> Haces 180 consumiciones y 200 producciones, luego tienes que cambiar las iteraciones del consumidor a 25 para
  que las producidas y consumidas sean 200

*/

// ---------------------------------------------------------------------

int productor()
{
   int value, tag ;
   int permisoCons;
   MPI_Status status;
   for ( unsigned int i = 0; i < ITERS ; i++ )
   {
      value = (rand() % 10);
      cout << "Productor produce valor " << value << endl << flush ;

      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );

      // enviar 'value'
      tag = permiso;
      MPI_Send(&permisoCons, 1, MPI_INT, Buffer, tag, MPI_COMM_WORLD);
      MPI_Recv(&permisoCons, 1, MPI_INT, Buffer, tag, MPI_COMM_WORLD, &status);
      if(tag == fin){ // Si recibe aviso del buffer para terminar
        cout<< "Productor finaliza" << endl;
        return 0;
      }
      cout<< "Productor de valor " << value << " pide permiso para enviar" << endl;

      MPI_Ssend( &value, 1, MPI_INT, Buffer, Productor, MPI_COMM_WORLD );
      cout<< "Productor de valor " << value << " envia" << endl;

   }
}
// ---------------------------------------------------------------------

int buffer()
{
   int        value[TAM] ,
              peticion ,
              pos  =  0,
              rama,
              permis,
              anterior;
   MPI_Status status ;
   bool end = false;

   for( unsigned int i = 0 ; i < ITERS*10 ; i++ )
   {

     // calcular la rama en función del origen del mensaje
     if(pos == 0){
        rama = 0;
      }else if(pos == TAM){
        rama = 1;
      }else{     // leer 'status' del siguiente mensaje (esperando si no hay)
        MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
      }



    int tag;
    switch (rama) {
      case 0:
        tag = permiso;
        MPI_Recv(&permis, 1, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
        cout<< "Buffer recibe peticion de permiso" << endl;
        if(end){
          tag = fin;
        }
        MPI_Send(&permis, 1, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD);

        MPI_Recv( &value[pos], 1, MPI_INT, MPI_ANY_SOURCE, Productor, MPI_COMM_WORLD, &status );
        cout << "Buffer recibe " << value[pos] << " de Productor " << endl << flush;
        pos++;
        if(anterior == value[pos - 1]){
          end = true;
        }
        anterior = value[pos];
        break;
      case 1:
        tag = Consumidor;
        MPI_Recv( &peticion, 1, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status );
        if(end){
          tag = fin;
        }
        MPI_Send(&permis, 1, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD);

        MPI_Ssend( &value[pos-1], 1, MPI_INT, status.MPI_SOURCE, Consumidor, MPI_COMM_WORLD);
        cout << "Buffer envía " << value[pos-1] << " a Consumidor " << endl << flush;
        pos--;
        break;
    }
  }
}




// ---------------------------------------------------------------------

int consumidor()
{
   int         value,
               tag,
               peticion = 1 ;
   float       raiz ;
   MPI_Status  status ;

   for (unsigned int i = 0; i < ITERS + 5; i++)
   {
      tag = tag;
      MPI_Send( &peticion, 1, MPI_INT, Buffer, tag, MPI_COMM_WORLD );
      MPI_Recv( &peticion, 1, MPI_INT, Buffer, tag, MPI_COMM_WORLD, &status);
      if(tag == fin){
        cout<< "Consumidor recibe aviso del buffer y finaliza" << endl;
        return 0;
      }


      MPI_Recv ( &value, 1,    MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD,&status );
      cout << "Consumidor recibe valor " << value << " de Buffer " << endl << flush ;

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
   if ( size != 10 )
   {
     if(rank == 0)
      cout<< "El numero de procesos debe ser 10 "<<endl;
      MPI_Finalize( ); // Para que no aparezcan -np mensajes, terminamos MPI antes de la salida
      return 0;
   }

   // verificar el identificador de proceso (rank), y ejecutar la
   // operación apropiada a dicho identificador
   if ( rank < 5)
      productor();
   else if ( rank == Buffer )
      buffer();
   else if(rank > 5)
      consumidor();

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}
