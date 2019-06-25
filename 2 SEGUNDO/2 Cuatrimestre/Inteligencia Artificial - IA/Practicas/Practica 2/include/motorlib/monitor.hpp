#ifndef MONITOR_H
#define MONITOR_H

#include "motorlib/entidad.hpp"
#include "motorlib/mapa.hpp"
#include "motorlib/util.h"
#include <glui/glui.h>

// Clase para monitorizar y controlar la ejecucion de todo el juego
// Es necesaria si se quiere independizar el dibujado de los modelo del comportamiento de los agentes.

class MonitorJuego {
  private:
    list<pair<int,int>> objetivos;
    vector<Entidad *> entidades;
    Mapa * mapa;

    bool apagarBelkan = false; // Notificar al motor de juego que sigua corriendo
    bool jugando = false;      // Notificar al motor de juego que haga los thinks
    bool empezarJuego = false; // Notificar al motor de juego que inicie un nuevo juego

    bool resultados = false;

    int pasos = 0;
    int pasosTotales = 0;
    int maxPasos = 2000;

    int retardo = 5;

    int objX = 1;
    int objY = 1;

    int nivel = 0;

  public:
    MonitorJuego(int x = 2000) {maxPasos = x;}
    ~MonitorJuego(){}

    void nueva_entidad(Entidad * entidad) {entidades.push_back(entidad);}
    unsigned int numero_entidades() {return entidades.size();}

    void clear() {entidades.clear();}
    Entidad * get_entidad(unsigned entidad) {return entidades[entidad];}
    vector<Entidad *> * get_entidades() {return &entidades;}
    void cambiarPosicion(unsigned char entidad, unsigned char x, unsigned char y) {entidades[entidad]-> setPosicion(x,y);}
    void cambiarOrientacion(unsigned char entidad, unsigned char orientacion);

    Mapa * getMapa() {return mapa;}
    void setMapa(char * file);

    void startGame(int valor = 1) {empezarJuego = true; pasosTotales = 0; pasos = 0; nivel = valor;} //Indica que hay un nuevo juego que inicializar
    bool inicializarJuego(); //Mira si tiene que inicializar un juego
    int juegoInicializado() {jugando = true; return mapa->getNFils();}

    bool continuarBelkan() {return !apagarBelkan;}
    void cerrarBelkan() {apagarBelkan = true;}

    bool mostrarResultados() {return resultados;}
    void setMostrarResultados(bool valor) {resultados = valor;}

    bool jugar() {return jugando;}

    void girarJugadorIzquierda() {mapa->girarCamaraIzquierda();}
    void girarJugadorDerecha() {mapa->girarCamaraDerecha();}

    void setPasos(int Npasos) {pasos = Npasos;}
    void decPasos(GLUI_EditText * editPosX = NULL, GLUI_EditText * editPosY = NULL);
    int getPasos() {return pasos;}

    bool finJuego() {return ((maxPasos - pasosTotales) <= 0);}

    void setRetardo(int tRetardo) {retardo = tRetardo;}
    int getRetardo() {return retardo;}

    void setObjX(int valor);
    int getObjX() {return objX;}

    void setObjY(int valor);
    int getObjY() {return objY;}

    void setListObj(list<pair<int,int>> & obj) {objetivos = obj;}
    list<pair<int,int>> getListObj() {return objetivos;}

    void inicializar(int mix = -1, int miy = -1);
};
#endif
