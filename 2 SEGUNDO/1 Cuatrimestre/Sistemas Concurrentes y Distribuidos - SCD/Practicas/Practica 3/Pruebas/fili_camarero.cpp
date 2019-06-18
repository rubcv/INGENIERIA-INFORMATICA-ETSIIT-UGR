#include "mpi.h"
#include <iostream>
#include "math.h"
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
//#define Filo 0;
//#define Tener 1;
#define coger 0
#define soltar 1
#define CamareroID 10
#define sentarse 2
#define levantarse 3
using namespace std;

void Camarero(int id, int total_procesos){

  int sentados = 0;

  while(true){
    MPI_Status status;
    int etq = MPI_ANY_TAG;
    int camarero;
    if(sentados == 4){
      etq = levantarse;
    }
    MPI_Probe( MPI_ANY_SOURCE, etq, MPI_COMM_WORLD, &status );
    MPI_Recv( &camarero, 1, MPI_INT, MPI_ANY_SOURCE, etq, MPI_COMM_WORLD, &status);
    if(status.MPI_TAG == levantarse){
      sentados--;
    }else{
      sentados++;
    }
    cout<< "Camarero: Hay " << sentados << " filosofos sentados" << endl;
    cout<< "Camarero: Me piden permiso y se lo doy a " <<  status.MPI_SOURCE << endl;
    MPI_Send( &camarero, 1, MPI_INT, status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD);
  }
}



void Filosofo(int id,int total_procesos)
{
  int izq=id+1; //tenedor izq del proceso a la izquierda
  int dcha=(id-1+total_procesos)%total_procesos;
  int permiso;
  while (true)
  {
    // Permiso
    MPI_Status status;
    MPI_Send( &permiso, 1, MPI_INT, CamareroID, sentarse, MPI_COMM_WORLD );
    MPI_Recv ( &permiso, 1,    MPI_INT, CamareroID, sentarse, MPI_COMM_WORLD, &status );
      /*
        cojo el filosofo 0,4,8 UNO SI Y OTRO NO
        Para que no haya interbloqueo
        Pk si todos envian y esperan a que el otro reciba,
        El que recive como esta esperando, nunca recivira
      */
  	//SI TODOS ME COGEN EL TENEDOR IZQUIERDO SE PRODUCIRA INTERBLOQUEO
  	//PUEDO PONER QUE SOLO UN FILOSOFO HAGA PRIMERO COGER DE FORMA DIFERENTE
      if(id%4==0)
      {
        // solicita tenedor izquierdo
        MPI_Ssend(&id,1,MPI_INT,izq,coger, MPI_COMM_WORLD);
        cout << "Filosofo " << id << " Coge tenedor izq. " << izq << endl;
        // solicita tenedor derecho
        MPI_Ssend(&id,1,MPI_INT,dcha,coger,MPI_COMM_WORLD);
        cout << "Filosofo " << id << " Coge tenedor  der. " << dcha << endl;
      }
      else
      {
      		// solicita tenedor derecho
      		cout << "Filosofo " << id << " coge tenedor der. " << dcha << endl;
       		 MPI_Ssend(&id,1,MPI_INT,dcha,coger,MPI_COMM_WORLD);
       		// solicita tenedor izquierdo
       		cout << "Filosofo " << id << " coge tenedor izq. " << izq << endl;
        	MPI_Ssend(&id,1,MPI_INT,izq,coger, MPI_COMM_WORLD);


      }
      cout << "Filosofo " << id << " COMIENDO" << endl ;
      sleep( (rand()%3)+1 ); // comiendo

      // suelta el tenedor izquierdo
      cout << "Filosofo "<<id<< " suelta tenedor izq. " << izq << endl;
      MPI_Ssend(&id,1,MPI_INT,izq,soltar, MPI_COMM_WORLD);

      // suelta el tenedor derecho
      cout << "Filosofo " << id << " suelta tenedor der. " << dcha << endl;
      MPI_Ssend(&id,1,MPI_INT,dcha,soltar,MPI_COMM_WORLD);

      cout<< "Filosofo " << id << " permiso para levantarme" << endl;
      MPI_Send( &permiso, 1, MPI_INT, CamareroID, levantarse, MPI_COMM_WORLD );
      MPI_Recv ( &permiso, 1,    MPI_INT, CamareroID, levantarse, MPI_COMM_WORLD, &status );


      cout << "Filosofo " << id << " PENSANDO" << endl;
      sleep( (rand()%3)+1 ); // pensando
  }
}

/////////////////////////////TENEDOR///////////////////////////////////////////
void Tenedor( int id, int nprocesos )
{
int  DATO_Recibir;

	MPI_Status status;
		while ( true )
		{ // Espera un peticion desde cualquier filosofo vecino ...
		MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );


		// Recibe la peticion del filosofo ...
		MPI_Recv(&DATO_Recibir,1,MPI_INT,MPI_ANY_SOURCE,coger,MPI_COMM_WORLD,&status);
		cout << "Tenedor. " << id << " recibe petic. de Filosofo[" << DATO_Recibir << "]"<<endl;
		// Espera a que el filosofo suelte el tenedor...
		MPI_Recv(&DATO_Recibir,1,MPI_INT,MPI_ANY_SOURCE,soltar,MPI_COMM_WORLD,&status);
		cout << "Tenedor. " << id << " recibe liberac. de Filosofo[" << DATO_Recibir << endl ;
		}
}
////////////////////////////MAIN///////////////////////////////////
int main(int argc, char  *argv[])
{
  int rank,size;
  MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(size!=11)
    {
      MPI_Finalize();
      cerr<<"Error con el numero de procesos, debe de ser 11"<<endl;
      return 1;
    }
    if(rank != 10 && rank%2==0 )
    {
      Filosofo(rank,size);
    }
    else if(rank != 10)
    {
      Tenedor(rank,size);
    }else if ( rank == 10){
      Camarero(rank, size);
    }

  MPI_Finalize();
  return 0;
}
