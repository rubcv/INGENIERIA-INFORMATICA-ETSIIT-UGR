#ifndef COMPORTAMIENTOALDEANO_H
#define COMPORTAMIENTOALDEANO_H

#include <chrono>
#include <time.h>
#include <thread>

#include "comportamientos/comportamiento.hpp"

class ComportamientoAldeano : public Comportamiento{

  public:
    ComportamientoAldeano(unsigned int size = 0) : Comportamiento(size){
      paso=0;
    }
    ComportamientoAldeano(const ComportamientoAldeano & comport) : Comportamiento(comport){}
    ~ComportamientoAldeano(){}

    Action think(Sensores sensores);

    int interact(Action accion, int valor);


    ComportamientoAldeano * clone(){return new ComportamientoAldeano(*this);}

  private:
    int paso;

};



#endif
