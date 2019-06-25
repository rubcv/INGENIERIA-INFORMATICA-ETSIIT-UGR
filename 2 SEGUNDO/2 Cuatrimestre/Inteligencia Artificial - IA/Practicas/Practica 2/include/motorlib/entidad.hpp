#ifndef ENTIDAD_H
#define ENTIDAD_H

#include "obj3dlib.hpp"
#include "comportamientolib.hpp"
#include "motorlib/util.h"

// Macro clase para englobar entidades de juego
// Contiene la informacion para pintar y ejecutar en el juego las entidades
// Las entidades son el jugador y los npcs

enum Orientacion {norte, este, sur, oeste};
enum Tipo {jugador, npc};
enum SubTipo {jugador_, aldeano, __NONE__};

class Entidad {
    private:
	  Tipo tipo;
	  SubTipo subtipo;
	  Orientacion orient;
	  unsigned int x, y;
	  unsigned int destX, destY;

	  Objeto3D * modelo;
	  Comportamiento* comportamiento;

	  //Colision
	  bool colision = false;
	  int colisiones = 0;

	  //reset
	  bool reset = false;

	  bool mensaje = false;

	  //vida
	  int vida = 500;
    int muertes_innecesarias = 0;

	  bool hitbox = true;
	  int desactivado = 0;

	  int last_action = 3;
	  int misiones = 0;
	  bool done = false;
	  double tiempo = 0;

	  vector <vector< unsigned char> > visionAux;

	public:
	  Entidad(Tipo paramTipo, SubTipo paramSubTipo, Orientacion paramOrient, unsigned int paramX, unsigned int paramY, Objeto3D * mod, Comportamiento * comp, int objX = 1, int objY = 1, int v = 500)
	      : tipo(paramTipo), subtipo(paramSubTipo), orient(paramOrient), x(paramX), y(paramY), modelo(mod), comportamiento(comp), destX(objX), destY(objY), vida(v) {}

	  ~Entidad() {delete modelo; delete comportamiento;}

	  void draw(int modo) {if(hitbox) {modelo -> draw(modo);}}
	  Action think(int acc, vector <vector< unsigned char> > vision);

	  //Programar funciones para la interacción con el entorno
	  void setPosicion(unsigned int paramX, unsigned int paramY) {x = paramX; y = paramY;}
	  void setObjetivo(unsigned int paramX, unsigned int paramY) {destX = paramX; destY = paramY;}
	  void setOrientacion(Orientacion paramOrient) {orient = paramOrient;}

	  Tipo getTipo() {return tipo;}
	  SubTipo getSubTipo() {return subtipo;}

	  unsigned char getSubTipoChar();

	  Orientacion getOrientacion() {return orient;}
	  unsigned int getX() {return x;}
	  unsigned int getY() {return y;}
	  bool getHitbox() {return hitbox;}

	  bool interact(Action accion, int valor);

	  void resetEntidad();
	  void seAostio() {colision = true; colisiones++;}
	  void notify() {mensaje = true;}

	  void getLastAction(int accion) {last_action = accion;}

	  vector< vector< unsigned char> > getMapaResultado() {return comportamiento -> getMapaResultado();}
	  vector< vector< unsigned char> > getMapaEntidades() {return comportamiento -> getMapaEntidades();}
    vector< vector< unsigned char> > getMapaPlan() {return comportamiento -> getMapaPlan();}

	  bool vivo() {return vida > 0;}

	  string toString();

	  void setVision(vector <vector< unsigned char> > vision) {visionAux = vision;}

	  void perderPV(int valor) {vida -= valor;}
	  void ganarPV(int valor) {vida += valor;}

	  int getColisiones() {return colisiones;}
    int getMuertesI() {return muertes_innecesarias;}

	  void setTiempo(double valor) {tiempo=valor;}
	  double getTiempo() {return tiempo;}
	  void addTiempo(double valor) {tiempo+=valor;}

	  int getMisiones() {return misiones;}

	  bool isActived() {return desactivado!=-1;}
	  void Active() {desactivado=0;}

	  void setMensajeOff() {mensaje = false;}
	  void setColisionOff() {colision = false;}
	  void setResetOff() {reset = false;}
	  void setHitbox(bool valor) {hitbox=valor;}

          bool fin() {return done;}
	  void resetFin() {done = false;}
};
#endif
