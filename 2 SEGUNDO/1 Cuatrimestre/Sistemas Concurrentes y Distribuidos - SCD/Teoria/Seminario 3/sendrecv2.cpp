// *********************************************************************
// SCD: ejemplos del seminario 3
// ejemplo 3: difusión de un mensaje en una cadena de procesos
// *********************************************************************

#include "mpi.h"
#include <iostream>
using namespace std;
 
int main( int argc, char *argv[] ) 
{
    int        rank,
               size,
               value;
    MPI_Status status;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
 
    do 
    {   if (rank == 0) 
        {
            scanf( "%d", &value );
            MPI_Send( &value, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD ); 
        }
        else 
        {
            MPI_Recv( &value, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status );
            if ( rank < size-1 )
                MPI_Send( &value, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD );
        }
        
        cout << "Soy el proceso " << rank << " y he recibido " << value << endl ;
    } 
    while (value >= 0);
 
    MPI_Finalize(); 
    return 0;
}
