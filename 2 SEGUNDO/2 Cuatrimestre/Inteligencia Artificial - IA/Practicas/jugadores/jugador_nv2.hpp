#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>
#include <set>
#include <utility>


struct estado {
  int fila;
  int columna;
  int orientacion;
};


class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}
    void AnularMatriz(vector<vector<unsigned char> > &m);

	estado avanzar(estado pos);
	estado girarIzq(estado pos);
	estado girarDch(estado pos);
	bool puedoIrACasilla(const estado & pos);
  bool esDestino(estado uno, estado destino);
  
  


  private:
    // Declarar Variables de Estado
    int fil, col, brujula;
    estado inicial, fin;
    vector< vector<unsigned char> > mapaTMP(mapaResultado.size()*2, vector<unsigned char> (mapaResultado.size()*2));
    estado destino, actual;
    list<Action> plan;
    Action ultimaAccion;
    bool hayPlan;

    bool pathFinding(const estado &origen, const estado &destino, list<Action> &plan);
    void PintaPlan(list<Action> plan);
};


#endif
