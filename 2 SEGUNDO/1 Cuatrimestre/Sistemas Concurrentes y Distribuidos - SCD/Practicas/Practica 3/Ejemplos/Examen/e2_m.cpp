#include "mpi.h"
#include <iostream>
#include "math.h"
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
using namespace std;
#define MOSTRADORES 0
#define ALU_MOS 1
#define FIN_SERVICIO 2
#define CONTROLADOR 12
#define PETICION 3 // va a ser como una bandera indicando que el un mostrador en la pos x esta ocupado

void mostrador(int id)
{
    MPI_Status status;
    while (true)
    {
      int dato=1,id_alum,alumno;
      //MPI_SOURCE-->CUALQUIER id alumno, Etiqueta-->ALU_MOS
      MPI_Recv(&id_alum,1,MPI_INT,MPI_ANY_SOURCE,ALU_MOS,MPI_COMM_WORLD,&status);
      alumno=status.MPI_SOURCE;
      //libre++;
      cout<<"Alumno ["<<alumno<<"] entra en el motrador["<<id<<"]"<<endl;
      usleep( 2000U * (100U+(rand()%900U)) );
      cout<<"Alumno ["<<alumno<<"] Procede a FIN de tramite en el motrador ["<<id<<"]"<<endl;
      MPI_Ssend(&id,1,MPI_INT,alumno,ALU_MOS,MPI_COMM_WORLD);
      //libre--;
    }
}

void alumnos(int id)
{
    MPI_Status status;
  while (true)
  {
      int peticion=1;
      int most_asignado;
      int id_mostrador;
      cout<<"Alumno ["<<id<<"] Envia peticion  al CONTROLADOR"<<endl;
      MPI_Ssend(&peticion,1,MPI_INT,CONTROLADOR,PETICION,MPI_COMM_WORLD);//puedo poner Send pk justo tengo un Recv a continuacion
      //DIGAMOS que el contralador me tiene que devolver que mostrador esta libre que sera el rank para enviar
      MPI_Recv(&most_asignado,1,MPI_INT,CONTROLADOR,100,MPI_COMM_WORLD,&status);//EL DATO SI IMPORTA AQUI pk es el mostrador libre
      cout<<"Controlador indica al alumno["<<id<<"] el mostrador libre ["<<most_asignado<<"] Y SE VA DIRECTO"<<endl;
      MPI_Ssend(&id,1,MPI_INT,most_asignado,ALU_MOS,MPI_COMM_WORLD);//EL DATO A ENVIAR TAMBIEN ME LA SOPLA      AQUI tambien podria poner un Send
      MPI_Recv(&id_mostrador,1,MPI_INT,most_asignado,ALU_MOS,MPI_COMM_WORLD,&status);//lo que envio me da igual  AQUI SI ES IMPORTANTE LA ETIQUETA(aunque yo he puesto en todas igual)
      cout << "El alumno[" <<id<<"] ha salido del mostrador["<<id_mostrador<<"] \n SERVICIO COMPLETADO"<<endl;//PODRIA poner id_mostrador==most_asignado
      //envio al controlador se servicio completado con el mostrador liberado
      MPI_Ssend(&most_asignado,1,MPI_INT,CONTROLADOR,FIN_SERVICIO,MPI_COMM_WORLD);
      usleep( 2000U * (100U+(rand()%900U)) );
   }
}

void Control(int id)
{
  int emisor=0,dato;
  int libre=3;
  while (true)
  {
      MPI_Status status;
      int rama;
      int peticion;
      int mostrador;
      int alumno;
      bool vector[]={true,true,true};
      if(libre==0)//no quedan libres
      {
        MPI_Recv(&mostrador,1,MPI_INT,MPI_ANY_SOURCE,FIN_SERVICIO,MPI_COMM_WORLD,&status);
        cout<<"Controlador ha recibido  del alumno ["<<status.MPI_SOURCE<<"] la finalizacion del mostrador["<<mostrador<<"]"<<endl;
      }
      else
      {
         MPI_Recv(&mostrador,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);//meto en vector[pos]=peticion
                    alumno=status.MPI_SOURCE;
      }
      if(status.MPI_TAG==FIN_SERVICIO)
      {
          libre++;
          vector[mostrador]=true;
      }
      else
      {
        if(status.MPI_TAG==PETICION)
         { libre--;
          mostrador=0;//utilizo como los id de los mostradores
          while(mostrador<3  && !vector[mostrador])
          {
            mostrador++;
          }
          vector[mostrador]=false;
          MPI_Ssend(&mostrador,1,MPI_INT,status.MPI_SOURCE,100,MPI_COMM_WORLD);//puedo poner un send
        }
      }





   }
}

int main(int argc, char  *argv[])
{
  int rank,size;
  MPI_Init( &argc, &argv );

    MPI_Comm_rank( MPI_COMM_WORLD, &rank ) ;
    MPI_Comm_size( MPI_COMM_WORLD, &size ) ;

    if(size!=13)
    {
     cerr<<"error numero de procesos incorrecto, debe de ser 13"<<endl;
     return 1;
    }
    if ( rank < 3 /*motradores*/) // Procesos 0,1,2
      mostrador(rank) ;				//LE PASO COMO PARAMETRO EL RANK por hacer cosas diferente
    else
    {
       if ( rank == CONTROLADOR ) // Proceso 12
        Control(rank) ;
       else
        alumnos(rank) ;	// Procesos 3,4,5,6,7,8,9,10,11  //LE PASO COMO PARAMETRO EL RANK
    }


  MPI_Finalize( ) ;
  return 0;
}
