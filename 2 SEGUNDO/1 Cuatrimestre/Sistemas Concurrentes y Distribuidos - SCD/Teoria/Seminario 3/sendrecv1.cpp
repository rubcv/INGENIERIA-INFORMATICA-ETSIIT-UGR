// *********************************************************************
// SCD: ejemplos del seminario 3
// ejemplo 2: envio y recepción asíncrono (seguro) de un mensaje
// *********************************************************************

#include "mpi.h"
#include <iostream>

using namespace std;

int main( int argc, char *argv[] )
{
    int        rank, 
               size, 
               value ;
    MPI_Status status;
     
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
 
    if ( rank == 0 ) 
    {
        value = 100 ;
        MPI_Send( &value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD );
        cout << "Proceso " << rank << " ha enviado " << value << " al proceso 1" << endl ;
    }  
    else
    {
        MPI_Recv( &value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status );
        cout << "Proceso " << rank << " ha recibido " << value << " de proceso 0" << endl ;
    }
   
    MPI_Finalize( );
    return 0;
}


