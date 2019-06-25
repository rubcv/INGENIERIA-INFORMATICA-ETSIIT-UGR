#ifndef MAPA_H
#define MAPA_H

#include <GL/glut.h>

#include "motorlib/entidad.hpp"
#include "modelos_belkan.hpp"

// Macro clase para englobar Mapas de juego
// Contiene la informacion para pintar y ejecutar en el juego las Mapaes
// Las Mapaes son el jugador y los npcs.

class Mapa {
  private:
	  std::vector< std::vector< unsigned char> > mapaCompleto;
	  std::vector< std::vector<bool> > mapaVisible;

	  std::vector<Entidad *> * entidades;

	  //Atributos necesarios y tal y cual...
	  void colorCeldaMM(unsigned char celda);
	  void complementosCelda(unsigned char celda);

	  void formaEntidad(unsigned char tipoParam);
	  void OrientacionEntidadMM(Orientacion orienParam);
	  void OrientacionEntidadFP(Orientacion orienParam);

	  float angulo = 0.0;
	  float x = 5.0;
	  float z = 5.0;

	  unsigned int nCols;
	  unsigned int nFils;

  public:
	  Mapa(std::vector< std::vector< unsigned char> > mapa,std::vector<Entidad *> * entidades_ptr): mapaCompleto(mapa), entidades(entidades_ptr){
	    std::vector< bool> aux(mapa[0].size(), true);
	    for(unsigned int i = 0; i < mapa.size(); i++){
	      mapaVisible.push_back(aux);
	    }

	    nCols = mapa.size();
	    nFils = mapa[0].size();
	  }
	  ~Mapa(){}

	  void drawMM1(int x, int y);
	  void drawMM2(int x, int y);
	  void drawFirstPerson();

	  unsigned char entidadEnCelda(unsigned int x, unsigned int y);

	  unsigned char getCelda(unsigned int i, unsigned int j){ return mapaCompleto[i][j];}

	  float getMapDepth(){return sqrt(pow(mapaCompleto.size(),2) + pow(mapaCompleto[0].size(),2));}

	  int casillaOcupada(unsigned int entidad);
	  int casillaOcupadaThrow(unsigned int entidad, int &fil, int &col);

	  void girarCamaraIzquierda();
	  void girarCamaraDerecha();

	  unsigned int getNCols(){return nCols;}
	  unsigned int getNFils(){return nFils;}

	  std::vector <std::vector< unsigned char> > vision(unsigned int Entidad);
};
#endif
