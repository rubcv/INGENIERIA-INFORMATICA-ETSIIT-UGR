#include "mpi.h"
#include <iostream>
#include "math.h"
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#define ITER 30
#define  TAM 4
#define BUFFER 8
#define Productor 0
#define Consumidor 1
using namespace std;
////////////////////////////////PRODUCTOR///////////////////////////////////////
void prod(int id)
{
  int dato=id;
  for (int  i = 0; i < ITER/3; i++)
  {
    dato=id;
    cout<<"El productor ["<<id<<"] produce: ("<<dato<<")"<<endl;
    MPI_Ssend(&dato,1,MPI_INT,BUFFER,Productor,MPI_COMM_WORLD);
    usleep( 1000U * (100U+(rand()%900U)) );
  }

  //int rank;
  //MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  cout<<".......................El productor["<<id<<"] ha terminado"<<endl;
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////CONSUMIDOR//////////////////////////////////////
void cons(int id)
{
  int dato;
  int peticion=0;
  MPI_Status status;
  for (int i = 0; i < ITER/5; i++)
  {
    usleep( 2000U * (100U+(rand()%900U)) );
    MPI_Ssend(&peticion,1,MPI_INT,BUFFER,Consumidor,MPI_COMM_WORLD);
    MPI_Recv(&dato,1,MPI_INT,BUFFER,Consumidor,MPI_COMM_WORLD,&status);
    cout<<"El CONSUMIDOR ["<<id<<"] Recive  del bufer el valor: (("<<dato<<"))"<<endl;

  }
  cout<<".......................El Consumidor["<<id<<"] ha terminado"<<endl;
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////BUFFER//////////////////////////////////////
void buff()
{
  MPI_Status status;
  int vector[TAM];
  int pos=0;
  int peticion;
  int contador=0;
  int vaciando;
  int rama;
  for (int i = 0; i < ITER*2; i++)
  {
    if(pos==0 )
    {
      rama=0;//el consumidor no puede consumir
      vaciando=0;
    }
    else
    {  if(pos==TAM  || vaciando)
        rama=1;//en este caso el productor no pude producir
      else
      {
        MPI_Probe(MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
        if(status.MPI_TAG==Productor)
          rama=0;
        else
          rama=1;
      }

    }
  //cout<<"Rama-->"<<rama<<endl;
/**************************************************/
        cout<<"CONTADOR-->"<<contador<<endl;
        for (int i = 0; i < TAM; i++)
        {
        cout<<"["<<vector[i]<<"] ";
        }
        cout  <<'\n';
/***************************************************/
        int dato;
        switch (rama)
        {
          case 0:
            MPI_Recv(&vector[pos],1,MPI_INT,MPI_ANY_SOURCE,Productor,MPI_COMM_WORLD,&status);
            cout<<"+++++BUFFER recive el  valor["<<vector[pos]<<"]del productor["<<status.MPI_SOURCE<<"]"<<endl;
            pos++;
            contador++;
            if(contador==10)
            {
              vaciando=1;
              contador=0;
              cout << "\n************ 10 PRODUCCIONES, PROCEDEMOS A VACIAR EL VECTOR ************" << '\n';
            }
            break;

          case 1:
            MPI_Recv(&peticion,1,MPI_INT,MPI_ANY_SOURCE,Consumidor,MPI_COMM_WORLD,&status);
            int id=status.MPI_SOURCE%4;//esto es para ponerlo bonito a la hora de imprimir en pantalla
            int task=status.MPI_SOURCE;//este es digamos el verdadero id
            pos--;

            MPI_Ssend(&vector[pos],1,MPI_INT,task,Consumidor,MPI_COMM_WORLD);
            cout<<"+++++El Buffer envia al consumidor["<<id<<"] el valor [["<<vector[pos]<<"]]"<<endl;
            break;

        }
   }

}

int main(int argc, char  *argv[])
{
  int size,rank;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  if(size!=9)
  {
    std::cerr << "ERROR nuemero de procesos es 9" << '\n';
    return 1;
  }
  if(rank==8)
    buff();
  else
  {
    if(rank<5)
      cons(rank);
    else
        prod(rank);
  }

  MPI_Finalize();
  return 0;
}
