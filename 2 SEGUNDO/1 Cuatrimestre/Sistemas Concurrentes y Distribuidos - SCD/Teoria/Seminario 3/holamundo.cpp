// *********************************************************************
// SCD: ejemplos del seminario 3
// ejemplo 1: impresion de mensajes en pantalla
// *********************************************************************

#include "mpi.h"
#include <iostream>
using namespace std;

int main( int argc, char *argv[] )
{
    int rank, 
        size ;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    cout << "Hola desde proceso " << rank << " de " << size << endl << flush ;
    
    MPI_Finalize();
    return 0;
}
