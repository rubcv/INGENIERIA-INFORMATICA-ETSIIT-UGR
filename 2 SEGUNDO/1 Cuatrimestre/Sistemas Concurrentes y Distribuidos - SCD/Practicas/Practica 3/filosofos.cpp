#include <iostream>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#include <mpi.h>


#define coger 0
#define soltar 1

using namespace std;

void Filosofo( int id, int nprocesos);
void Tenedor ( int id, int nprocesos);

// ---------------------------------------------------------------------


/*
   Si los filosofos solicitan siempre los tenedores en el mismo orden, se produce bloqueo entre los filosofos.
   Luego para implementar correctamente este problema se debe hacer que un filosofo coja los tenedores en orden inverso a los
   demas filosofos.
*/



int main( int argc, char** argv )
{
   int rank, size;

   srand(time(0));
   MPI_Init( &argc, &argv );
     MPI_Comm_rank( MPI_COMM_WORLD, &rank );
     MPI_Comm_size( MPI_COMM_WORLD, &size );

       if( size != 10)
       {
          if( rank == 0)
             cout<<"El numero de procesos debe ser 10" << endl << flush ;
          MPI_Finalize();
          return 0;
       }

       if ((rank%2) == 0)
          Filosofo(rank, size); // Los pares son Filosofos
       else
          Tenedor(rank, size);  // Los impares son Tenedores

   MPI_Finalize( );
   return 0;
}
// ---------------------------------------------------------------------

void Filosofo( int rank, int nprocesos )
{
   int izq = (rank+1) % nprocesos;
   int der = ((rank+nprocesos)-1) % nprocesos;
   int destino;
   while(1)
   {
     // Separar
     if(rank != 0){
        // Solicita tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, rank + 1, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor izquierdo: " << izq << endl << flush;

        // Solicita tenedor derecho
        // ((rank - 1) < 0)? destino = 4 : destino = rank - 1;
        destino = rank - 1;
        MPI_Ssend(&der, 1, MPI_INT, destino, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor derecho: " << der << endl << flush;

        cout<< " - FILOSOFO: " << rank << " COMIENDO" << endl << flush;
        sleep((rand() % 3)+1);  //comiendo

        // Suelta el tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, destino, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor izquierdo: " << izq << endl << flush;

        // Suelta el tenedor derecho
        MPI_Ssend(&der, 1, MPI_INT, rank + 1, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor derecho: " << der << endl << flush;

        // Piensa (espera bloqueada aleatorio del proceso)
        cout << " - FILOSOFO: " << rank << " PENSANDO" << endl << flush;

        // espera bloqueado durante un intervalo de tiempo aleatorio
        // (entre una décima de segundo y un segundo)
        usleep( 1000U * (100U+(rand()%900U)) );
      }else{
        // Solicita tenedor derecho
        // ((rank - 1) < 0)? destino = 4 : destino = rank - 1;
        destino = 9;
        MPI_Ssend(&der, 1, MPI_INT, destino, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor derecho: " << der << endl << flush;

        // Solicita tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, rank + 1, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor izquierdo: " << izq << endl << flush;


        cout<< " - FILOSOFO: " << rank << " COMIENDO" << endl << flush;
        sleep((rand() % 3)+1);  //comiendo

        // Suelta el tenedor derecho
        MPI_Ssend(&der, 1, MPI_INT, rank + 1, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor derecho: " << der << endl << flush;

        // Suelta el tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, destino, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor izquierdo: " << izq << endl << flush;


        // Piensa (espera bloqueada aleatorio del proceso)
        cout << " - FILOSOFO: " << rank << " PENSANDO" << endl << flush;

        // espera bloqueado durante un intervalo de tiempo aleatorio
        // (entre una décima de segundo y un segundo)
        usleep( 1000U * (100U+(rand()%900U)) );
      }
 }
}
// ---------------------------------------------------------------------

void Tenedor(int rank, int nprocesos)
{
  int buf;
  MPI_Status status;
  int Filo;

  while( true )
  {
      // Espera un peticion desde cualquier filosofo vecino ...
      MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      // Recibe la peticion del filosofo ...
      Filo = status.MPI_SOURCE; // Cada tenedor recibe el mensaje del filosofo que lo haya pedido
      MPI_Recv(&buf, 1, MPI_INT, Filo, coger, MPI_COMM_WORLD, &status); // Solicita tenedor
      cout << " * Tenedor: " << rank << " recibe peticion de filosofo: " << Filo << endl << flush;
      // Espera a que el filosofo suelte el tenedor...
      MPI_Recv(&buf, 1, MPI_INT, Filo, soltar, MPI_COMM_WORLD, &status); // Soltar tenedor izquierdo
      cout << " * Tenedor: " << rank << " recibe liberacion de filosofo: " << Filo << endl << flush;
  }
}
// ---------------------------------------------------------------------
