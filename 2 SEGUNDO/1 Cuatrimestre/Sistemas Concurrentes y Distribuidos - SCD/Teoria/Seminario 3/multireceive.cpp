// *********************************************************************
// SCD: ejemplos del seminario 3
// Ejemplo 5: Sondeo continuo de varias fuentes desconocidas (sec 5).
// *********************************************************************

#include "mpi.h"
#include <librerias.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int         rank ,
                size ,
                flag ,
                buf ,
                src ,
                tag ;
    MPI_Status  status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    if ( rank == 0 )
    {
        int contador = 0 ;
        while ( contador < 10*(size-1) )
        {
            MPI_Iprobe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status );
            if ( flag > 0 )
            {
                MPI_Recv( &buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
                src = status.MPI_SOURCE ;
                tag = status.MPI_TAG ;
                cout << "Mensaje de " << src << " con tag = " << tag << endl ;
                contador++ ;
            }
            sleep(1);
        }
        cout<< "Total de mensajes recibidos: "<< contador << endl << flush ;
    }
    else
        for ( int i = 0 ; i <10 ; i++ )
            MPI_Send( &buf, 1, MPI_INT, 0, i, MPI_COMM_WORLD );

    MPI_Finalize();
    return 0;
}
