#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
  int rank,size, recibido;
  MPI_Status estado;
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank != 0){

    // Envias al siguiente, y si eres el 3, al 0
    MPI_Ssend(&rank, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD); // Haces primero el envio para dar paso, si recibes antes de enviar te quedas bloqueado
    // Recibes del anterior y si eres 0 del 3
    MPI_Recv(&recibido, 1, MPI_INT, (size + rank -1) % size, 0, MPI_COMM_WORLD, &estado);

    cout<< "Rank: " << rank << endl;
    cout<< "Dato recibido: " << recibido << endl;

    MPI_Finalize();
  }else{
    // Recibes del anterior y si eres 0 del 3
    MPI_Recv(&recibido, 1, MPI_INT, (size + rank -1) % size, 0, MPI_COMM_WORLD, &estado);

    // Envias al siguiente, y si eres el 3, al 0
    MPI_Ssend(&rank, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD); // Haces primero el envio para dar paso, si recibes antes de enviar te quedas bloqueado

    cout<< "Rank: " << rank << endl;
    cout<< "Dato recibido: " << recibido << endl;

    MPI_Finalize();

  }

}
