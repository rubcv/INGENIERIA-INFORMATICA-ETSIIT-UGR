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
      mapaTMP.resize(mapaResultado.size() * 2);
      mapaPesos.resize(mapaResultado.size() * 2);
      fil = col = mapaTMP.size() / 2;
      for(int i = 0; i < mapaTMP.size(); i++){
        mapaTMP[i].resize(mapaResultado.size() * 2);
        for(int j = i; j < mapaTMP[0].size(); j++){
          mapaTMP[i][j] = '?';
        }
      }
      for(int i = 0; i < mapaPesos.size(); i++){
        mapaPesos[i].resize(mapaResultado.size() * 2);
        for(int j = i; j < mapaPesos[0].size(); j++){
          mapaPesos[i][j] = 0;
        }
      }

      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      estoyOrientado = false;
      planTMP = false;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      mapaTMP.resize(mapaResultado.size() * 2);
      mapaPesos.resize(mapaResultado.size() * 2);
      fil = col = mapaTMP.size() / 2;
      for(int i = 0; i < mapaPesos.size(); i++){
        mapaPesos[i].resize(mapaResultado.size() * 2);
        for(int j = i; j < mapaPesos[0].size(); j++){
          mapaPesos[i][j] = 0;
        }
      }
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      estoyOrientado = false;
      planTMP = false;
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
  void actualizarMapa(Sensores sensores, estado actual, vector< vector<unsigned char> > & mapaAUX, vector<vector<int> > & mapaPesos );
  void PintarMapa(const vector< vector <unsigned char> > & mapa);


  private:
    // Declarar Variables de Estado
    int fil, col, brujula, fil_anterior, col_anterior;
    estado inicial, fin;
    vector< vector<unsigned char> > mapaTMP;
    vector <vector <int> > mapaPesos;
    estado destino, actual;
    list<Action> plan;
    Action ultimaAccion;
    bool hayPlan, planTMP;
    bool estoyOrientado;

    bool pathFinding(const estado &origen, const estado &destino, list<Action> &plan);
    void PintaPlan(list<Action> plan);
};


#endif
