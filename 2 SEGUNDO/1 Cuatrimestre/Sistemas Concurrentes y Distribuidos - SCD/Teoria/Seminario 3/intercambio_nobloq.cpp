// *********************************************************************
// SCD: ejemplos del seminario 3
// Ejemplo 6: Intercambio asíncrono (inseguro) de mensajes entre pares 
//            de procesos (sec 5).
// *********************************************************************

#include "mpi.h"
#include <iostream>

using namespace std;
 
int main( int argc, char *argv[] ) 
{
    int         rank, 
                size, 
                vecino, 
                valor_enviado, 
                valor_recibido;
    MPI_Status  status;
    MPI_Request request_send,
                request_recv;
 
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    
    valor_enviado = rank*(rank+1) ;

    if ( rank % 2 == 0 ) 
        vecino = rank+1 ;
    else 
        vecino = rank-1 ;

    // las siguientes dos llamadas pueden aparecer en cualquier orden   
    MPI_Irecv( &valor_recibido, 1, MPI_INT, vecino, 0, MPI_COMM_WORLD, &request_recv );
    MPI_Isend( &valor_enviado,  1, MPI_INT, vecino, 0, MPI_COMM_WORLD, &request_send ); 
    
    MPI_Wait( &request_send, &status );   
    MPI_Wait( &request_recv, &status ); 

    cout<< "Soy el proceso " << rank << " y he recibido " << valor_recibido << endl ;
    
    MPI_Finalize(); 
    return 0;
}







