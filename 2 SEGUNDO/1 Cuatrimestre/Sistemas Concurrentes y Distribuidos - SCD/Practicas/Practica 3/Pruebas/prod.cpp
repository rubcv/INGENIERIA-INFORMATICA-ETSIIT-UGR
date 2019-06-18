#include "mpi.h"
#include <iostream>
#include "math.h"
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
/*
		mpicxx PROD.cpp -o prod
		mpirun -np 6 INTERSINCRO
		Procesos pares mejor
*/
#define Productor 0  //identificador de la etiqueta
#define Buffer 5   //el proceso nº5 es el buffer
#define Consumidor 1 //identificador de la etiqueta
#define ITERS 20
#define TAM    5
using namespace std;
//////////////////////////////////PRODUCTOR/////////////////////////////////////////////
void productor(int elemento)
{
	int dato;
  for( unsigned int i = 0 ; i < ITERS/5; i++) //divido entre 5 pk tengo 20 iteraciones y 5 productores
  {
  	 dato=elemento*10+i;
     cout << "Productor ["<<elemento<<"]"<< "produce valor "<< dato << endl ;
     MPI_Ssend( &dato, 1, MPI_INT, Buffer, Productor, MPI_COMM_WORLD );//Yo quiero enviar al Buffer y su etiqueta=productor
     // espera bloqueado durante un intervalo de tiempo aleatorio
     // (entre una décima de segundo y un segundo)
     usleep( 1000U * (100U+(rand()%900U)) );

   }
   int rank;
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );				//se introduce el id del proceso en la variable rank
	cout<< ".........Productor "<<rank<<" ha terminado..."<<endl<<flush;
}
//////////////////////////////////CONSUMIDOR/////////////////////////////////////////////
void consumidor(int elemento)
{
  int value, peticion=1;
  float raiz;
  MPI_Status status;
  int nombre=elemento % 4;//Los consumidores son el proceso 5,6,7,8 digamos que hago que si es el primero consumidor es el 5, 5%4=1
  for( unsigned int i = 0 ; i < ITERS/4 ; i++ )//Al ser solo 4 consumidores, divido entre 5 pk tengo 20 iteraciones
  {
     MPI_Ssend( &peticion, 1, MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD );
     MPI_Recv ( &value,1, MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD, &status);//El Consumidor guarda el dato
     cout << "Consumidor ["<<nombre<<"]  recibe valor "<<value<<" de Buffer "<<endl ;
     // espera bloqueado durante un intervalo de tiempo aleatorio
     // (entre una décima de segundo y un segundo)
     usleep( 1000U * (100U+(rand()%900U)) );
     raiz = sqrt(value);
   }
   int rank;
	MPI_Comm_rank( MPI_COMM_WORLD, &rank );
	cout<< "........Consumidor "<<rank<<" ha terminado..."<<endl<<flush;
}
//////////////////////////////////BUFFER////////////////////////////////////////////////
void buffer()
{
  int value[TAM];
  int peticion;
  MPI_Status status;
  int pos=0;
  int rama;
  int num=0;
  int task=0;
  for( unsigned int i = 0 ; i < ITERS*2 ; i++ ) //SON 40 20--->productor y 20---->consumidor
  {
  	if(pos==0)
  	{
  		rama=0; //El consumidor no puede consumir, buffer vacio  PRODUCIRA EL productor
  	}
  	else
  	{
  		if(pos==TAM)//El productor no puede producir, el buffer esta lleno
  		{
  			rama=1;
  		}

	  	else
	  	{
	  		 /*Retorna sólo cuando hay algún mensaje que encaje con los argumentos.
				 ▸ Permite esperar la llegada de un mensaje sin conocer su procedencia,
				 	 etiqueta o tamaño.*/
		     MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );//status, almacena la etiqueta entera del mensaje(quien la enviado,etiqueta, etc)
		     if (status.MPI_SOURCE < Buffer)
		     	rama =0; //como los procesos productores son los del 0 al 4 llevarán en rama = 0 (tag)
		     else
		     	rama=1;

		     /*
		     	otra manera es:
		     						if (status.MPI_TAG == Productor) //AQUI ES CON LA ETIQUETA
		     							rama =0;
		    						else
		     							rama=1;
		     */
	  	}
	 }

	// std::cout << "RAMA" << rama<<endl;

	 switch(rama)
	 {
		 case 0://PRODUCTOR  Uso el tag=productor
			 //El buffer recive al productor
			 MPI_Recv( &value[pos], 1, MPI_INT, MPI_ANY_SOURCE, Productor, MPI_COMM_WORLD, &status );//El id del proceso me da igual--> MPI_ANY_SOURCE
			 task=status.MPI_SOURCE ;  //saco quien lo ha enviado al buffer osea el id del proceso
			 cout << "BUFFER recibe " << value[pos] << " de Productor [" << task <<"]" <<endl;
			 pos++;
			 break;
		 case 1://CONSUMIDOR uso el tag=consumidor
			 MPI_Recv( &peticion, 1, MPI_INT, MPI_ANY_SOURCE, Consumidor, MPI_COMM_WORLD, &status );//eTIQUETA-->> Consumidor,, id de cualquiera
			 // En vez de poner MPI_ANY_SOURCE y luego calcular task = status.MPI_SOURCE ;---> directamente me ahorro hacer eso
			 task=status.MPI_SOURCE;
			 num = status.MPI_SOURCE % 4 ; //como los consumidores van a tener ei id 6,7,8,9, pues le hago el modulo, el 5 es el buffer y de 0...4 son los productores
			 // envíamos al tag del que recibimos.
			 pos--;
					 MPI_Ssend( &value[pos], 1, MPI_INT, task, Consumidor , MPI_COMM_WORLD);//el buffer envia el dato al consumidor
					 cout << "Buffer envía " << value[pos] << " a Consumidor " << num << endl;

					 break;
	 }
  }
}
/////////////////////////////////////MAIN/////////////////////////////////////////////////
int main(int argc, char *argv[])
{
   int rank,size;

   // inicializar MPI, leer identif. de proceso y número de procesos
     MPI_Init( &argc, &argv );
	   MPI_Comm_rank( MPI_COMM_WORLD, &rank ) ;
     MPI_Comm_size( MPI_COMM_WORLD, &size ) ;

		 //srand ( time(NULL) );
		 // comprobar el número de procesos con el que el programa
	   // ha sido puesto en marcha (debe ser 10)
		 if(size!=10)
     {
     	cerr<<"error numero de procesos incorrecto, debe de ser 10"<<endl;
			return 1;
     }
     if ( rank < 5 /*bufer*/) // Procesos 0,1,2,3 y 4
     	 productor(rank) ;				//LE PASO COMO PARAMETRO EL RANK por hacer cosas diferente
     else
     {	if ( rank == Buffer ) // Proceso 5
     		buffer() ;
        else
        	consumidor(rank) ;	// Procesos 6,7,8 y 9  //LE PASO COMO PARAMETRO EL RANK
      }

      MPI_Finalize( ) ;
      return 0;
}
