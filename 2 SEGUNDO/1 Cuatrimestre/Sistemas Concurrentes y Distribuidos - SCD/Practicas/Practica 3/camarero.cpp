#include <mpi.h>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#include <iostream>


#define coger 0
#define soltar 1
#define sentarse 2
#define levantarse 3
#define camarero 10

using namespace std;

void Filosofo (int id, int nprocesos);
void Tenedor  (int id, int nprocesos);
void Camarero ();

int main(int argc, char** argv){
  int rank, size;

  MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size != 11){
      if(rank == 0){
        cout<< "El numero de procesos debe ser 11" << endl;
      }
      MPI_Finalize();
      return 1;
    }

    if(rank != 10 && (rank % 2 == 0) ){
      Filosofo(rank, size);
    }else if(rank != 10 ){
      Tenedor(rank, size);
    }else if (rank == 10){
        Camarero();
    }


  MPI_Finalize();

  return 0;
}


void Camarero(){
  int sentados = 0;

  while(true){
    int buf;
    MPI_Status status;
    int filosofo, peticion;

    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

    // Identifica al filosofo y la peticion
    filosofo = status.MPI_SOURCE;
    peticion = status.MPI_TAG;

    if(sentados == 4){ // Si ya hay 4 sentados, solo recibe peticiones de levantarse
      peticion = levantarse;
    }

    // Recibe una peticion
      MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, peticion, MPI_COMM_WORLD, &status);
      if(peticion == sentarse){
        sentados++;
        cout<< " + CAMARERO: SE SIENTA: " << filosofo << ", Hay " << sentados << " filosofos sentados en la mesa" << endl << flush;
      }else if(peticion == levantarse){
        sentados--;
        cout<< " + CAMARERO: SE LEVANTA: " << filosofo << ", Hay " << sentados << " filosofos sentados en la mesa" << endl << flush;
      }
  }
}

void Filosofo(int rank, int nprocesos){
  int izq = (rank+1) % nprocesos;
  int der = ((rank+nprocesos)-1) % nprocesos;
  int destino, permiso;
  while(true){

      cout << " - FILOSOFO: " << rank << " PENSANDO" << endl << flush;
      usleep( 1000U * (100U+(rand()%900U)) );

      if(rank != 0){

        // Filosofo pide permiso para sentarse
        MPI_Ssend(&permiso, 1, MPI_INT, camarero, sentarse, MPI_COMM_WORLD);
        cout<< " - FILOSOFO: " << rank << " ME SIENTO" << endl << flush;

        // Solicita tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, rank + 1, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor izquierdo: " << izq << endl << flush;

        // Solicita tenedor derecho
        MPI_Ssend(&der, 1, MPI_INT, rank - 1, coger, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " coge tenedor derecho: " << der << endl << flush;

        cout<< " - FILOSOFO: " << rank << " COMIENDO" << endl << flush;
        sleep((rand() % 3)+1);  //comiendo

        // Suelta el tenedor izquierdo
        MPI_Ssend(&izq, 1, MPI_INT, rank - 1, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor izquierdo: " << izq << endl << flush;

        // Suelta el tenedor derecho
        MPI_Ssend(&der, 1, MPI_INT, rank + 1, soltar, MPI_COMM_WORLD);
        cout <<" - FILOSOFO: " << rank << " suelta tenedor derecho: " << der << endl << flush;

        // Filosofo pide permiso para levantarse
        MPI_Ssend(&permiso, 1, MPI_INT, camarero, levantarse, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " ME LEVANTO" << endl << flush;

      }else{

        // Filosofo pide permiso para sentarse
        MPI_Ssend(&permiso, 1, MPI_INT, camarero, sentarse, MPI_COMM_WORLD);
        cout<< " - FILOSOFO: " << rank << " ME SIENTO" << endl << flush;

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


        // Filosofo pide permiso para levantarse
        MPI_Ssend(&permiso, 1, MPI_INT, camarero, levantarse, MPI_COMM_WORLD);
        cout << " - FILOSOFO: " << rank << " ME LEVANTO" << endl << flush;
      }


  }
}

void Tenedor(int rank, int nprocesos){
  int buf;
  MPI_Status status;
  int filosofo;

  while(true){
    // Espera una peticion de cualquier filosofo
    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

    // Identifica al filosofo
    filosofo = status.MPI_SOURCE;

    // Recibe su peticion de coger y lo desbloquea (El filosofo hace un Ssend())
    cout << " * Tenedor: " << rank << " recibe peticion de filosofo: " << filosofo << endl << flush;
    MPI_Recv(&buf, 1, MPI_INT, filosofo, coger, MPI_COMM_WORLD, &status);

    // Recibe su peticion de soltar y desbloquea al filosofo (El filosofo hace un Ssend())
    cout << " * Tenedor: " << rank << " recibe liberacion de filosofo: " << filosofo << endl << flush;
    MPI_Recv(&buf, 1, MPI_INT, filosofo, soltar, MPI_COMM_WORLD, &status);
  }
}
