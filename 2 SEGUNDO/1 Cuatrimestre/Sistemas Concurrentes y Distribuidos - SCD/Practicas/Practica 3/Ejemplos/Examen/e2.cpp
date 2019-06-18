#include <iostream>
#include <unistd.h>
#include <mpi.h>


#define levantarse 1

using namespace std;


void Alumno(){
  int mostr, aux;
  MPI_Status status;
  while(1){
    MPI_Send(&mostr, 1, MPI_INT, 12, 2, MPI_COMM_WORLD);
    MPI_Recv(&mostr, 1, MPI_INT, 12, 2, MPI_COMM_WORLD, &status);

    MPI_Send(&mostr, 1, MPI_INT, mostr, 0, MPI_COMM_WORLD); // Mandas al rank del mostrador que has recibido
    MPI_Recv(&aux, 1, MPI_INT, mostr, 0, MPI_COMM_WORLD, &status); // Recibes del mismo mostrador


    MPI_Send(&mostr, 1, MPI_INT, 12, levantarse, MPI_COMM_WORLD); // Le devuelves al controlador el mostrador que has soltado
  }


  // while(true){
  //   int peticion, mostrador;
  //   MPI_Status status;
  //   MPI_Ssend(&peticion, 1, MPI_INT, 12, entrar, MPI_COMM_WORLD); // Manda peticion al Controlador
  //   cout<< " - ALUMNO: Aviso al controlador" << endl;
  //   MPI_Recv(&peticion, 1, MPI_INT, 12, mostrador, MPI_COMM_WORLD, &status); // Recibe el mostrador al que tiene que ir
  //   cout<< " - ALUMNO: Controlador me manda al mostrador " << mostrador << endl;
  //   MPI_Ssend(&peticion, 1, MPI_INT, peticion, 0, MPI_COMM_WORLD); // Manda peticion al mostrador
  //   cout<< " - ALUMNO: Mando peticion al mostrador " << mostrador << endl;
  // }
}

void Mostrador(){
  int aux;
  MPI_Status status;


  while(1){
    MPI_Recv(&aux, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
    sleep(1);

    MPI_Ssend(&aux, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
  }

  // while(true){
  // int dato, libre = -1; // Empieza estando libre
  // MPI_Status status;
  //   MPI_Recv(&dato, 1, MPI_INT, 12, MPI_ANY_TAG, MPI_COMM_WORLD, &status); // Recibe aviso del Controlador
  //   cout<< " + MOSTRADOR: Recibo aviso del controlador" << endl;
  //   MPI_Send(&dato, 1, MPI_INT, 12, libre, MPI_COMM_WORLD); // Le comunica si esta libre
  //   cout<< " + MOSTRADOR: Mi estado es: " << libre << " se lo comunico al controlador" << endl;
  //
  //   libre = 1; // Se ocupa
  //   cout<< " + MOSTRADOR: Recibo la peticion del alumno" << endl;
  //   MPI_Recv(&dato, 1, MPI_INT, MPI_ANY_SOURCE, entrar, MPI_COMM_WORLD, &status); // Recibe la peticion del alumno
  // }
}


void Controlador(){
  int contLibres = 3;
  bool mostradoresLibres[] = {true, true, true};
  int mostr;
  MPI_Status status;

  while(1){
    if(contLibres == 0){
      MPI_Recv(&mostr, 1, MPI_INT, MPI_ANY_SOURCE, levantarse, MPI_COMM_WORLD, &status); // Solo acepto que se levanten

    }else{
      MPI_Recv(&mostr, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status); // Acepto de cualquiera
    }

    if(status.MPI_TAG == levantarse){ // Si el que llega es de levantarse, aumento los libres
      contLibres++;
      mostradoresLibres[mostr] = true; // Lo pongo a libre
    }else{
      contLibres--;
      mostr = 0;
      while(!mostradoresLibres[mostr] && mostr < 3){
        mostr++;
      }
      mostradoresLibres[mostr] = false;

      MPI_Send(&mostr, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD); // El mensaje es mostr

    }
  }


  // while(true){
  //   int peticion, tag, mostrador = 0;
  //   int libre = -1;
  //   MPI_Status status;
  //
  //   MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status); // Identifica de quien viene el mensaje
  //
  //   cout<< " * CONTROLADOR: Recibo peticion del alumno " << status.MPI_SOURCE << endl;
  //   MPI_Recv(&peticion, 1, MPI_INT, status.MPI_SOURCE, entrar, MPI_COMM_WORLD, &status); // Recibe la peticion de entrar del alumno
  //
  //   cout<< " * CONTROLADOR: Compruebo los mostradores" << endl;
  //   while(tag != libre && mostrador < 3){ // Comprueba los 3 mostradores hasta encontrar uno libre
  //     MPI_Send(&peticion, 1, MPI_INT, mostrador, tag, MPI_COMM_WORLD); // Manda peticion
  //     MPI_Recv(&peticion, 1, MPI_INT, mostrador, tag, MPI_COMM_WORLD, &status); // Recibe peticion y compara la etiqueta
  //     mostrador++; // Comprueba todos los mostradores
  //   }
  //   cout<< " * CONTROLADOR: El mostrador libre es el " << mostrador << endl;
  //   cout<< " * CONTROLADOR: Le mando el mostrador al alumno" << endl;
  //   MPI_Ssend(&peticion, 1, MPI_INT, status.MPI_SOURCE, mostrador, MPI_COMM_WORLD); //  Le manda al alumno el mostrador que esta libre
  //
  //   mostrador = 0; // Vuelve a comprobar los mostradores desde el 0
  // }
}



int main(int argc, char** argv){
  int rank, size;

  MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size != 12){
      if(rank == 0){
        cout<< "El numero de procesos debe ser 12" << endl;
        MPI_Finalize();
        return 1;
      }
    }

    if(rank == 12){ // rank = 12 -> Controlador
      Controlador();
    }else if(rank < 3){ // 0,1,2 -> Mostrador
      Mostrador();
    }else if(rank >= 3 && rank < 12){ // 3-11 -> Alumno
      Alumno();
    }
}
