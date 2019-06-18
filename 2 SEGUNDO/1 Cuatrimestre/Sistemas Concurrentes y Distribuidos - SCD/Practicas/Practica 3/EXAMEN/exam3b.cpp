


#include <mpi.h>
#include <iostream>
#include <math.h>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"

const int NPROD = 5;
const int NCONS = 4;
const int Buffer = NPROD + NCONS - 1;    
const int Consola = Buffer + 1; 
const int Barrera = Consola + 1;
#define ITERS       20
#define TAM          5
#define Productor    4
#define Consumidor   6

using namespace std;





/*
CAMBIAR ITERACIONES DEL BUCLE:

  Buffer -> 20 * 10 = 200;
  5 Prod -> 20 * 5 = 100;
  4 Cons -> 20 * 4 = 80;

  -> Haces 180 consumiciones y 200 producciones, luego tienes que cambiar las iteraciones del consumidor a 25 para
  que las producidas y consumidas sean 200

*/

// ---------------------------------------------------------------------

void barrera(){
	
	int rondas[NCONS];
	for(int i = 0; i < NCONS; i++){
		rondas[i] = 0;
	}
	MPI_Status status;
	int peticion;
	int veces = 0;
	
	while(true){
	
      MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      
		for(int i = 0; i < NCONS; i++){
			if(rondas[i] < 15){ // Si sus rondas son menores que 15
			
				if(status.MPI_TAG == i + 5){ // Si la etiqueta es i (+ 5 para saltarse los 5 productores )
      			  MPI_Recv( &peticion, 1, MPI_INT, status.MPI_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
      			  rondas[i]++;
				
					for(int j = 0; j < NCONS; j++){ // Se comprueban las rondas de todos los consumidores
						veces += rondas[j];
					}
					if(veces == 15*NCONS){ // Si todos han completado las 15
						for(int k = 0; k < NCONS; k++){
							rondas[k] = 0; // Se vuelven a poner a 0
						}
					}
				}
				veces = 0;
			}
		}
	}
}

// ---------------------------------------------------------------------


void consola(int size){

	int valor;
	MPI_Status status;
	
	while(true){
	
		MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		if(status.MPI_TAG == 0){
			if(status.MPI_SOURCE < NPROD){
			  cout << "Productor " << status.MPI_SOURCE << " produce valor " << valor << endl << flush ;
			}else if(status.MPI_SOURCE > NPROD && status.MPI_SOURCE != Buffer){
				cout << "Consumidor " << size - status.MPI_SOURCE - 1 << " recibe valor " << valor << " de Buffer " << endl << flush ;
			}else if(status.MPI_SOURCE == Buffer){
				cout << "Buffer envía " << valor << " a Consumidor " << endl << flush;
			}
		}else{
			if(status.MPI_SOURCE < NPROD){
			  cout << "Productor " << status.MPI_SOURCE << " produce valor " << valor << endl << flush ;
			}else if(status.MPI_SOURCE > NPROD && status.MPI_SOURCE != Buffer){
				cout << "Consumidor "<< size - status.MPI_SOURCE - 1 << "  recibe valor " << valor << " de Buffer " << endl << flush ;
			}else if(status.MPI_SOURCE == Buffer){
				cout << "Buffer envía " << valor << " a Consumidor " << endl << flush;
			}
		}	
	}
}


// ---------------------------------------------------------------------

void productor()
{
   int value = 0;

  while(true)
   {
      
      //cout << "Productor produce valor " << value << endl << flush ;
	  MPI_Ssend( &value, 1, MPI_INT, Consola, 0, MPI_COMM_WORLD );
      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );

      // enviar 'value'
      MPI_Ssend( &value, 1, MPI_INT, Buffer, Productor, MPI_COMM_WORLD );
      
      value++;
   }
}
// ---------------------------------------------------------------------

void buffer()
{
   int        value[TAM] ,
              peticion ,
              pos  =  0,
              rama ;
   MPI_Status status ;

  while(true)
   {


     // calcular la rama en función del origen del mensaje
     if(pos == 0){
       rama = 0;
     }else if(pos == TAM){
      rama = 1;
    }else{     // leer 'status' del siguiente mensaje (esperando si no hay)
      MPI_Probe( MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
    }



    switch (rama) {
      case 0:
        MPI_Recv( &value[pos], 1, MPI_INT, MPI_ANY_SOURCE, Productor, MPI_COMM_WORLD, &status );
        MPI_Ssend( &value[pos], 1, MPI_INT, Consola, 0, MPI_COMM_WORLD);
        // cout << "Buffer recibe " << value[pos] << " de Productor " << endl << flush;
        pos++;
        break;
      case 1:
        MPI_Recv( &peticion, 1, MPI_INT, MPI_ANY_SOURCE, Consumidor, MPI_COMM_WORLD, &status );
        MPI_Ssend( &value[pos-1], 1, MPI_INT, status.MPI_SOURCE, Consumidor, MPI_COMM_WORLD);
        MPI_Ssend( &value[pos-1], 1, MPI_INT, Consola, 1, MPI_COMM_WORLD);
       // cout << "Buffer envía " << value[pos-1] << " a Consumidor " << endl << flush;
        pos--;
        break;
    }
  }
}




// ---------------------------------------------------------------------

void consumidor(int rank)
{
   int         value,
               peticion = 1 ;
   float       raiz ;
   MPI_Status  status ;

   while(true)
   {
      MPI_Ssend( &peticion, 1, MPI_INT, Barrera, rank, MPI_COMM_WORLD ); // Se le manda el rank como etiqueta a la barrera para que identifique al consumidor
      MPI_Ssend( &peticion, 1, MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD );
      MPI_Recv ( &value, 1,    MPI_INT, Buffer, Consumidor, MPI_COMM_WORLD,&status );
      MPI_Ssend( &value, 1, MPI_INT, Consola, 0, MPI_COMM_WORLD );
//      cout << "Consumidor recibe valor " << value << " de Buffer " << endl << flush ;

      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );

      raiz = sqrt(value) ;
   }
}
// ---------------------------------------------------------------------

int main(int argc, char *argv[])
{
   int rank,size;



   // inicializar MPI, leer identif. de proceso y número de procesos
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );

   // inicializa la semilla aleatoria:
   srand ( time(NULL) );

   // comprobar el número de procesos con el que el programa
   // ha sido puesto en marcha (debe ser 10)
   
   int nProcesos = NPROD + NCONS + 1 + 1 + 1; // +1 del buffer 
   
   if ( size != nProcesos)
   {
     if(rank == 0)
      cout<< "El numero de procesos debe ser "<< nProcesos <<endl;
      MPI_Finalize( ); // Para que no aparezcan -np mensajes, terminamos MPI antes de la salida
      return 0;
   }

   // verificar el identificador de proceso (rank), y ejecutar la
   // operación apropiada a dicho identificador
   if ( rank < NPROD)
      productor();
   else if ( rank == Buffer )
      buffer();
   else if(rank == Consola)
   	consola(size);   // Para que imprima el numero de cada proceso dentro de su tipo
   else if(rank == Barrera)
   		barrera();
   else if(rank > NPROD)
      consumidor(rank); // Para que la barrera identifique al consumidor

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}
