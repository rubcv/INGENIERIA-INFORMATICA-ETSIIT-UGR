// *********************************************************************
// SCD: ejemplos del seminario 3
// Ejemplo 4: Intercambio síncrono (seguro) de mensajes entre pares 
//            de procesos (sec 4).
// *********************************************************************

#include "mpi.h"
#include <iostream>

using namespace std;
 
int main(int argc, char *argv[]) 
{
    int         rank,
                size, 
                valor_enviado, 
                valor_recibido;
    MPI_Status  status;
    
    MPI_Init( &argc, &argv);
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    
    valor_enviado = rank*(rank+1) ;
    
    if ( rank % 2 == 0 ) 
    {
        MPI_Ssend( &valor_enviado,  1, MPI_INT, rank+1, 0, MPI_COMM_WORLD ); 
        MPI_Recv ( &valor_recibido, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD, &status );
    }
    else 
    {
        MPI_Recv ( &valor_recibido, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status );
        MPI_Ssend( &valor_enviado,  1, MPI_INT, rank-1, 0, MPI_COMM_WORLD );
    }
    
    cout<< "Soy el proceso " << rank << " y he recibido " << valor_recibido << endl ;
 
    MPI_Finalize(); 
    return 0;
}
